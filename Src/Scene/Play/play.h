#pragma once
#include "../Title/title.h"
#include "../../Player/player.h"
#include "../Shop/shop.h"

const int PLAY_IMAGE_NUMBER = 3;	//�摜����

#define PLAY_BACK_PATH		"Data/PlayImage/haikei.png"		//�v���C�V�[���w�i�p�X
//�w�i���W
const int BACK_X = 640;		
const int BACK_Y = 360;
//�X�N���[�����x
const int BACK_SPEED = 4;

class Play : public Title
{
private:

	Player m_player;	//�v���C���[�N���X
	Shop m_shop;
	int m_scrollFlame = 0;		//�X�N���[���t���[��
	

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