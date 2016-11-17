#ifdef __cplusplus
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif

#ifndef _AI
#define _AI

// ai.cpp
EXPORT void initAI();			// AIの初期化(最初に一度だけ実行される)
EXPORT int  processAI();		// AIの本体(ステップ毎に繰り返し実行される)

#endif