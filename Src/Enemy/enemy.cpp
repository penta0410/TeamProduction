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
	/*敵初期化情報*/
	handle = 0;							//敵画像ハンドル
	Experience = ENEMY_EXPERIENCE;		//敵経験値
	point = ENEMY_POINT;				//敵得点
	EnemyATK = ENEMY_ATK;				//敵攻撃力
	Enemy_is_alive = true;				//敵生存フラグ

}

void Enemy::LoadEnemy()		//敵読み込み
{
	/*handle=LoadGraph(ENEMY_PATH)		*/
}

void Enemy::DrawEnemy()		//敵描画
{
	/*for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_is_alive) {
			DrawRotaGraph();
		}
	}*/
}

bool Enemy::FinEnemy()		//敵後処理
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
	//enemybullet->bullethandle= LoadGraph(ENEMY_BULLRT_PATH);
}

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

void Enemy::shotEnemyBullet()
{
	///*for (int i = 0; i < ENEMY_BULLET_MAX_NUM; i++)
	//{
	//	if (enemybullet[i].isuse)
	//	{
	//		enemybullet[i].x;
	//		enemybullet[i].y = EnemyPosy + ENEMY_H;

	//		enemybullet[i].isuse = true;

	//		break;

	//	}*/
	//}
}