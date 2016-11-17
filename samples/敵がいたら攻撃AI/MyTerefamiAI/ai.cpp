//
// AI�{�� (ai.cpp)
//

#include <Windows.h>
#include "ai.h"
#include "common.h"

#define CHARA_NAME			"�G��������U��"	// �� ���@ AI�̖��O: ���{��Ȃǂ��g�p�\
#define CHARA_IMGFILENAME	"ika2.png"			// �� ���A AI�̉摜�t�@�C����: �c����1:1��PNG(�T�C�Y�͎��R)�B��o���ɂ͑���AI�Ɣ��Ȃ��悤�ȃt�@�C����(�����̖��O�Ȃ�)�ɂ��Ă�������

extern int playerID, playerCount, fieldWidth, fieldHeight;

// ������ AI�݌v �������� ������

void initAI() {
	/* �Q�[���J�n���Ɉ�x�������s����܂�(�C��) */
	return;
}

int processAI() {
	/* �Q�[�����A�X�e�b�v���ɌJ��Ԃ����s����܂� */
	if (getEnemyCount(getX() + getDirection() * 2 - 1, getY()) > 0){
		return 7;
	}
	return rand() % 9;
}

// ������ AI�݌v �����܂� ������

// --- �ȉ��A�ҏW�֎~ ---

// �L�����N�^�̏����Q�[���{�̂ɓn��
EXPORT void _getName(char *lpName) {
	strcpy_s(lpName, 256, CHARA_NAME);
	return;
}

EXPORT void _getImgFilename(char *lpImgFilename) {
	strcpy_s(lpImgFilename, 256, CHARA_IMGFILENAME);
	return;
}