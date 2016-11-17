#ifdef __cplusplus
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif

#ifndef _COMMON
#define _COMMON

// common.cpp
EXPORT int getField(int x, int y);
EXPORT int getEnemyCount(int x, int y);
EXPORT int getEnemyDirection(int x, int y);
EXPORT int getEnemyDamage(int x, int y);
EXPORT int getEnemyJumpRemain(int x, int y);
EXPORT int getEnemyAttackCombo(int x, int y);
EXPORT int getEnemyID(int x, int y);
EXPORT int getPlayerX(int id);
EXPORT int getPlayerY(int id);
EXPORT int getPlayerDirection(int id);
EXPORT int getPlayerDamage(int id);
EXPORT int getPlayerJumpRemain(int id);
EXPORT int getPlayerAttackCombo(int id);
EXPORT int getX();
EXPORT int getY();
EXPORT int getDirection();
EXPORT int getDamage();
EXPORT int getJumpRemain();
EXPORT int getAttackCombo();

#endif