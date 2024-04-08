#include "DxLib.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"
#include "../Common.h"

Enemy::Enemy(){}			//�R���X�g���N�^
Enemy::~Enemy(){}			//�f�X�g���N�^

//�G�X�e�[�^�X
void Enemy::InitEnemy()		//�G������
{
	//�G���������
	handle = 0;							//�G�摜�n���h��
	Experience = ENEMY_EXPERIENCE;		//�G�o���l
	point = ENEMY_POINT;				//�G���_
	Radius = RADIUS;			//�G���a

	

	Enemy_is_alive = true;				//�G�����t���O

	//���A================================
	//�G���W
	EnemyPosx[0] = 500;
	EnemyPosx[1] = 800;
	EnemyPosx[2] = 500;
	EnemyPosx[3] = 800;
	EnemyPosx[4] = 500;
	EnemyPosy[0] = 0;
	EnemyPosy[1] = -800;
	EnemyPosy[2] = -2000;
	EnemyPosy[3] = -3200;
	EnemyPosy[4] = -4400;

	//�G�ړ��t���[��
	m_EnemyMoveFlame = 0;
	//======================================

}

void Enemy::LoadEnemy()		//�G�ǂݍ���
{
	handle = LoadGraph(ENEMY_PATH);
}

void Enemy::DrawEnemy()		//�G�`��
{
	if (Enemy_is_alive)
	{
		//�G�̐�������
		for (int m_enemy_num = 0; m_enemy_num < ENEMY_MAX_NUM; m_enemy_num++)
		{
			DrawRotaGraph(EnemyPosx[m_enemy_num], EnemyPosy[m_enemy_num],
				2.0f, 0.0f, handle, true);
		}
	}

}

//�G�ʏ폈��  ���A
void Enemy::StepEnemy()
{
	//�t���[���C���N�������g
	m_EnemyMoveFlame++;

	//�v���C�V�[���ɍs����3�b��~
	if (m_EnemyMoveFlame >= 180)
	{
		for (int i = 0; i < ENEMY_MAX_NUM; i++)
		{
			EnemyPosy[i] += 4;
		}
	}

}

bool Enemy::KillEnemy()		//�G����
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_is_alive) {
			//�G�������Ă���
			return false;
		}
	}
	//�G���|���ꂽ
	return true;
}

//�G�e������
void Enemy::InitEnemyBullet()
{
	for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		enemybullet->bullethandle = 0;	//�G�e�摜�n���h��
		enemybullet->x = 0;				//X���W
		enemybullet->y = 0;				//Y���W
		enemybullet->isuse = false;		//�g�p���t���O
	}
}

//�G�e�ǂݍ���
void Enemy::LoadEnemyBullet()
{
	enemybullet->bullethandle= LoadGraph(ENEMY_BULLRT_PATH);
}

//�G�e�`��
void Enemy::DrawEnemyBullet()
{
	for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		if (enemybullet->isuse)
		{
			DrawRotaGraph(enemybullet[i].x,enemybullet[i].y,1.0,0.0,enemybullet[i].bullethandle,true);
		}
	}
}

//�G�e�ړ�����
void Enemy::MoveEnemyBullet()
{
	for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		if (enemybullet[i].isuse)
		{
			enemybullet[i].y += 5;
			if (enemybullet[i].y< WINDOW_HEIGHT)
			{
				enemybullet[i].isuse = false;
			}
		}
	}
}

//�G�e���ˏ���
void Enemy::shotEnemyBullet()
{
	for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		if (enemybullet[i].isuse)
		{
			enemybullet[i].x;
			/*enemybullet[i].y = EnemyPosy + ENEMY_H;*/

			enemybullet[i].isuse = true;

			break;

		}
	}
}

//�G�̒e�ƃv���C���[�̓����蔻��
void Enemy::EnemyBulletCllision()
{
	/*for (int enemybulletindex = 0; enemybulletindex < ENEMY_BULLET_MAX_NUM; enemybulletindex++)
	{
		if (enemybullet[enemybulletindex].isuse == false) {
			continue;
		}
		if (IsHitCircle())
		{

		}
	}*/
}

//�G�ƃv���C���[�̓����蔻��
void Enemy::EnemyPlayerCollision()
{
	/*for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_is_alive == false) {
			continue;
		}

		if (IsHitCircle())
		{

		}
	}*/
}