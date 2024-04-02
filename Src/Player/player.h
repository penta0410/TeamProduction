#pragma once

#define PLAYER_IMAGE_PATH "Data/PlayImage/majo.png"		//プレイヤー画像パス
#define DEFAULT_MOVE_X	  10.0f							//プレイヤーのデフォルトの移動量
#define DEFAULT_HP		  3								//プレイヤーのデフォルトの体力
#define DEFAULT_ATK		  1								//プレイヤーのデフォルトの攻撃力
#define DEFAULT_DEF		  1								//プレイヤーのデフォルトの守備力


#define PLAYER_W		  150							//プレイヤーの横サイズ
#define PLAYER_H		  220							//プレイヤーの縦サイズ

class Player
{
private:

	int image_handle = 0;								//プレイヤー画像ハンドル

	float posX = 0.0f;									//プレイヤーのX座標
	float posY = 0.0f;									//プレイヤーのY座標

	float move_x = 0.0f;								//プレイヤーのX移動量
	int HP  = 0;										//プレイヤーの体力
	int ATK = 0;										//プレイヤーの攻撃力
	int DEF = 0;										//プレイヤーの守備力

public:

														//コンストラクタ
	Player();					
														//デストラクタ
	~Player();											

														//プレイヤーの初期化
	void Init();										

														//プレイヤーの読み込み
	void LoadPlayer();									
	
														//プレイヤーの基本的な移動
	void MovePlayer();		

														//Aキーまたは←キーを押しているか
	bool Input_Left();
														//Dキーまたは→キーを押しているか
	bool Input_Right();
														//AキーとDキーまたは←キーと→キーを同時に押しているか
	bool Input_LeftAndRight();

};
