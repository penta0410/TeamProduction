#pragma once
#include "../Title/title.h"

const int SHOP_IMAGE_NUMBER = 10;	//ショップ画像枚数

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
