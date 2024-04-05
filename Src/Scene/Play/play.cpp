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
	m_imagehandle[0] = LoadGraph(PLAY_IMAGE_PATH[0]);	//プレイ背景画像

	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイ通常処理
void Play::StepPlay()
{
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
	DrawRotaGraph(645, 359, 1.01f, 0.0f, m_imagehandle[0], true); //プレイ背景描画

}

//プレイ後処理
void Play::FinPlay()
{

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