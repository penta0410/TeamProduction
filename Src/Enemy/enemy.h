#pragma once

//�G���
#define ENEMY_MAX_NUM			//�G�̐�


class Enemy
{
public:

	int handle = 0;				//�摜�n���h��
	int Experience = 0;			//�G�̌o���l
	int point = 0;				//�G�̓��_
	float Posx = 0.0f;			//X���W
	float Posy = 0.0f;			//Y���W
		
	Enemy();					//�R���X�g���N�^
	~Enemy();					//�f�X�g���N�^

	//�G������
	void Init();

	//�G�̕`��
	//void Draw();

	////�G�S�Ń`�F�b�N
	//bool IsAllKill();

	//�R�����g�A�E�g���Ă�����͎̂g�����킩��Ȃ��̂ł��Ă܂�//
};

