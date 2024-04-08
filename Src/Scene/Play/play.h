#pragma once
#include "../Title/title.h"
#include "../../Player/player.h"
#include "../../Enemy/enemy.h"
#include "../Shop/shop.h"

const int PLAY_IMAGE_NUMBER = 3;	//�摜����

#define PLAY_BACK_PATH		"Data/PlayImage/haikei.png"		//�v���C�V�[���w�i�p�X
#define ITEM_SELECT_PATH	"Data/PlayImage/Item.jpg"		//�Ŕp�X

//�w�i���W
const int BACK_X = 640;		
const int BACK_Y = 360;
//�X�N���[�����x
const int BACK_SPEED = 4;

class Play : public Title
{
private:

	Player m_player;	//�v���C���[�N���X
	Enemy m_enemy;		//�G�l�~�[�N���X
	int m_scrollFlame = 0;		//�X�N���[���t���[��

	//�Ŕ�
	int m_SignBoard_x[ENEMY_MAX_NUM] = { 0 };		//X���W
	int m_SignBoard_y[ENEMY_MAX_NUM] = { 0 };		//Y���W

public:

	Play();
	~Play();

	//�v���C������  
	void InitPlay();

	//�v���C�ʏ폈��
	void StepPlay(int hp);

	//�v���C�`�揈��
	void DrawPlay(int hp);

	//�v���C�㏈��
	void FinPlay();

	

};