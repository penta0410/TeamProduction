#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Scene/Play/Play.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Effect/Effect.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"
#include "../Common.h"

Player::Player()
{

}

Player::~Player()
{
	
}

void Player::Init()
{
	image_handle = 0;							

	posX = WINDOW_WIDTH / 2;
	posY = WINDOW_HEIGHT - (PLAYER_H / 2);

	move_x = DEFAULT_MOVE_X;
	HP     = DEFAULT_HP;										
	ATK    = DEFAULT_ATK;										
	DEF	   = DEFAULT_DEF;
}

void Player::LoadPlayer()
{
	image_handle = LoadGraph(PLAYER_IMAGE_PATH);
}

void Player::MovePlayer()
{
	if (Input_Left())		 posX -= move_x;
	if (Input_Right())		 posX += move_x;
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