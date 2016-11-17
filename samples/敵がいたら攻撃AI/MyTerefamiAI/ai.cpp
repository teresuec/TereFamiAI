//
// AI本体 (ai.cpp)
//

#include <Windows.h>
#include "ai.h"
#include "common.h"

#define CHARA_NAME			"敵がいたら攻撃"	// ← ■① AIの名前: 日本語なども使用可能
#define CHARA_IMGFILENAME	"ika2.png"			// ← ■② AIの画像ファイル名: 縦横比1:1のPNG(サイズは自由)。提出時には他のAIと被らないようなファイル名(自分の名前など)にしてください

extern int playerID, playerCount, fieldWidth, fieldHeight;

// ■■■ AI設計 ここから ■■■

void initAI() {
	/* ゲーム開始時に一度だけ実行されます(任意) */
	return;
}

int processAI() {
	/* ゲーム中、ステップ毎に繰り返し実行されます */
	if (getEnemyCount(getX() + getDirection() * 2 - 1, getY()) > 0){
		return 7;
	}
	return rand() % 9;
}

// ■■■ AI設計 ここまで ■■■

// --- 以下、編集禁止 ---

// キャラクタの情報をゲーム本体に渡す
EXPORT void _getName(char *lpName) {
	strcpy_s(lpName, 256, CHARA_NAME);
	return;
}

EXPORT void _getImgFilename(char *lpImgFilename) {
	strcpy_s(lpImgFilename, 256, CHARA_IMGFILENAME);
	return;
}