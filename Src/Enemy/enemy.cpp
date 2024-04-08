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
	//“G‰Šú‰»î•ñ
	handle = 0;							//“G‰æ‘œƒnƒ“ƒhƒ‹
	Experience = ENEMY_EXPERIENCE;		//“GŒoŒ±’l
	point = ENEMY_POINT;				//“G“¾“_
	Radius = RADIUS;			//“G”¼Œa

	

	Enemy_is_alive = true;				//“G¶‘¶ƒtƒ‰ƒO

	//š œA================================
	//“GÀ•W
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

	//“GˆÚ“®ƒtƒŒ[ƒ€
	m_EnemyMoveFlame = 0;
	//======================================

}

void Enemy::LoadEnemy()		//“G“Ç‚İ‚İ
{
	handle = LoadGraph(ENEMY_PATH);
}

void Enemy::DrawEnemy()		//“G•`‰æ
{
	if (Enemy_is_alive)
	{
		//“G‚Ì”‚¾‚¯‰ñ‚·
		for (int m_enemy_num = 0; m_enemy_num < ENEMY_MAX_NUM; m_enemy_num++)
		{
			DrawRotaGraph(EnemyPosx[m_enemy_num], EnemyPosy[m_enemy_num],
				2.0f, 0.0f, handle, true);
		}
	}

}

//“G’Êíˆ—  š œA
void Enemy::StepEnemy()
{
	//ƒtƒŒ[ƒ€ƒCƒ“ƒNƒŠƒƒ“ƒg
	m_EnemyMoveFlame++;

	//ƒvƒŒƒCƒV[ƒ“‚És‚Á‚Ä3•b’â~
	if (m_EnemyMoveFlame >= 180)
	{
		for (int i = 0; i < ENEMY_MAX_NUM; i++)
		{
			EnemyPosy[i] += 4;
		}
	}

}

bool Enemy::KillEnemy()		//“Gˆ—
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
	enemybullet->bullethandle= LoadGraph(ENEMY_BULLRT_PATH);
}

//“G’e•`‰æ
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

//“G‚Ì’e‚ÆƒvƒŒƒCƒ„[‚Ì“–‚½‚è”»’è
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

//“G‚ÆƒvƒŒƒCƒ„[‚Ì“–‚½‚è”»’è
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