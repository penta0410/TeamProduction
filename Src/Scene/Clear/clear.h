#pragma once
#include "../Title/title.h"

const int CLEAR_IMAGE_NUMBER = 10;		//�摜����

//�X�e�[�W�N���A��ʉ摜�p�X
#define STAGRE_CLEAR_BACK_PATH		"Data/GameClearImage/StageClear.png"

class Clear : public Title
{
private:


public:

	//�N���A������
	void InitClear();

	//�N���A�ʏ폈��
	void StepClear();

	//�N���A���[�h
	void LoadClear();

	//�N���A�`�揈��
	void DrawClear();

	//�N���A�㏈��
	void FinClear();

};