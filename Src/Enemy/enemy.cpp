#include "DxLib.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"


Enemy::Enemy(){}			//コンストラクタ
Enemy::~Enemy(){}			//デストラクタ

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

void Enemy::ATKEnemy()		//敵攻撃
{

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


