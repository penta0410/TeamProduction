#pragma once
#include "../Title/title.h"
#include "../../Player/player.h"

const int SHOP_IMAGE_NUMBER = 20;	//ショップ画像枚数

#define SHOP_BACK_IMAGE_PATH	"Data/ShopImage/ShopBackImage.png"	//ショップ背景画像パス
#define SHOP_SCROLL_IMAGE_PATH		"Data/ShopImage/ScrollImage.png"	//ショップスクロール画像パス
#define SHOP_PATH				"Data/ShopImage/Shop.png"	//ショップ

class Shop : public Title
{

private:

	Player m_player;	//プレイヤークラス宣言

	int m_PlayerHp = 0;
	int m_PlayerAttackPower = 0;
	int m_PlayerAttackInterval = 0;
	int m_ScoreUp = 0;
	int m_MoveSpeed = 0;
	int m_MoneyAmmountUp = 0;

public:

	//ショップ初期化
	void InitShop();

	//ショップ通常処理
	void StepShop();

	//ショップ描画処理
	void DrawShop();

	//ショップ後処理
	void FinShop();

};
