#include "DxLib.h"
#include "stageselect.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"
#include "../Scene.h"

//=============================
// ステージセレクトシーン
//=============================

//ステージセレクト画像パス
const char* STAGE_SELECT_IMAGE_PATH[STAGE_SELECT_IMAGE_NUMBER] =
{
	STAGE_SELECT_BACK_IMAGE_PATH,
	STAGE_SELECT_TITLE_IMAGE_PATH,

};

//ステージセレクト初期化
void StageSelect::InitStageSelect()
{
	//シーンフラグ初期化
	m_SceneFlag = 0;

	m_imagehandle[0] = LoadGraph(STAGE_SELECT_IMAGE_PATH[0]);	//ステージセレクト背景画像
	m_imagehandle[1] = LoadGraph(STAGE_SELECT_IMAGE_PATH[1]);	//ステージセレクトタイトル画像
	
	//ステージセレクトループへ
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;

}

//ステージセレクト通常処理
void StageSelect::StepStageSelect()
{
	//シーン遷移処理
	if (m_SceneFlag == 0)
	{
		//プレイシーンへの遷移
		//Enterキー押されたなら
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
			m_SceneFlag = 0;

			//ステージセレクト後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}

		//プレイシーンへの遷移
		//tabキー押されたなら
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			m_SceneFlag = 1;

			//ステージセレクト後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}

		//タイトルシーンへの遷移
		//左コントロールキー押されたなら
		if (IsKeyPush(KEY_INPUT_LCONTROL))
		{
			m_SceneFlag = 2;

			//ステージセレクト後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}
	}
	
}

//ステージセレクト描画処理
void StageSelect::DrawStageSelect()
{
	
	DrawRotaGraph(645, 359, 1.01f, 0.0f, m_imagehandle[0], true); //ステージセレクト背景描画
	DrawRotaGraph(200, 50, 0.25f, 0.0f, m_imagehandle[1], true);	//ステージセレクトタイトル描画
	
	//デバッグ
	/*DrawFormatString(100, 100, GetColor(255, 255, 255), 
		"ステージセレクトシーンです。", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255),
		"プレイシーンへはenterを押してください。", true);
	DrawFormatString(100, 300, GetColor(255, 255, 255),
		"ショップシーンへはtabを押してください。", true);
	DrawFormatString(100, 400, GetColor(255, 255, 255),
		"タイトルシーンへは左ctrlを押してください。", true);*/

}

//ステージセレクト後処理
void StageSelect::FinStageSelect()
{
	if (m_SceneFlag == 0)
	{
		//プレイシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}

	if (m_SceneFlag == 1)
	{
		//ショップシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_SHOP;
	}

	if (m_SceneFlag == 2)
	{
		//タイトルシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}

}