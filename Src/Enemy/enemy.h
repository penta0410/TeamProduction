#pragma once

//Gîń
#define ENEMY_PATH				//GĚpX
#define ENEMY_MAX_NUM			//GĚ
#define ENEMY_HP 		(3)		//GĚHP
#define ENEMY_ATK		(1)		//GĚU


class Enemy
{
public:

	int handle = 0;				//ćnh
	int enemyHP = 0;			//GĚCt
	int enemyExperience = 0;	//GĚoąl
	int point = 0;				//GĚž_
	float Posx = 0.0f;			//XŔW
	float Posy = 0.0f;			//YŔW
		
	Enemy();
	~Enemy();

	//Gúť
	void InitEnemy();

	//GĚ`ć
	void DrawEnemy();

	//GSĹ`FbN
	bool IsAllKillEnemy();

	

};

