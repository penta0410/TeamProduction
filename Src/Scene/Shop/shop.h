#pragma once
#include "../Title/title.h"

const int SHOP_IMAGE_NUMBER = 10;	//�V���b�v�摜����

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
