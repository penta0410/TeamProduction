#pragma once

//“Gî•ñ
#define	ENEMY_PATH			  "Data/EnemyImage/Tameo.png"		//“G‚Ì’eƒpƒX
#define ENEMY_MAX_NUM		  (5)								//“G‚Ì”
#define ENEMY_POINT			  (3)								//“G“¾“_
#define ENEMY_EXPERIENCE	  (2)								//“GŒoŒ±’l
#define ENEMY_H				  (64)								//“Gc•
#define ENEMY_W				  (64)								//“G‰¡•
#define RADIUS				  (32)								//“G”¼Œa

//“G’eî•ñ
#define ENEMY_BULLRT_PATH	 "Data/EnemyImage/EnemyBullet.png"	//“G‚Ì’eƒpƒX
#define ENEMY_BULLET_MAX_NUM  (20)								//“G’e”

struct Enemybullet
{
	int bullethandle;
	int x, y;
	bool isuse;
};

class Enemy
{
protected:

	Enemybullet enemybullet[ENEMY_BULLET_MAX_NUM] = { 0 };

	//“G‰Šú‰»î•ñ
	int handle = 0;				//‰æ‘œƒnƒ“ƒhƒ‹
	int Experience = 0;			//“G‚ÌŒoŒ±’l
	int point = 0;				//“G‚Ì“¾“_
	int Radius = 0;				//“G‚Ì”¼Œa

	float EnemyPosx[ENEMY_MAX_NUM] = { 0.0f };		//XÀ•W
	float EnemyPosy[ENEMY_MAX_NUM] = { 0.0f };		//YÀ•W

	bool Enemy_is_alive;		//“G¶‘¶ƒtƒ‰ƒO

	//š œA
	//“GˆÚ“®ƒtƒŒ[ƒ€
	int m_EnemyMoveFlame = 0;

public:

	Enemy();					//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	~Enemy();					//ƒfƒXƒgƒ‰ƒNƒ^

	//“G‰Šú‰»
	void InitEnemy();

	//“G“Ç‚İ‚İ
	void LoadEnemy();

	//“G‚Ì•`‰æ	
	void DrawEnemy();

	//“G’Êíˆ—  š œA
	void StepEnemy();

	//“G‚Ìˆ—
	bool KillEnemy();

	//“G’e‰Šú‰»
	void InitEnemyBullet();

	//“G’e“Ç‚İ‚İ
	void LoadEnemyBullet();

	//“G’e•`‰æ
	void DrawEnemyBullet();

	//“G‚Ì’e‚ÆƒvƒŒƒCƒ„[‚Ì“–‚½‚è”»’è
	void EnemyBulletCllision();

	//“G‚ÆƒvƒŒƒCƒ„[‚Ì“–‚½‚è”»’è
	void EnemyPlayerCollision();

	//“G’eˆÚ“®ˆ—
	void MoveEnemyBullet();

	//“G’e”­Ëˆ—
	void shotEnemyBullet();

};

