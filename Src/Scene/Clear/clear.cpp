#include "DxLib.h"
#include "clear.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// クリアシーン
//=============================

//プレイ初期化  
void Clear::InitClear()
{
	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//プレイ通常処理
void Clear::StepClear()
{
	//ステージ選択への遷移
	//ENTERキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_SceneFlag = 0;

		//プレイ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}

}

//プレイ描画処理
void Clear::DrawClear()
{


	//デバッグ
	DrawFormatString(100, 100, GetColor(255, 255, 255),
		"クリアシーンです", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255),
		"ステージセレクトへはenterを押してください", true);

}

//プレイ後処理
void Clear::FinClear()
{
	if (m_SceneFlag == 0)
	{
		//ステージセレクトINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

}
