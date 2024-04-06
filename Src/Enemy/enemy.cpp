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
	/*�G���������*/
	handle = 0;							//�G�摜�n���h��
	Experience = ENEMY_EXPERIENCE;		//�G�o���l
	point = ENEMY_POINT;				//�G���_
	EnemyATK = ENEMY_ATK;				//�G�U����
	Enemy_is_alive = true;				//�G�����t���O

}

void Enemy::LoadEnemy()		//�G�ǂݍ���
{
	/*handle=LoadGraph(ENEMY_PATH)		*/
}

void Enemy::DrawEnemy()		//�G�`��
{
	/*for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_is_alive) {
			DrawRotaGraph();
		}
	}*/
}

bool Enemy::FinEnemy()		//�G�㏈��
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
	//enemybullet->bullethandle= LoadGraph(ENEMY_BULLRT_PATH);
}

//�G�e�`��
void Enemy::DrawEnemyBullet()
{
	/*for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		if (enemybullet->isuse)
		{
			DrawRotaGraph();
		}
	}*/
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
	/*for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		if (enemybullet[i].isuse)
		{
			enemybullet[i].x;
			enemybullet[i].y = EnemyPosy + ENEMY_H;

			enemybullet[i].isuse = true;

			break;

		}
	}*/
}