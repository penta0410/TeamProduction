#pragma once

//“Gî•ñ
#define	ENEMY_PATH			  "Data/EnemyImage/Tameo.png"		//“G‚Ì’eƒpƒX
#define ENEMY_MAX_NUM		  (40)								//“G‚Ì”
#define ENEMY_ATK			  (1)								//“GUŒ‚—Í
#define ENEMY_POINT			  (3)								//“G“¾“_
#define ENEMY_EXPERIENCE	  (2)								//“GŒoŒ±’l
#define ENEMY_H				  (64)								//“Gc•
#define ENEMY_W				  (64)								//“G‰¡•

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
	int EnemyATK = 0;			//“G‚ÌUŒ‚—Í
	float EnemyPosx = 0.0f;		//XÀ•W
	float EnemyPosy = 0.0f;		//YÀ•W
	bool Enemy_is_alive;		//“G¶‘¶ƒtƒ‰ƒO


public:

	Enemy();					//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	~Enemy();					//ƒfƒXƒgƒ‰ƒNƒ^

	//“G‰Šú‰»
	void InitEnemy();

	//“G“Ç‚İ‚İ
	void LoadEnemy();

	//“G‚Ì•`‰æ
	void DrawEnemy();

	//“G‚ÌŒãˆ—
	bool FinEnemy();

	//“G’e‰Šú‰»
	void InitEnemyBullet();

	//“G’e“Ç‚İ‚İ
	void LoadEnemyBullet();

	//“G’e•`‰æ
	void DrawEnemyBullet();

	//“G’eˆÚ“®ˆ—
	void MoveEnemyBullet();

	//“G’e”­Ëˆ—
	void shotEnemyBullet();

};

