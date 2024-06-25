#include "member.h"
#include"visitor.h"

void MaleMember::accept(AbstractAction *action)
{
    action->maleDoing(this);
}

void FemaleMember::accept(AbstractAction *action)
{
    action->femaleDoing(this);
}
