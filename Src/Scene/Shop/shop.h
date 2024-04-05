#pragma once
#include "../Title/title.h"

const int SHOP_IMAGE_NUMBER = 20;	//�V���b�v�摜����

#define SHOP_BACK_IMAGE_PATH	"Data/ShopImage/ShopBackImage.png"	//�V���b�v�w�i�摜�p�X
#define SHOP_SCROLL_IMAGE_PATH		"Data/ShopImage/ScrollImage.png"	//�V���b�v�X�N���[���摜�p�X
#define SHOP_PATH				"Data/ShopImage/Shop.png"	//�V���b�v

class Shop : public Title
{

private:


public:

	//�V���b�v������
	void InitShop();

	//�V���b�v�ʏ폈��
	void StepShop();

	//�V���b�v�`�揈��
	void DrawShop();

	//�V���b�v�㏈��
	void FinShop();

};
