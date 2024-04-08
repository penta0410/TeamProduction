#include "DxLib.h"
#include "gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// ゲームオーバーシーン
//=============================


//ステージセレクト画像パス
const char* GAME_OVER_IMAGE_PATH[GAME_OVER_IMAGE_NUMBER] =
{
	GAME_OVER_BACK_PATH,			//ゲームオーバー画面

};

//ゲームオーバー初期化
void GameOver::InitGameOver()
{
	m_imagehandle[0] = LoadGraph(GAME_OVER_IMAGE_PATH[0]);

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
	//ゲームオーバー背景描画
	DrawRotaGraph(640, 360, 01.0f, 0.0f, m_imagehandle[0], true);

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
