#include "DxLib.h"
#include "enemy.h"
#include "Boss.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

//�����s����Ƃ��R�����g�A�E�g���Ă�������
<<<<<<< HEAD				


Enemy::Enemy(){}			//�R���X�g���N�^
Enemy::~Enemy(){}			//�f�X�g���N�^

void Enemy::InitEnemy()		//�G������
{
	//�G���������
	handle = 0;							//�G�摜�n���h��
	Experience = ENEMY_EXPERIENCE;		//�G�o���l
	point = ENEMY_POINT;				//�G���_
	EnemyATK = ENEMY_ATK;				//�G�U����
	Enemy_is_alive = true;				//�G�����t���O

}

void Enemy::LoadEnemy()		//�G�ǂݍ���
{
	//handle=LoadGraph(ENEMY_PATH)		
}

void Enemy::DrawEnemy()		//�G�`��
{
	//DrawRotaGraph()
}

void Enemy::ATKEnemy()		//�G�U��
{

}

void Enemy::FinEnemy()		//�G�㏈��
{

}

=======
////Enemy::Enemy()
////{
////
////}
////
////Enemy::~Enemy()
////{
////
////}
////
////void Enemy::Init()
////{
////	handle = 0;
////
////
////
////}
////
=======
//Enemy::Enemy()
//{
//
//}
//
//Enemy::~Enemy()
//{
//
//}
//
//void Enemy::Init()
//{
//	handle = 0;
//	point = 0;
//}
//
<<<<<<< Updated upstream
=======
>>>>>>> 013ee3738470a81b1ba1ade8b80d07a30904121f
>>>>>>> Stashed changes
////void Enemy::Draw()
////{
////
////}
////
////bool Enemy::IsAllKill()
////{
////
////}
<<<<<<< Updated upstream
>>>>>>> fec13275ec03b2afa9f01ca8c49686a91d24406c
//
////�R�����g�A�E�g���Ă�����͎̂g�����킩��Ȃ��̂ł��Ă܂�//
=======
<<<<<<< HEAD
=======

