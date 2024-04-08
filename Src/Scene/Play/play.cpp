#include <math.h>
#include "DxLib.h"
#include "play.h"
#include "../Scene.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Common.h"
#include "../Play/play.h"
#include "../../Screen/Screen.h"

//=============================
// プレイシーン
//=============================

Play::Play() {}		//コンストラクタ
Play::~Play() {}	//デストラクタ

//プレイシーン画像パス
const char* PLAY_IMAGE_PATH[PLAY_IMAGE_NUMBER] =
{
	PLAY_BACK_PATH,		//プレイ背景パス
	ITEM_SELECT_PATH,	//看板パス

};

//プレイ初期化  
void Play::InitPlay()
{
	//プレイヤー初期化
	m_player.Init();

	//プレイヤー読み込み
	m_player.LoadPlayer();

	//敵初期化
	m_enemy.InitEnemy();

	//敵読み込み
	m_enemy.LoadEnemy();

	//敵弾初期化
	m_enemy.InitEnemyBullet();

	//敵弾読み込み
	m_enemy.LoadEnemyBullet();
	
	//背景座標
	m_Back_x = BACK_X;
	m_Back_y = BACK_Y;
	m_Back_x_2 = -m_Back_x;
	m_Back_y_2 = -m_Back_y;

	m_SignBoard_x[0] = 500;
	m_SignBoard_x[1] = 800;
	
	m_SignBoard_y[1] = -1400;
	m_SignBoard_y[2] = -2600;
	m_SignBoard_y[3] = -3800;
	m_SignBoard_y[4] = -5000;

	m_scrollFlame = 0;		//スクロールフレーム

	m_imagehandle[0] = LoadGraph(PLAY_IMAGE_PATH[0]);	//プレイ背景画像
	m_imagehandle[1] = LoadGraph(PLAY_IMAGE_PATH[1]);	//看板

	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイ通常処理
void Play::StepPlay(int hp)
{
	//フレームカウント
	m_scrollFlame++;

	//プレイシーンに行って3秒停止
	if (m_scrollFlame >= 180)
	{
		m_Back_y += BACK_SPEED;
		m_Back_y_2 += BACK_SPEED;
	}

	//スクロール処理
	if (m_Back_y > 360 + 710)
	{
		m_Back_y = -BACK_Y;
	}
	if (m_Back_y_2 > 360 + 710)
	{
		m_Back_y_2 = -BACK_Y;
	}




	//敵弾発射処理　　落合
	m_enemy.shotEnemyBullet();

	//敵弾移動処理　　落合
	m_enemy.MoveEnemyBullet();

	//敵通常処理
	m_enemy.StepEnemy();

	//敵処理　　落合
	m_enemy.KillEnemy();

	//プレイヤー処理
	m_player.MovePlayer();

	//クリアシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//プレイシーンフラグをクリアシーンに変更
		m_SceneFlag = 0;

		//'プレイ後処理'へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	}

	//ゲームオーバーシーンへの遷移
	//Tabキー押されたなら
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		//プレイシーンフラグをクリアシーンに変更
		m_SceneFlag = 1;

		//'プレイ後処理'へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	}
	//当たり判定
	for (int m_enemy_num = 0; m_enemy_num <= ENEMY_MAX_NUM; m_enemy_num++)
	{
		if (m_player.IsHit_Enemy(m_enemy.EnemyPosx[m_enemy_num], m_enemy.EnemyPosx[m_enemy_num], m_enemy.Radius))
		{
			//プレイシーンフラグをクリアシーンに変更
			m_SceneFlag = 1;

			//'プレイ後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		}
	}
}

//プレイ描画処理
void Play::DrawPlay(int hp)
{
	//プレイ背景描画
	DrawRotaGraph(m_Back_x, m_Back_y, 1.0f, 0.0f, m_imagehandle[0], true);
	DrawRotaGraph(m_Back_x, m_Back_y_2, 1.0f, 0.0f, m_imagehandle[0], true);


	//看板描画
	for (int i = 0; i < 5; i++)
	{
		/*DrawRotaGraph(m_SignBoard_x[i], m_SignBoard_y[i], 1.0f, 0.0f, m_imagehandle[1], true);*/
	}

	//プレイヤー描画
	m_player.DrawPlayer();
	
	//敵描画　　落合
	m_enemy.DrawEnemy();
	m_enemy.DrawEnemyBullet();

}

//プレイ後処理
void Play::FinPlay()
{
	//画像消去
	for (int i = 0; i < PLAY_IMAGE_NUMBER; i++)
	{
		DeleteGraph(m_imagehandle[i]);
	}

	//クリアシーンへ
	if (m_SceneFlag == 0)
	{
		//ゲームクリアシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}

	//ゲームオーバーシーンへ
	if (m_SceneFlag == 1)
	{
		//ゲームオーバーシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;

	}
}


