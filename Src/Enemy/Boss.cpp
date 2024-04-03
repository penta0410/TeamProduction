#include "DxLib.h"
#include "Boss.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"


void Boss::InitBoss()						//プレイ初期化
{
	Boss_handle = 0;						//画像ハンドル

	Boss_ATK = BOSS_ATK;					//ボス攻撃力
	Boss_HP = BOSS_HP;						//ボス体力
	Boss_point = BOSS_POINT;				//ボスポイント
	Boss_experience = BOSS_EXPERIENCE;


}

void Boss::DrawBoss()						//ボス描画
{

}

void Boss::ATKBoss()						//ボス攻撃
{

}

//bool Boss::KillBoss()						//ボス全滅チェック
//{
//
//}