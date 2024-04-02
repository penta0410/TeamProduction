#pragma once

//敵情報
#define ENEMY_PATH		//敵のパス
#define ENEMY_MAX_NUM	//敵の数

//敵情報
struct EnemyInfo
{
	int handle;		//画像ハンドル
	int x, y;		//座標
	int enemyHP;	//敵のライフ			
	bool isActive;	//敵の生存フラグ
};

class Enemy
{
public:

	//敵初期化

	//敵の描画

	//敵全滅チェック

};

