#include "DxLib.h"
#include "enemy.h"
#include "Boss.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

//↓実行するときコメントアウトしてください
<<<<<<< HEAD				


Enemy::Enemy(){}			//コンストラクタ
Enemy::~Enemy(){}			//デストラクタ

void Enemy::InitEnemy()		//敵初期化
{
	//敵初期化情報
	handle = 0;							//敵画像ハンドル
	Experience = ENEMY_EXPERIENCE;		//敵経験値
	point = ENEMY_POINT;				//敵得点
	EnemyATK = ENEMY_ATK;				//敵攻撃力
	Enemy_is_alive = true;				//敵生存フラグ

}

void Enemy::LoadEnemy()		//敵読み込み
{
	//handle=LoadGraph(ENEMY_PATH)		
}

void Enemy::DrawEnemy()		//敵描画
{
	//DrawRotaGraph()
}

void Enemy::ATKEnemy()		//敵攻撃
{

}

void Enemy::FinEnemy()		//敵後処理
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
////コメントアウトしているものは使うかわからないのでしてます//
=======
<<<<<<< HEAD
=======

