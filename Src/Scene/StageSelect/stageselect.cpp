#include "DxLib.h"
#include "stageselect.h"
#include "../../Input/Input.h"

//=============================
// ステージセレクトシーン
//=============================

//ステージセレクト初期化
void Stage_Select::InitStageSelect()
{
	//ステージセレクトループへ
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;

	//ステージセレクトシーンフラグ
	m_SceneFlag = 0;

}

//ステージセレクト通常処理
void Stage_Select::StepStageSelect()
{
	//ステージセレクト処理
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

	}
}

//ステージセレクト描画処理
void Stage_Select::DrawStageSelect()
{
	//ステージセレクト画面描画
	DrawGraph(0, 0, m_imagehandle[0], true);

	//デバッグ
	DrawFormatString(100, 100, GetColor(0, 0, 0), 
		"ステージ選択画面です", true);

}

//ステージセレクト後処理
void Stage_Select::FinStageSelect()
{
	if (m_SceneFlag == 0)
	{
		//プレイシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}