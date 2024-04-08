#pragma once

//�G���
#define	ENEMY_PATH			  "Data/EnemyImage/Tameo.png"		//�G�̒e�p�X
#define ENEMY_MAX_NUM		  (5)								//�G�̐�
#define ENEMY_POINT			  (3)								//�G���_
#define ENEMY_EXPERIENCE	  (2)								//�G�o���l
#define ENEMY_H				  (64)								//�G�c��
#define ENEMY_W				  (64)								//�G����
#define RADIUS				  (32)								//�G���a

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
	int Radius = 0;				//�G�̔��a

	float EnemyPosx[ENEMY_MAX_NUM] = { 0.0f };		//X���W
	float EnemyPosy[ENEMY_MAX_NUM] = { 0.0f };		//Y���W

	bool Enemy_is_alive;		//�G�����t���O

	//���A
	//�G�ړ��t���[��
	int m_EnemyMoveFlame = 0;

public:

	Enemy();					//�R���X�g���N�^
	~Enemy();					//�f�X�g���N�^

	//�G������
	void InitEnemy();

	//�G�ǂݍ���
	void LoadEnemy();

	//�G�̕`��	
	void DrawEnemy();

	//�G�ʏ폈��  ���A
	void StepEnemy();

	//�G�̏���
	bool KillEnemy();

	//�G�e������
	void InitEnemyBullet();

	//�G�e�ǂݍ���
	void LoadEnemyBullet();

	//�G�e�`��
	void DrawEnemyBullet();

	//�G�̒e�ƃv���C���[�̓����蔻��
	void EnemyBulletCllision();

	//�G�ƃv���C���[�̓����蔻��
	void EnemyPlayerCollision();

	//�G�e�ړ�����
	void MoveEnemyBullet();

	//�G�e���ˏ���
	void shotEnemyBullet();

};

