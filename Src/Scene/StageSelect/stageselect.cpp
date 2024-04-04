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
	STAGE_SELECT_BACK_IMAGE_PATH,		//ステージ背景
	STAGE_SELECT_TITLE_IMAGE_PATH,		//ステージセレクト見出し
	STAGE_RETURN_BOTTAN_IMAGE_PATH,		//戻るボタン
	STAGE_SHOP_BOTTAN_IMAGE_PATH,		//ショップボタン
    STAGE_SELECT_MENU_BOTTAN_IMAGE_PATH		//メニューボタン
	STAGE_ICON_IMAGE_PATH,					//ステージアイコン

};

//ボタン画像パス
const char* BOTTAN_IMAGE_PATH[BOTTAN_IMAGE_NUMBER] =
{
	TAB_BOTTAN_IMAGE_PATH,		//タブボタン
	ENTER_BOTTAN_IMAGE_PATH,	//エンターボタン
	LEFT_CLICK_BOTTAN_IMAGE_PATH,	//左クリックボタン

};

//ステージセレクト初期化
void StageSelect::InitStageSelect()
{
	//シーンフラグ初期化
	m_SceneFlag = 0;

	m_imagehandle[0] = LoadGraph(STAGE_SELECT_IMAGE_PATH[0]);	//ステージセレクト背景画像
	m_imagehandle[1] = LoadGraph(STAGE_SELECT_IMAGE_PATH[1]);	//ステージセレクトタイトル画像
	m_imagehandle[2] = LoadGraph(STAGE_SELECT_IMAGE_PATH[2]);	//戻るボタン画像
	m_imagehandle[3] = LoadGraph(STAGE_SELECT_IMAGE_PATH[3]);	//ショップボタン画像
	m_imagehandle[4] = LoadGraph(STAGE_SELECT_IMAGE_PATH[4]);	//メニューボタン画像
	m_imagehandle[5] = LoadGraph(BOTTAN_IMAGE_PATH[0]);			//タブボタン画像
	m_imagehandle[6] = LoadGraph(BOTTAN_IMAGE_PATH[1]);			//エンターボタン画像
	m_imagehandle[7] = LoadGraph(STAGE_SELECT_IMAGE_PATH[5]);	//ステージアイコン画像
 	
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

		//メニュー画面へ
		//tabキー押されたなら
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			
		}

		//タイトルシーンへの遷移
		
		//m_SceneFlag = 2;

		////ステージセレクト後処理へ移動
		//g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	
	}
	
}

//ステージセレクト描画処理
void StageSelect::DrawStageSelect()
{
	
	DrawRotaGraph(645, 359, 1.01f, 0.0f, m_imagehandle[0], true); //ステージセレクト背景描画
	DrawRotaGraph(200, 50, 0.25f, 0.0f, m_imagehandle[1], true);	//ステージセレクトタイトル描画
	
	DrawRotaGraph(1210, 680, 1.1f, 0.0f, m_imagehandle[4], true);	//メニューボタン描画
	DrawRotaGraph(1240, 705, 0.07f, 0.0f, m_imagehandle[5], true);	//タブボタン描画
	
	DrawRotaGraph(300, 300, 0.8f, 0.0f, m_imagehandle[7], true);	//ステージアイコン描画
	
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