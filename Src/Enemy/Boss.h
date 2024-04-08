#pragma once
#include "enemy.h"

#define BOSS_MAX_NUM	  (1)									//�{�X�ő吔
#define BOSS_IMAGE_PATH	  "Data/EnemyImage/kariEnemy.png"		//�{�X�摜�p�X
#define BOSS_EXPERIENCE	  (5)									//�{�X�o���l
#define BOSS_RADIUS		  (60)									//�{�X���a
#define	BOSS_POINT		  (10)									//�{�X����l���ł��链�_
#define BOSS_W			  (120)									//�{�X���T�C�Y
#define BOSS_H			  (120)									//�{�X�c�T�C�Y

#define BOSS_BULLET_PATH  "Data/EnemyImage/BossBullet.png"		//�摜�p�X
#define BOSS_BULLET_MAX_NUM (50)								//�{�X�e��

struct BossBullet
{
	int bossBullethandle;
	int x, y;
	bool BossbulletUse;
};

BossBullet bossbulletIndex[BOSS_BULLET_MAX_NUM] = { 0 };

class Boss:public Enemy
{
protected:

	//�G���
	int Boss_handle = 0;			//�{�X�摜�n���h��
	int Boss_experience = 0;		//�{�X�̌o���l
	int Boss_point = 0;				//�{�X�̓��_
	int Radius = 0;					//�{�X���a

	float BossX = 0.0f;				//�{�X��X���W
	float BossY = 0.0f;				//�{�X��Y���W

	bool Boss_is_alive;				//�{�X�����t���O

public:

	Boss();							//�R���X�g���N�^
	~Boss();						//�f�X�g���N�^

	//�{�X������
	void InitBoss();

	//�{�X�ǂݍ���
	void LoadBoss();

	//�{�X�`��
	void DrawBoss();

	//�{�X�㏈��
	bool FinBoss();

	//�{�X�e������
	void InitBossBullet();

	//�{�X�e�ǂݍ���
	void LoadBossBullet();

	//�{�X�e�`��
	void DrawBossBullet();

	//�{�X�e���ˏ���
	bool BossShotBullet(int shotPosX,int shotPosY);

	//�{�X�̒e�ƃv���C���[�̓����蔻��
	void BossBulletCllision();

	//�{�X�ƃv���C���[�̓����蔻��
	void BossPlayerCollision();

	//�{�X�e�ړ�����
	void MoveBossBullet();

};
