#include "DxLib.h"
#include "player.h"
#include "../Input/Input.h"
#include "../Scene/Play/Play.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Effect/Effect.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"
#include "../Common.h"
#include<math.h>


Player::Player()
{

}

Player::~Player()
{
	
}

void Player::Init()
{
	image_handle = 0;							

	radius = 60;//仮
	posX = WINDOW_WIDTH / 2;
	posY = WINDOW_HEIGHT - (PLAYER_H / 2);

	move_x			    = PLAYER_DEFAULT_MOVE_X;
	HP			        = PLAYER_DEFAULT_HP;
	ATK					= PLAYER_DEFAULT_ATK;
	ATK_SPEED		    = PLAYER_DEFAULT_ATK_SPEED;
	DEF				    = PLAYER_DEFAULT_DEF;
	Move_Speed          = PLAYER_DEFAULT_SPEED;
	EXPERIENCE_POINT    = 0;
	LEVEL		        = PLAYER_DEFAULT_LEVEL;
	level_border_line   = LEVEL_DEFAULT_BORDER_LINE;
	invisible_cool_time = INVISIBLE_COOL_TIME;
	invisible			= false;
}

void Player::LoadPlayer()
{
	image_handle = LoadGraph(PLAYER_IMAGE_PATH);
}

//プレイヤー描画処理	國廣
void Player::DrawPlayer()
{
	DrawRotaGraph(posX, posY, 1.0f, 0.0f, image_handle, true);

}

void Player::MovePlayer()
{
	//プレイヤー道当たり判定
	if (posX > 420)
	{
		if (Input_Left())		 posX -= move_x;
	}
	if (posX < 850)
	{
		if (Input_Right())		 posX += move_x;
	}
	if (Input_LeftAndRight())posX += 0.0f;
	else					 posX += 0.0f;
}

bool Player::Input_Left()
{
	if (CheckHitKey(KEY_INPUT_A) == 1 || 
		CheckHitKey(KEY_INPUT_LEFT) == 1)
		return true;
}
bool Player::Input_Right()
{
	if (CheckHitKey(KEY_INPUT_D) == 1 || 
		CheckHitKey(KEY_INPUT_RIGHT) == 1)
		return true;
}
bool Player::Input_LeftAndRight()
{
	if(Input_Left()&& Input_Right())
		return true;
}

void Player::Level_Up()
{
	if (LEVEL < PLAYER_BEGINNER_LEVEL)
	{
		if (EXPERIENCE_POINT > level_border_line)
		{
			LEVEL++;
			level_border_line += 5;
		}
	}
	else if (LEVEL < PLAYER_MAX_LEVEL)
	{
		if (EXPERIENCE_POINT > level_border_line)
		{
			LEVEL++;
			level_border_line *= 2;
		}
	}
}

void Player::Invisible_Time()
{
	if (invisible)
	{
		invisible_cool_time++;
		if (invisible_cool_time > 60)
		{
			invisible_cool_time = 0;
			invisible = false;
		}
	}
}

//プレイヤーｈｐセット
void  Player::SetPlayer_Hp(int hp)
{
	HP = HP + hp;
}

bool Player::IsHit_Enemy(float enemyx, float enemyy, float enemyradius)
{
	if (IsHitCircle(posX, posY, radius, enemyx, enemyy, enemyradius))
		return true;
	else return false;
}

//プレイヤー弾初期化
void Player::bullet::init_Bullet()
{
	for (int i = 0; i < PLAYER_BULLET_MAX_NUM; i++)
	{
		handle = 0;		//弾画像ハンドル
		x = 0;			//X座標
		y = 0;			//Y座標
		isuse = false;	//使用中フラグ
	}
}
void Player::beam::load()
{

}
void Player::arrow::load()
{

}
void Player::slash::load()
{

}
void Player::fireball::load()
{

}
void Player::coldball::load()
{

}
void Player::thunderball::load()
{

}
void Player::darkball::load()
{

}
void  Player::boomerang::load()
{

}


void Player::beam::move()
{

}
void Player::arrow::move()
{

}
void Player::slash::move()
{

}
void Player::fireball::move()
{

}
void Player::coldball::move()
{

}
void Player::thunderball::move()
{

}
void Player::darkball::move()
{

}
void  Player::boomerang::move()
{

}
