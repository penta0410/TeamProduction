#include "DxLib.h"
#include "Boss.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

Boss::~Boss(){}		//デストラクタ


void Boss::InitBoss()						//プレイ初期化
{
	Boss_handle = 0;						//画像ハンドル

	Boss_ATK = BOSS_ATK;					//ボス攻撃力
	Boss_HP = BOSS_HP;						//ボス体力
	Boss_point = BOSS_POINT;				//ボスポイント
	Boss_experience = BOSS_EXPERIENCE;		//ボス経験値
	Boss_is_alive = true;					//ボス生存フラグ
}

void Boss::LoadBoss()						//ボス読み込み
{
	//Boss_handle = LoadGraph(BOSS_IMAGE_PATH);	//画像ができるまで
}

void Boss::DrawBoss()						//ボス描画
{
	//DrawRotaGraph()
}

void Boss::ATKBoss()						//ボス攻撃
{
	
}

void Boss::FinBoss()						//ボス後処理
{

}