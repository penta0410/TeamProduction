#include "DxLib.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"


Enemy::Enemy(){}			//�R���X�g���N�^
Enemy::~Enemy(){}			//�f�X�g���N�^

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

void Enemy::ATKEnemy()		//�G�U��
{

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


