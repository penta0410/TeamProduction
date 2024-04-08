#include "DxLib.h"
#include "gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// ゲームオーバーシーン
//=============================
//
//GAME_OVER_BACK_PATH

//ゲームオーバー初期化
void GameOver::InitGameOver()
{
	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//ゲームオーバー通常処理
void GameOver::StepGameOver()
{
	//ENTERキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//ステージ選択シーンへ
		m_SceneFlag = 0;

		//プレイ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}

}

//ゲームオーバー描画処理
void GameOver::DrawGameOver()
{
	
	//デバッグ
	DrawFormatString(0, 30, GetColor(255, 255, 255),
		"ゲームオーバーシーンです。", true);
	DrawFormatString(0, 130, GetColor(255, 255, 255), 
		"ステージセレクトにはエンターを押してください", true);

}

//ゲームオーバー後処理
void GameOver::FinGameOver()
{
	if (m_SceneFlag == 0)
	{
		//ステージセレクトINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}
}
