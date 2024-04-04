#include "DxLib.h"
#include "stageselect.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"
#include "../Scene.h"
#include "../../Common.h"

//=============================
// ステージセレクトシーン
//=============================

//ステージセレクト画像パス
const char* STAGE_SELECT_IMAGE_PATH[STAGE_SELECT_IMAGE_NUMBER] =
{
	STAGE_SELECT_BACK_IMAGE_PATH,		//ステージ背景
	STAGE_SELECT_TITLE_IMAGE_PATH,		//ステージセレクト見出し
	STAGE_ICON_IMAGE_PATH,					//ステージアイコン
	STAGE1_PATH,				
    STAGE2_PATH,		
	STAGE3_PATH,

};

//ボタン画像パス
const char* BOTTAN_IMAGE_PATH[BOTTAN_IMAGE_NUMBER] =
{
	STAGE_RETURN_BOTTAN_IMAGE_PATH,		//戻るボタン
	STAGE_SHOP_BOTTAN_IMAGE_PATH,		//ショップボタン
	STAGE_SELECT_MENU_BOTTAN_IMAGE_PATH,		//メニューボタン
	TAB_BOTTAN_IMAGE_PATH,		//タブボタン
	ENTER_BOTTAN_IMAGE_PATH,	//エンターボタン
	LEFT_CLICK_BOTTAN_IMAGE_PATH,	//左クリックボタン

};



//ステージセレクト初期化
void StageSelect::InitStageSelect()
{
	m_SceneFlag = 0;	//シーンフラグ初期化
	m_Menu_Bottan_Flame = 0;		//メニューボタンフレーム
	m_Menu_Flag = false;	//メニューフラグ

	m_imagehandle[0] = LoadGraph(STAGE_SELECT_IMAGE_PATH[0]);	//ステージセレクト背景画像
	m_imagehandle[1] = LoadGraph(STAGE_SELECT_IMAGE_PATH[1]);	//ステージセレクトタイトル画像
	m_imagehandle[2] = LoadGraph(BOTTAN_IMAGE_PATH[0]);			//戻るボタン画像
	m_imagehandle[3] = LoadGraph(BOTTAN_IMAGE_PATH[1]);			//ショップボタン画像
	m_imagehandle[4] = LoadGraph(BOTTAN_IMAGE_PATH[2]);			//メニューボタン画像
	m_imagehandle[5] = LoadGraph(BOTTAN_IMAGE_PATH[3]);			//タブボタン画像
	m_imagehandle[6] = LoadGraph(BOTTAN_IMAGE_PATH[4]);			//エンターボタン画像
	m_imagehandle[7] = LoadGraph(STAGE_SELECT_IMAGE_PATH[2]);	//ステージアイコン画像
	m_imagehandle[8] = LoadGraph(STAGE_SELECT_IMAGE_PATH[3]);	//ステージ名1
	m_imagehandle[9] = LoadGraph(STAGE_SELECT_IMAGE_PATH[4]);	//ステージ名2
	m_imagehandle[10] = LoadGraph(STAGE_SELECT_IMAGE_PATH[5]);	//ステージ名3

	//ステージアイコン
	//x座標
	m_StageIcon_x[0] = 300;
	m_StageIcon_x[1] = 500;
	m_StageIcon_x[2] = 700;
	//y座標
	m_StageIcon_y[0] = 350;
	m_StageIcon_y[1] = 550;
	m_StageIcon_y[2] = 350;


	//ステージセレクトループへ
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;
}

//ステージセレクト通常処理
void StageSelect::StepStageSelect()
{
	//メニュー画面へ
	//ボタンが押せるかどうか
	//tabキー押されたなら
	if (IsBottanFlag(30, m_Menu_Bottan_Flame))
	{
		if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_Menu_Flag == false)
		{
			m_Menu_Flag = true;		//メニューフラグをonに
		}
		else if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_Menu_Flag == true)
		{
			m_Menu_Flag = false;		//メニューフラグをoffに
		}
	}

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
	DrawRotaGraph(1240, 710, 0.07f, 0.0f, m_imagehandle[5], true);	//タブボタン描画
	
	//ステージアイコン描画
	for (int i = 0; i < STAGE_NUM; i++)
	{
		//ステージアイコン
		DrawRotaGraph(m_StageIcon_x[i], m_StageIcon_y[i], 0.2f, 0.0f, m_imagehandle[7], true);
		//ステージ名
		DrawRotaGraph(m_StageIcon_x[i] + 20, m_StageIcon_y[i] - 30, 0.4f, 0.0f, m_imagehandle[i + 8], true);
	
	}
	

	//メニュー画面
	if (m_Menu_Flag == true)
	{
		Menu();		//メニュー処理
	}

}

//ステージセレクト後処理
void StageSelect::FinStageSelect()
{
	if (m_SceneFlag == 0)
	{
		//プレイシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
	else if (m_SceneFlag == 1)
	{
		//ショップシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_SHOP;
	}
	else if (m_SceneFlag == 2)
	{
		//タイトルシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}

}

//ステージアイコン選択処理
void StageSelect::StageIconSelect()
{

}

//メニュー処理
void StageSelect::Menu()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
	DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	

}

//ボタンが押せるかどうか
bool StageSelect::IsBottanFlag(int seconds, int Flame)
{
	//フレームインクリメント
	Flame++;

	//0.5秒たったら
	if(Flame >= seconds)
	{
		//押せる場合trueを返す
		return true;
	}
}