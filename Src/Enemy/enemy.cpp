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
	/*DrawRotaGraph();*/
}

void Enemy::ATKEnemy()		//�G�U��
{

}

void Enemy::FinEnemy()		//�G�㏈��
{

}


