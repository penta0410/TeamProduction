#pragma once
#include "../Title/title.h"

const int PLAY_IMAGE_NUMBER = 10;	//画像枚数

#define PLAY_BACK_PATH		"Data/PlayImage/haikei.png"		//プレイシーン背景パス

class Play : public Title
{
private:

	

public:

	Play();
	~Play();

	//プレイ初期化  
	void InitPlay();

	//プレイ通常処理
	void StepPlay();

	//プレイ描画処理
	void DrawPlay();

	//プレイ後処理
	void FinPlay();

};