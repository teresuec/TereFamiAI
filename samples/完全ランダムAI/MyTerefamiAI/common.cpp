//
// キャラクタ共通の設計(common.cpp)
//
// ※このファイルの内容は書き換えないで下さい

#include <Windows.h>
#include <time.h>
#include "ai.h"
#include "common.h"

#ifdef __cplusplus
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD fdwReason,
	LPVOID lpvReserved
	){
	return TRUE;
}

typedef struct tPlayer {
	int x;
	int y;
	int direction;
	int damage;
	int jumpRemain;
	int attackCombo;
} TPlayer;

static const int *field;
int playerID, playerCount, fieldWidth, fieldHeight;
static const TPlayer *player;

EXPORT void _initAI(const int *_field, int _playerID, int _playerCount, int _fieldWidth, int _fieldHeight) {
	field = _field;
	playerCount = _playerCount;
	fieldWidth = _fieldWidth;
	fieldHeight = _fieldHeight;
	playerID = _playerID;
	srand((int)time(NULL) + playerID);
	initAI();
	return;
}

EXPORT int _processAI(TPlayer *_player) {
	player = _player;
	return processAI();
}


// フィールドの状態を取得
EXPORT int getField(int x, int y) {
	if ((x < 0) || (x >= fieldWidth) || (y < 0) || (y >= fieldHeight)){
		return -1;
	}
	return field[x + y*fieldWidth];
}

EXPORT int getEnemyCount(int x, int y) {
	if ((x < 0) || (x >= fieldWidth) || (y < 0) || (y >= fieldHeight)){
		return -1;
	}
	int n = 0;
	for (int i = 0; i < playerCount; i++){
		if (i == playerID) continue;
		if ((player[i].x == x) && (player[i].y == y)){
			n++;
		}
	}
	return n;
}

EXPORT int getEnemyDirection(int x, int y) {
	if ((x < 0) || (x >= fieldWidth) || (y < 0) || (y >= fieldHeight)){
		return -1;
	}
	int direction = -1;
	for (int i = 0; i < playerCount; i++){
		if (i == playerID) continue;
		if ((player[i].x == x) && (player[i].y == y)){
			if (direction == -1){
				direction = player[i].direction;
			}
			else{
				return -2;
			}
		}
	}
	return direction;
}

EXPORT int getEnemyDamage(int x, int y) {
	if ((x < 0) || (x >= fieldWidth) || (y < 0) || (y >= fieldHeight)){
		return -1;
	}
	int damage = -1;
	for (int i = 0; i < playerCount; i++){
		if (i == playerID) continue;
		if ((player[i].x == x) && (player[i].y == y)){
			if (damage == -1){
				damage = player[i].direction;
			}
			else{
				return -2;
			}
		}
	}
	return damage;
}

EXPORT int getEnemyJumpRemain(int x, int y) {
	if ((x < 0) || (x >= fieldWidth) || (y < 0) || (y >= fieldHeight)){
		return -1;
	}
	int jumpRemain = -1;
	for (int i = 0; i < playerCount; i++){
		if (i == playerID) continue;
		if ((player[i].x == x) && (player[i].y == y)){
			if (jumpRemain == -1){
				jumpRemain = player[i].jumpRemain;
			}
			else{
				return -2;
			}
		}
	}
	return jumpRemain;
}

EXPORT int getEnemyAttackCombo(int x, int y) {
	if ((x < 0) || (x >= fieldWidth) || (y < 0) || (y >= fieldHeight)){
		return -1;
	}
	int attackCombo = -1;
	for (int i = 0; i < playerCount; i++){
		if (i == playerID) continue;
		if ((player[i].x == x) && (player[i].y == y)){
			if (attackCombo == -1){
				attackCombo = player[i].attackCombo;
			}
			else{
				return -2;
			}
		}
	}
	return attackCombo;
}

EXPORT int getEnemyID(int x, int y) {
	if ((x < 0) || (x >= fieldWidth) || (y < 0) || (y >= fieldHeight)){
		return -1;
	}
	int id = -1;
	for (int i = 0; i < playerCount; i++){
		if (i == playerID) continue;
		if ((player[i].x == x) && (player[i].y == y)){
			if (id == -1){
				id = i;
			}
			else{
				return -2;
			}
		}
	}
	return id;
}

// 各プレイヤーの情報を取得
EXPORT int getPlayerX(int id) {
	if ((id < 0) || (id >= playerCount)){
		return -1;
	}
	return player[id].x;
}

EXPORT int getPlayerY(int id) {
	if ((id < 0) || (id >= playerCount)){
		return -1;
	}
	return player[id].y;
}

EXPORT int getPlayerDirection(int id) {
	if ((id < 0) || (id >= playerCount)){
		return -1;
	}
	return player[id].direction;
}

EXPORT int getPlayerDamage(int id) {
	if ((id < 0) || (id >= playerCount)){
		return -1;
	}
	return player[id].damage;
}

EXPORT int getPlayerJumpRemain(int id) {
	if ((id < 0) || (id >= playerCount)){
		return -1;
	}
	return player[id].jumpRemain;
}

EXPORT int getPlayerAttackCombo(int id) {
	if ((id < 0) || (id >= playerCount)){
		return -1;
	}
	return player[id].attackCombo;
}

// 自分の情報を取得
EXPORT int getX() {
	return player[playerID].x;
}

EXPORT int getY() {
	return player[playerID].y;
}

EXPORT int getDirection() {
	return player[playerID].direction;
}

EXPORT int getDamage() {
	return player[playerID].damage;
}

EXPORT int getJumpRemain() {
	return player[playerID].jumpRemain;
}

EXPORT int getAttackCombo() {
	return player[playerID].attackCombo;
}