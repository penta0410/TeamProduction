#include "DxLib.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"


Enemy::Enemy(){}			//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Enemy::~Enemy(){}			//ƒfƒXƒgƒ‰ƒNƒ^

void Enemy::InitEnemy()		//“G‰Šú‰»
{
	/*“G‰Šú‰»î•ñ*/
	handle = 0;							//“G‰æ‘œƒnƒ“ƒhƒ‹
	Experience = ENEMY_EXPERIENCE;		//“GŒoŒ±’l
	point = ENEMY_POINT;				//“G“¾“_
	EnemyATK = ENEMY_ATK;				//“GUŒ‚—Í
	Enemy_is_alive = true;				//“G¶‘¶ƒtƒ‰ƒO

}

void Enemy::LoadEnemy()		//“G“Ç‚İ‚İ
{
	/*handle=LoadGraph(ENEMY_PATH)		*/
}

void Enemy::DrawEnemy()		//“G•`‰æ
{
	/*for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_is_alive) {
			DrawRotaGraph();
		}
	}*/

	
}

void Enemy::ATKEnemy()		//“GUŒ‚
{

}

bool Enemy::FinEnemy()		//“GŒãˆ—
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_is_alive) {
			//“G‚ª¶‚«‚Ä‚¢‚é
			return false;
		}
	}

	//“G‚ª“|‚³‚ê‚½
	return true;

}


