#ifdef __cplusplus
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif

#ifndef _AI
#define _AI

// ai.cpp
EXPORT void initAI();			// AI�̏�����(�ŏ��Ɉ�x�������s�����)
EXPORT int  processAI();		// AI�̖{��(�X�e�b�v���ɌJ��Ԃ����s�����)

#endif