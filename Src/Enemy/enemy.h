#pragma once

//�G���
#define	ENEMY_PATH						//�G�̒e�p�X
#define ENEMY_MAX_NUM		 			//�G�̐�
#define ENEMY_ATK			  (1)		//�G�U����
#define ENEMY_POINT			  (3)		//�G���_
#define ENEMY_EXPERIENCE	  (2)		//�G�o���l

//�G�e���
#define ENEMY_BULLET_MAX_NUM  (20)		//�G�e��
#define ENEMY_BULLET_SPD      (2)		//�G�e�X�s�[�h
#define ENEMY_BULLET_INTERVAL (40)		//�G�e���ˊԊu

class Enemy
{
protected:
	//�G���������
	int handle = 0;				//�摜�n���h��
	int Experience = 0;			//�G�̌o���l
	int point = 0;				//�G�̓��_
	int EnemyATK = 0;			//�G�̍U����
	float Posx = 0.0f;			//X���W
	float Posy = 0.0f;			//Y���W
	bool Enemy_is_alive;		//�G�����t���O

	//�G�e���
	int bullet_handle = 0;		//�e�摜�n���h��
	bool bullet_is_use;			//�e�g�p�t���O

public:

	Enemy();					//�R���X�g���N�^
	~Enemy();					//�f�X�g���N�^

	//�G������
	void InitEnemy();

	//�G�ǂݍ���
	void LoadEnemy();

	////�G�e�ǂݍ���
	//void LoadEnemyBullet();

	//�G�U��
	void ATKEnemy();

	////�e�ړ�����
	//void MoveBullet();

	//�G�̕`��
	void DrawEnemy();

	//�G�e�`��
	void DrawEnemyBullet();

	//�G�̌㏈��
	void FinEnemy();


	//�G�S�Ń`�F�b�N
	//bool IsAllKillEnemy();

	//�R�����g�A�E�g���Ă�����͎̂g�����킩��Ȃ��̂ł��Ă܂�//
};

