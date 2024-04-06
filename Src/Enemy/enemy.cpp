#include "DxLib.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"
#include "../Common.h"

Enemy::Enemy(){}			//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Enemy::~Enemy(){}			//ƒfƒXƒgƒ‰ƒNƒ^

//“GƒXƒe[ƒ^ƒX
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

//“G’e‰Šú‰»
void Enemy::InitEnemyBullet()
{
	for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		enemybullet->bullethandle = 0;	//“G’e‰æ‘œƒnƒ“ƒhƒ‹
		enemybullet->x = 0;				//XÀ•W
		enemybullet->y = 0;				//YÀ•W
		enemybullet->isuse = false;		//g—p’†ƒtƒ‰ƒO
	}
}

//“G’e“Ç‚İ‚İ
void Enemy::LoadEnemyBullet()
{
	//enemybullet->bullethandle= LoadGraph(ENEMY_BULLRT_PATH);
}

//“G’e•`‰æ
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

//“G’eˆÚ“®ˆ—
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

//“G’e”­Ëˆ—
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