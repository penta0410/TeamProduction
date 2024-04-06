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


};

//プレイ初期化  
void Play::InitPlay()
{
	//プレイヤー初期化
	m_player.Init();
	
	//背景座標
	m_Back_x = BACK_X;		
	m_Back_y = BACK_Y;
	m_Back_x_2 = -m_Back_x;
	m_Back_y_2 = -m_Back_y;

	m_scrollFlame = 0;		//スクロールフレーム

	m_imagehandle[0] = LoadGraph(PLAY_IMAGE_PATH[0]);	//プレイ背景画像

	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイ通常処理
void Play::StepPlay()
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

}

//プレイ描画処理
void Play::DrawPlay()
{

	//プレイ背景描画
	DrawRotaGraph(m_Back_x, m_Back_y, 1.0f, 0.0f, m_imagehandle[0], true);
	DrawRotaGraph(m_Back_x, m_Back_y_2, 1.0f, 0.0f, m_imagehandle[0], true);

	DrawFormatString(100, 100, GetColor(0, 0, 0), "%d", m_player.GetPlayer_Hp(), true);

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


