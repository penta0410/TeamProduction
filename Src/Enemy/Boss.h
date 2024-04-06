#pragma once
#include "enemy.h"

#define BOSS_MAX_NUM	  (1)		//ボス最大数
#define BOSS_IMAGE_PATH				//ボス画像パス
#define BOSS_EXPERIENCE	  (5)		//ボス経験値
#define	BOSS_POINT		  (10)		//ボスから獲得できる得点
#define	BOSS_HP			  (20)		//ボスデフォルト体力
#define BOSS_ATK		  (3)		//ボスデフォルト攻撃力
#define BOSS_W						//ボス横サイズ
#define BOSS_H						//ボス縦サイズ

#define BOSS_BULLET_PATH			//画像パス
#define BOSS_BULLET_MAX_NUM (50)	//ボス弾数

struct BossBullet
{
	int bosshandle;
	int x, y;
	bool BossbulletUse;
};

BossBullet bossbulletIndex[BOSS_BULLET_MAX_NUM] = { 0 };

class Boss:public Enemy
{
protected:

	//敵情報
	int Boss_handle = 0;			//ボス画像ハンドル
	int Boss_experience = 0;		//ボスの経験値
	int Boss_point = 0;				//ボスの得点
	int Boss_HP = 0;				//ボスの体力
	int Boss_ATK = 0;				//ボスの攻撃力

	float BossX = 0.0f;				//ボスのX座標
	float BossY = 0.0f;				//ボスのY座標

	bool Boss_is_alive;				//ボス生存フラグ

public:

	Boss();							//コンストラクタ
	~Boss();						//デストラクタ

	//ボス初期化
	void InitBoss();

	//ボス読み込み
	void LoadBoss();

	//ボス描画
	void DrawBoss();

	//ボス後処理
	bool FinBoss();

	//ボス弾初期化
	void InitBossBullet();

	//ボス弾読み込み
	void LoadBossBullet();

	//ボス弾描画
	void DrawBossBullet();

	//ボス弾発射処理
	bool BossShotBullet(int shotPosX,int shotPosY);

	//ボス弾移動処理
	void MoveBossBullet();

};
