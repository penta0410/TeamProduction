#include "DxLib.h"
#include "enemy.h"
#include "Boss.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

<<<<<<< Updated upstream
//�����s����Ƃ��R�����g�A�E�g���Ă�������
<<<<<<< HEAD				
=======
>>>>>>> Stashed changes


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

<<<<<<< Updated upstream
=======
=======
void Enemy::Init()
{
	handle = 0;



}

//void Enemy::Draw()
//{
>>>>>>> Stashed changes
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

////void Enemy::Draw()
////{
////
////}
////
////bool Enemy::IsAllKill()
////{
////
////}

//
////�R�����g�A�E�g���Ă�����͎̂g�����킩��Ȃ��̂ł��Ă܂�//


