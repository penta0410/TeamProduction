#pragma once


#define PLAYER_IMAGE_PATH "Data/PlayImage/majo.png"			//プレイヤー画像パス
#define PLAYER_DEFAULT_MOVE_X	   10.0f							//プレイヤーのデフォルトの移動量
#define PLAYER_DEFAULT_HP		   3								//プレイヤーのデフォルトの体力
#define PLAYER_DEFAULT_ATK		   1								//プレイヤーのデフォルトの攻撃力
#define PLAYER_DEFAULT_ATK_SPEED   2								//プレイヤーのデフォルトの攻撃速度
#define PLAYER_DEFAULT_DEF		   1								//プレイヤーのデフォルトの守備力
#define PLAYER_DEFAULT_SPEED       2								//プレイヤーのデフォルト移動速度
#define PLAYER_DEFAULT_LEVEL	   1								//プレイヤーのデフォルトのレベル
#define PLAYER_BEGINNER_LEVEL	   20								//プレイヤーのビギナーレベル
#define PLAYER_MAX_LEVEL		   100								//プレイヤーのマックスレベル
#define PLAYER_W				   150								//プレイヤーの横サイズ
#define PLAYER_H				   220								//プレイヤーの縦サイズ
#define LEVEL_DEFAULT_BORDER_LINE  5								//プレイヤーのデフォルトのレベル境界線
#define INVISIBLE_COOL_TIME		   60								//プレイヤーの無敵時間
#define PLAYER_BULLET_MAX_NUM	   50								//プレイヤーの弾数
class Player
{
private:

	int image_handle = 0;									//プレイヤー画像ハンドル

	float posX = 0.0f;										//プレイヤーのX座標
	float posY = 0.0f;										//プレイヤーのY座標
		
	int LEVEL = 0;											//プレイヤーのレベル
	int EXPERIENCE_POINT = 0;								//プレイヤーの経験値

	float move_x = 0.0f;									//プレイヤーのX移動量
	int HP  = 0;											//プレイヤーの体力
	int ATK = 0;											//プレイヤーの攻撃力
	int ATK_SPEED = 0;										//プレイヤーの攻撃速度
	int Move_Speed = 0;										//プレイヤーの移動速度
	int DEF = 0;											//プレイヤーの守備力
	int level_border_line = 0;								//レベルの境界線
	bool invisible = false;									//無敵状態
	int invisible_cool_time = 0;							//プレイヤーの無敵時間
	float radius = 0;										//プレイヤーの半径
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
															//プレイヤーのレベル処理
	void Level_Up();
															//プレイヤーHPゲット処理
	int GetPlayer_Hp() { return HP; };						
															//プレイヤーｈｐセット
	void  SetPlayer_Hp(int hp);									
															//プレイヤー無敵処理
	void Invisible_Time();
			

		class bullet
		{
		protected:
			int handle = 0;
			int x, y = 0;
			bool isuse = false;
			void init_Bullet();
		};

		class fireball :public bullet
		{
			void load();
			void move();
		};
		class coldball :public bullet
		{
			void load();
			void move();
		};
		class darkball :public bullet
		{
			void load();
			void move();
		};
		class thunderball :public bullet
		{
			void load();
			void move();
		};
		class beam :public bullet
		{
			void load();
			void move();
		};
		class arrow :public bullet
		{
			void load();
			void move();
		};
		class slash :public bullet
		{
			void load();
			void move();
		};
		class boomerang :public bullet
		{
			void load();
			void move();
		};
		
		
		
};
