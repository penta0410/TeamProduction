#pragma once

//敵情報
#define	ENEMY_PATH						//敵の弾パス
#define ENEMY_MAX_NUM		  (40)		//敵の数
#define ENEMY_ATK			  (1)		//敵攻撃力
#define ENEMY_POINT			  (3)		//敵得点
#define ENEMY_EXPERIENCE	  (2)		//敵経験値

//敵弾情報
#define ENEMY_BULLET_MAX_NUM  (20)		//敵弾数
#define ENEMY_BULLET_SPD      (2)		//敵弾スピード
#define ENEMY_BULLET_INTERVAL (40)		//敵弾発射間隔

struct EnemyBulletInfo
{
	int bullethandle;		//弾画像ハンドル
	int x, y;				//座標
	bool bulletisUse;		//弾使用中フラグ
};

class Enemy
{
protected:

	//敵初期化情報
	int handle = 0;				//画像ハンドル
	int Experience = 0;			//敵の経験値
	int point = 0;				//敵の得点
	int EnemyATK = 0;			//敵の攻撃力
	float Posx = 0.0f;			//X座標
	float Posy = 0.0f;			//Y座標
	bool Enemy_is_alive;		//敵生存フラグ

	

public:

	Enemy();					//コンストラクタ
	~Enemy();					//デストラクタ

	//敵初期化
	void InitEnemy();

	//敵読み込み
	void LoadEnemy();

	////敵弾読み込み
	//void LoadEnemyBullet();

	//敵攻撃
	void ATKEnemy();

	////弾移動処理
	//void MoveBullet();

	//敵の描画
	void DrawEnemy();

	//敵弾描画
	void DrawEnemyBullet();

	//敵の後処理
	bool FinEnemy();


	//敵全滅チェック
	//bool IsAllKillEnemy();

	//コメントアウトしているものは使うかわからないのでしてます//
};

