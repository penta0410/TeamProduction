#pragma once
#include "../Title/title.h"

const int CLEAR_IMAGE_NUMBER = 10;		//画像枚数

class Clear : public Title
{
private:

public:

	//クリア初期化
	void InitClear();

	//クリア通常処理
	void StepClear();

	//クリア描画処理
	void DrawClear();

	//クリア後処理
	void FinClear();

};