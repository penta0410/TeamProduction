#pragma once
#include "../../Scene/Scene.h"
#include "../../Scene/Title/title.h"

const int STAGE_SELECT_IMAGE_NUMBER = 10; //ステージセレクト画像枚数

#define STAGE_SELECT_BACK_IMAGE_PATH	"Data/StageSelectImage/StageSelectBackImage.png"	//ステージセレクト背景パス

class StageSelect : public Title
{
private:

	

public:

	//ステージセレクト初期化
	void InitStageSelect();

	//ステージセレクト通常処理
	void StepStageSelect();

	//ステージセレクト描画処理
	void DrawStageSelect();

	//ステージセレクト後処理
	void FinStageSelect();
};
