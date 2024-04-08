#pragma once
#include "../Title/title.h"
#include "../../Player/player.h"
#include "../../Enemy/enemy.h"
#include "../Shop/shop.h"

const int PLAY_IMAGE_NUMBER = 3;	//画像枚数

#define PLAY_BACK_PATH		"Data/PlayImage/haikei.png"		//プレイシーン背景パス
#define ITEM_SELECT_PATH	"Data/PlayImage/Item.jpg"		//看板パス

//背景座標
const int BACK_X = 640;		
const int BACK_Y = 360;
//スクロール速度
const int BACK_SPEED = 4;

class Play : public Title
{
private:

	Player m_player;	//プレイヤークラス
	Enemy m_enemy;		//エネミークラス
	int m_scrollFlame = 0;		//スクロールフレーム

	//看板
	int m_SignBoard_x[ENEMY_MAX_NUM] = { 0 };		//X座標
	int m_SignBoard_y[ENEMY_MAX_NUM] = { 0 };		//Y座標

public:

	Play();
	~Play();

	//プレイ初期化  
	void InitPlay();

	//プレイ通常処理
	void StepPlay(int hp);

	//プレイ描画処理
	void DrawPlay(int hp);

	//プレイ後処理
	void FinPlay();

	

};