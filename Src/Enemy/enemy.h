#pragma once

//�G���
#define ENEMY_PATH				//�G�̃p�X
#define ENEMY_MAX_NUM			//�G�̐�
#define ENEMY_HP 		(3)		//�G��HP
#define ENEMY_ATK		(1)		//�G�̍U��


class Enemy
{
public:

	int handle = 0;		//�摜�n���h��
	int HP = 0;			//�G�̃��C�t
	int Experience = 0;	//�G�̌o���l
	int point = 0;				//�G�̓��_
	float Posx = 0.0f;			//X���W
	float Posy = 0.0f;			//Y���W
		
	Enemy();
	~Enemy();

	//�G������
	void Init();

	//�G�̕`��
	void Draw();

	//�G�S�Ń`�F�b�N
	bool IsAllKill();

	

};

