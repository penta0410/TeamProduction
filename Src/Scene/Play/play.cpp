#include <math.h>
#include "DxLib.h"
#include "play.h"
#include "../Scene.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Common.h"

//=============================
// プレイシーン
//=============================

Play::Play() {}		//コンストラクタ
Play::~Play() {}	//デストラクタ

//プレイ初期化  
void Play::InitPlay()
{
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
	//デバッグ
	DrawFormatString(100, 100, GetColor(255, 255, 255), "プレイシーンです", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "クリアシーンへはenter", true);
	DrawFormatString(100, 300, GetColor(255, 255, 255), "ゲームオーバーシーンへはtab", true);

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