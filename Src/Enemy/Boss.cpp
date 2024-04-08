#include "DxLib.h"
#include "Boss.h"
#include "../Common.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

//Boss::Boss(){}		//コンストラクタ
//Boss::~Boss(){}		//デストラクタ


void Boss::InitBoss()						//プレイ初期化
{
	Boss_handle = 0;						//画像ハンドル
	Boss_point = BOSS_POINT;				//ボスポイント
	Boss_experience = BOSS_EXPERIENCE;		//ボス経験値
	Radius = BOSS_RADIUS;					//半径
	Boss_is_alive = true;					//ボス生存フラグ

}

void Boss::LoadBoss()						//ボス読み込み
{
	Boss_handle = LoadGraph(BOSS_IMAGE_PATH);	//画像ができるまで
}

void Boss::DrawBoss()						//ボス描画
{
	for (int i = 0; i < BOSS_MAX_NUM; i++)
	{
		if (Boss_is_alive)
		{
			DrawRotaGraph(BossX,BossY,1.0f,0.0,Boss_handle,true);
		}
	}
	
}

bool Boss::FinBoss()						//ボス後処理
{

	for (int i = 0; i < BOSS_MAX_NUM; i++)
	{
		if (Boss_is_alive) {
			//ボスが生きている
			return false;
		}
	}

	//ボスが倒された
	return true;
}

//ボス弾初期化
void InitBossBullet()
{
	for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
	{
		bossbulletIndex->bossBullethandle = 0;
		bossbulletIndex->x = 0;
		bossbulletIndex->y = 0;
		bossbulletIndex->BossbulletUse = false;
	}
}

bool Boss::BossShotBullet(int shotPosX, int shotPosY)
{
	for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
	{
		if (bossbulletIndex[i].BossbulletUse)
		{
			//弾座標の初期位置に敵の座標
			bossbulletIndex[i].x = shotPosX;
			bossbulletIndex[i].y = shotPosY + BOSS_H;
			bossbulletIndex[i].BossbulletUse = true;

			//発射成功
			return true;
		}
	}
	//失敗
	return false;
}

//ボス弾読み込み
void Boss::LoadBossBullet()
{
	bossbulletIndex->bossBullethandle = LoadGraph(BOSS_BULLET_PATH);
}

//ボス弾描画
void Boss::DrawBossBullet()
{
	for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
	{
		if (bossbulletIndex->BossbulletUse)
		{
			DrawRotaGraph(bossbulletIndex[i].x,bossbulletIndex[i].y,1.0f,0.0,bossbulletIndex[i].bossBullethandle,true);
		}
	}
}

//ボス弾移動処理
void Boss::MoveBossBullet()
{
	for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
	{
		if (bossbulletIndex[i].BossbulletUse)
		{
			bossbulletIndex->y += 3;

			//画面外に出たら未使用に戻す
			if (bossbulletIndex[i].y < WINDOW_HEIGHT)
			{
				bossbulletIndex->BossbulletUse = false;
			}
		}
	}
}

//ボスの弾とプレイヤーの当たり判定
void Boss::BossBulletCllision()
{

}

//ボスとプレイヤーの当たり判定
void Boss::BossPlayerCollision()
{

}