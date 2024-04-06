#pragma once
#include "../Title/title.h"
#include "../../Player/player.h"
#include "../Shop/shop.h"

const int PLAY_IMAGE_NUMBER = 3;	//画像枚数

#define PLAY_BACK_PATH		"Data/PlayImage/haikei.png"		//プレイシーン背景パス
//背景座標
const int BACK_X = 640;		
const int BACK_Y = 360;
//スクロール速度
const int BACK_SPEED = 4;

class Play : public Title
{
private:

	Player m_player;	//プレイヤークラス
	Shop m_shop;
	int m_scrollFlame = 0;		//スクロールフレーム
	

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