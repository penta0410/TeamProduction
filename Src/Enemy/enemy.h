#pragma once

//敵情報
#define ENEMY_PATH				//敵のパス
#define ENEMY_MAX_NUM			//敵の数
#define ENEMY_HP 		(3)		//敵のHP
#define ENEMY_ATK		(1)		//敵の攻撃


class Enemy
{
public:

	int handle = 0;		//画像ハンドル
	int HP = 0;			//敵のライフ
	int Experience = 0;	//敵の経験値
	int point = 0;				//敵の得点
	float Posx = 0.0f;			//X座標
	float Posy = 0.0f;			//Y座標
		
	Enemy();
	~Enemy();

	//敵初期化
	void Init();

	//敵の描画
	void Draw();

	//敵全滅チェック
	bool IsAllKill();

	

};

