#include "DxLib.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"
#include "../Common.h"

Enemy::Enemy(){}			//コンストラクタ
Enemy::~Enemy(){}			//デストラクタ

//敵ステータス
void Enemy::InitEnemy()		//敵初期化
{
	//敵初期化情報
	handle = 0;							//敵画像ハンドル
	Experience = ENEMY_EXPERIENCE;		//敵経験値
	point = ENEMY_POINT;				//敵得点
	Radius = RADIUS;			//敵半径

	

	Enemy_is_alive = true;				//敵生存フラグ

	//國廣================================
	//敵座標
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

	//敵移動フレーム
	m_EnemyMoveFlame = 0;
	//======================================

}

void Enemy::LoadEnemy()		//敵読み込み
{
	handle = LoadGraph(ENEMY_PATH);
}

void Enemy::DrawEnemy()		//敵描画
{
	if (Enemy_is_alive)
	{
		//敵の数だけ回す
		for (int m_enemy_num = 0; m_enemy_num < ENEMY_MAX_NUM; m_enemy_num++)
		{
			DrawRotaGraph(EnemyPosx[m_enemy_num], EnemyPosy[m_enemy_num],
				2.0f, 0.0f, handle, true);
		}
	}

}

//敵通常処理  國廣
void Enemy::StepEnemy()
{
	//フレームインクリメント
	m_EnemyMoveFlame++;

	//プレイシーンに行って3秒停止
	if (m_EnemyMoveFlame >= 180)
	{
		for (int i = 0; i < ENEMY_MAX_NUM; i++)
		{
			EnemyPosy[i] += 4;
		}
	}

}

bool Enemy::KillEnemy()		//敵処理
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_is_alive) {
			//敵が生きている
			return false;
		}
	}
	//敵が倒された
	return true;
}

//敵弾初期化
void Enemy::InitEnemyBullet()
{
	for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	{
		enemybullet->bullethandle = 0;	//敵弾画像ハンドル
		enemybullet->x = 0;				//X座標
		enemybullet->y = 0;				//Y座標
		enemybullet->isuse = false;		//使用中フラグ
	}
}

//敵弾読み込み
void Enemy::LoadEnemyBullet()
{
	enemybullet->bullethandle= LoadGraph(ENEMY_BULLRT_PATH);
}

//敵弾描画
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

//敵弾移動処理
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

//敵弾発射処理
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

//敵の弾とプレイヤーの当たり判定
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

//敵とプレイヤーの当たり判定
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