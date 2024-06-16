/*
单例模式
*/

#include<iostream>
#include <mutex>
#include<atomic>
#include<queue>
#include<thread>
using namespace  std;

# if 0
//饿汉模式->定义类时创建单例对象，多线程访问类对象时没有线程安全问题
//定义一个单例模式的任务队列
class TaskQueue
{
public:
 //单例模式，不要让外部对象调用默认构造和拷贝函数
  //通过两种方法移除，一种时=delete,另一种时放在private;

    //TaskQueue() = delete;
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue &operator =(const TaskQueue &t) =delete;

    static TaskQueue *getInstance()
    {
        return m_taskQ;
    }
    void print()
    {
        cout<<"This is a single instance of TaskQueue"<<endl;
    }
private:
    TaskQueue() = default;
    //TaskQueue(const TaskQueue &t)=default;
    //TaskQueue &operator =(const TaskQueue &t) =default;
    
    //只能通过过类名访问静态属性或者方法
    static TaskQueue *m_taskQ;
};

TaskQueue* TaskQueue::m_taskQ = new TaskQueue;
#endif

# if 0
//懒汉模式->定义类时不创建单例对象，需要时才创建
//多线程访问类对象时，存在线程安全问题，需要加锁解决
//多线程访问，使用锁解决安全问题，回造成访问效率降低，因此选择饿汉模式更适合
class TaskQueue
{
public:
    //TaskQueue() = delete;
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue &operator =(const TaskQueue &t) =delete;

    static TaskQueue *getInstance()
    {
        //使用原子变量，保证计算机内部执行顺序
        //原子变量保证线程安全，保证创建对象时，只有一个线程可以执行到这步，其他线程只能等待
        TaskQueue *tmp = m_taskQ.load();  //取出
        if(tmp == nullptr)
        {
            m_mutex.lock();
            tmp = m_taskQ.load();  //取出
            if(tmp == nullptr)
            {   
                tmp = new TaskQueue;
                m_taskQ.store(tmp);  //保存
            }
            m_mutex.unlock();
        }
        return tmp;
        /*
        //双重检查锁定，保证线程安全
        //创建好对象后，后续访问就变为并行，提高运行效率
        if(m_taskQ == nullptr)
        {
            //为保持线程同步，使用锁把程序变成串行，运行效率较低，为解决效率低下问题，使用双重检查锁定
            m_mutex.lock();
            if(m_taskQ == nullptr)
            {   
                m_taskQ = new TaskQueue;
            }
            m_mutex.unlock();
        }
        return m_taskQ;
         */
    }
    void print()
    {
        cout<<"This is a single instance of TaskQueue"<<endl;
    }
private:
    TaskQueue() = default;
    //TaskQueue(const TaskQueue &t)=default;
    //TaskQueue &operator =(const TaskQueue &t) =default;
    
    //只能通过过类名访问静态属性或者方法
   // static TaskQueue *m_taskQ;
    static mutex m_mutex;
    static atomic<TaskQueue*> m_taskQ; //使用原子变量保证计算机内部执行顺序
};

//TaskQueue* TaskQueue::m_taskQ = nullptr;
mutex TaskQueue::m_mutex;  //静态函数就算不创建对象，也要在外部进行声明
atomic<TaskQueue*> TaskQueue::m_taskQ; //原子变量初始化为nullptr
#endif


# if 0
//上面的原子操作较为复杂，使用更简化的方法进行更改
//使用静态的局部对象解决线程安全问题
//静态局部对象只在第一次访问时创建，后续访问直接返回静态局部对象，保证线程安全
//静态局部对象在线程间共享，提高运行效率
//之所以这种方法时安全的，时因为C++11中规定：如果指令逻辑进入一个未被初始化的声明变量，
//所有并发执行应当等待变量完成初始化。
class TaskQueue
{
public:
    //TaskQueue() = delete;
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue &operator =(const TaskQueue &t) =delete;

    static TaskQueue *getInstance()
    {
        //该方法仅在C++11及以上版本有效
        static TaskQueue task;  //局部静态对象
        return &task;
    }
    void print()
    {
        cout<<"This is a single instance of TaskQueue"<<endl;
    }
private:
    TaskQueue() = default;
    //TaskQueue(const TaskQueue &t)=default;
    //TaskQueue &operator =(const TaskQueue &t) =default;
};

#endif

# if 1
//使用懒汉模式写一个日志队列
class TaskQueue
{
public:
    //TaskQueue() = delete;
    TaskQueue(const TaskQueue &t) = delete;
    TaskQueue &operator =(const TaskQueue &t) =delete;

    static TaskQueue *getInstance()
    {
        //该方法仅在C++11及以上版本有效
        static TaskQueue task;  //局部静态对象
        return &task;
    }
    //判断队列是否为空
    bool isEmpty()
    {
        //锁管理
        lock_guard<mutex> locker(m_mutex);
        return m_data.empty();
    }
    //添加任务
    void addTask(int task)
    {
        lock_guard<mutex> locker(m_mutex);
        m_data.push(task);
    }
    //删除任务
    bool popTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if(m_data.empty())
        {
            return false;
        }
        m_data.pop();
        return true;
    }
    //取出任务
    int takeTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if(m_data.empty())
        {
            return -1;
        }
        return m_data.front();
    }
    void print()
    {
        cout<<"This is a single instance of TaskQueue"<<endl;
    }
private:
    TaskQueue() = default;
    //TaskQueue(const TaskQueue &t)=default;
    //TaskQueue &operator =(const TaskQueue &t) =default;

    //定义任务队列
    queue<int> m_data;  //需要用互斥锁保护内部数据
    mutex m_mutex;
};

#endif

int main()
{
    TaskQueue *taskQ = TaskQueue::getInstance();

    //生产者
    thread t1([=](){
        for(int i = 0 ;i < 100; i++)
         {
            taskQ->addTask(i+1000);
            cout<<"++ push data: "<<i+1000<<
            ", threaID: "<<this_thread::get_id()<<endl;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
    });
    
    //消费者
     thread t2([=](){
        this_thread::sleep_for(chrono::milliseconds(20));
        while (!taskQ->isEmpty())
        {
            int i = taskQ->takeTask();
            cout<<"++ take data: "
            <<i<<", threaID: "<<this_thread::get_id()<<endl;
            taskQ->popTask();
            this_thread::sleep_for(chrono::milliseconds(30));
        }
    });
    
    //堵塞主线程
    t1.join();
    t2.join();

    return 0;
}

