#pragma once
#include "../Title/title.h"

const int PLAY_IMAGE_NUMBER = 10;	//�摜����

#define PLAY_BACK_PATH		"Data/PlayImage/haikei.png"		//�v���C�V�[���w�i�p�X

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