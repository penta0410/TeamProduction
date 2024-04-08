#pragma once

//�G���
#define	ENEMY_PATH			  "Data/EnemyImage/Tameo.png"		//�G�̒e�p�X
#define ENEMY_MAX_NUM		  (40)								//�G�̐�
#define ENEMY_ATK			  (1)								//�G�U����
#define ENEMY_POINT			  (3)								//�G���_
#define ENEMY_EXPERIENCE	  (2)								//�G�o���l
#define ENEMY_H				  (64)								//�G�c��
#define ENEMY_W				  (64)								//�G����

//�G�e���
#define ENEMY_BULLRT_PATH	 "Data/EnemyImage/EnemyBullet.png"	//�G�̒e�p�X
#define ENEMY_BULLET_MAX_NUM  (20)								//�G�e��

struct Enemybullet
{
	int bullethandle;
	int x, y;
	bool isuse;
};

class Enemy
{
protected:

	Enemybullet enemybullet[ENEMY_BULLET_MAX_NUM] = { 0 };

	//�G���������
	int handle = 0;				//�摜�n���h��
	int Experience = 0;			//�G�̌o���l
	int point = 0;				//�G�̓��_
	int EnemyATK = 0;			//�G�̍U����
	float EnemyPosx = 0.0f;		//X���W
	float EnemyPosy = 0.0f;		//Y���W
	bool Enemy_is_alive;		//�G�����t���O


public:

	Enemy();					//�R���X�g���N�^
	~Enemy();					//�f�X�g���N�^

	//�G������
	void InitEnemy();

	//�G�ǂݍ���
	void LoadEnemy();

	//�G�̕`��
	void DrawEnemy();

	//�G�̌㏈��
	bool FinEnemy();

	//�G�e������
	void InitEnemyBullet();

	//�G�e�ǂݍ���
	void LoadEnemyBullet();

	//�G�e�`��
	void DrawEnemyBullet();

	//�G�e�ړ�����
	void MoveEnemyBullet();

	//�G�e���ˏ���
	void shotEnemyBullet();

};

