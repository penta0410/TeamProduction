#pragma once
#include "../../Screen/Screen.h"
#include "../Title/title.h"

const int PLAY_IMAGE_NUMBER = 10;	//�摜����

class Play : public Title
{
private:


public:

	Play();
	~Play();

	//�v���C������  
	void InitPlay();

	//�v���C�ʏ폈��
	void StepPlay();

	//�v���C�`�揈��
	void DrawPlay();

	//�v���C�㏈��
	void FinPlay();

};