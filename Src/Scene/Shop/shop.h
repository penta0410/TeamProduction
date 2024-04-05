#pragma once
#include "../Title/title.h"

const int SHOP_IMAGE_NUMBER = 20;	//ショップ画像枚数

#define SHOP_BACK_IMAGE_PATH	"Data/ShopImage/ShopBackImage.png"	//ショップ背景画像パス
#define SHOP_SCROLL_IMAGE_PATH		"Data/ShopImage/ScrollImage.png"	//ショップスクロール画像パス
#define SHOP_PATH				"Data/ShopImage/Shop.png"	//ショップ

class Shop : public Title
{

private:


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
