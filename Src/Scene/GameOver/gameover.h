#pragma once
#include "../Title/title.h"

const int GAME_OVER_IMAGE_NUMBER = 10;	//画像枚数

//ゲームオーバー画面パス
#define GAME_OVER_BACK_PATH			"Data/GameOverImage/GameOver.png"

class GameOver : public Title
{
private:


public:

	//ゲームオーバー初期化
	void InitGameOver();

	//ゲームオーバー通常処理
	void StepGameOver();

	//ゲームオーバー描画処理
	void DrawGameOver();

	//ゲームオーバー後処理
	void FinGameOver();

};