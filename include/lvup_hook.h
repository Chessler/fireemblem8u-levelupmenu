#ifndef GUARD_LVUP_HOOK_H
#define GUARD_LVUP_HOOK_H

#include "bmbattle.h"

/*
 * Level-Up Hook Interface
 *
 * This layer intercepts the stat-delta buffer generated during
 * CheckBattleUnitLevelUp() before it is committed to the Unit struct.
 *
 * All modifications must operate on the BattleUnit delta fields
 * (changeHP, changePow, changeSkl, etc).
 *
 * The display layer and final commit layer both consume these deltas,
 * so altering them here affects both animation and permanent stats.
 */

/**
 * Called after growth rolls and cap checks.
 * Intended to mutate bu->change* fields.
 */
void LvupHook_OnAfterGrowth(struct BattleUnit* bu);

/**
 * Optional: compute and return total rolled stat gains.
 * Useful for allocation systems.
 */
int LvupHook_GetTotalDelta(struct BattleUnit* bu);

/**
 * Optional: zero all deltas.
 * Useful for point allocation systems.
 */
void LvupHook_ClearDeltas(struct BattleUnit* bu);

void LvupHook_ForceHP(struct BattleUnit* bu);

#endif // GUARD_LVUP_HOOK_H