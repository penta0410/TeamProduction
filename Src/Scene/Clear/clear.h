#pragma once
#include "../Title/title.h"

const int CLEAR_IMAGE_NUMBER = 10;		//�摜����

class Clear : public Title
{
private:

public:

	//�N���A������
	void InitClear();

	//�N���A�ʏ폈��
	void StepClear();

	//�N���A�`�揈��
	void DrawClear();

	//�N���A�㏈��
	void FinClear();

};