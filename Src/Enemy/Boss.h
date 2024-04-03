#pragma once
#include "enemy.h"

#define BOSS_IMAGE_PATH				//ボス画像パス
#define BOSS_EXPERIENCE	  (5)		//ボス経験値
#define	BOSS_POINT		  (10)		//ボスから獲得できる得点
#define	BOSS_HP			  (20)		//ボスデフォルト体力
#define BOSS_ATK		  (3)		//ボスデフォルト攻撃力
#define BOSS_W						//ボス横サイズ
#define BOSS_H						//ボス縦サイズ

class Boss:public Enemy
{
public:

	int Boss_handle = 0;			//ボス画像ハンドル
	int Boss_experience = 0;		//ボスの経験値
	int Boss_point = 0;				//ボスの得点
	int Boss_HP = 0;				//ボスの体力
	int Boss_ATK = 0;				//ボスの攻撃力
	float BossX = 0.0f;				//ボスのX座標
	float BossY = 0.0f;				//ボスのY座標
	bool  Boss_is_alive;			//ボス生存フラグ

	Boss();							//コンストラクタ
	~Boss();						//デストラクタ

	//ボス初期化
	void InitBoss();

	//ボス描画
	void DrawBoss();

	//ボス攻撃
	void ATKBoss();

	//ボス全滅チェック
	/*bool KillBoss();*/

};
