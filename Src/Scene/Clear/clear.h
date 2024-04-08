#pragma once
#include "../Title/title.h"

const int CLEAR_IMAGE_NUMBER = 10;		//画像枚数

//ステージクリア画面画像パス
#define STAGRE_CLEAR_BACK_PATH		"Data/GameClearImage/StageClear.png"

class Clear : public Title
{
private:


public:

	//クリア初期化
	void InitClear();

	//クリア通常処理
	void StepClear();

	//クリアロード
	void LoadClear();

	//クリア描画処理
	void DrawClear();

	//クリア後処理
	void FinClear();

};