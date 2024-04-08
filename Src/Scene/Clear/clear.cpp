#include "DxLib.h"
#include "clear.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// クリアシーン
//=============================

//ステージクリア画像パス
const char* CLEAR_PATH[CLEAR_IMAGE_NUMBER] =
{
	STAGRE_CLEAR_BACK_PATH,			//ステージクリア画面

};

//クリアロード
void Clear::LoadClear()
{
	m_imagehandle[0] = LoadGraph(CLEAR_PATH[0]);	//クリア画面

}

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

	DrawRotaGraph(640, 360, 1.01f, 0.0f, m_imagehandle[0], true);
	

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
