#include "global.h"
#include "bmbattle.h"

void LvupHook_ForceHP(struct BattleUnit* bu)
{
    // Only affect player units
    if (bu->unit.index < 0x40)  // or use faction check if you prefer
    {
        //bu->changeHP = 2;
    }
}