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
	RETURN_TITLE_BOTTAN_PATH,		//タイトルに戻るボタン
	OPITON_BOTTAN_PATH,				//オプションボタン
	BOTTAN_FLAME_PATH,		//メニューボタンフレーム
	STAGE_FLAME_PATH,		//ステージ選択フレーム
};



//ステージセレクト初期化
void StageSelect::InitStageSelect()
{
	m_SceneFlag = 0;	//シーンフラグ初期化

	m_MenuBottanFlame = 0;		//メニューボタンフレーム
	m_MenuFlag = false;	//メニューフラグ
	m_MenuBottanFlag = 1;		//メニューボタンのフラグ
	//メニューボタンフレーム座標
	m_MenuBottanFlame_x = 302;
	m_MenuBottanFlame_y = 324;


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
	m_imagehandle[11] = LoadGraph(BOTTAN_IMAGE_PATH[1]);		//ショップボタン画像
	m_imagehandle[12] = LoadGraph(BOTTAN_IMAGE_PATH[6]);		//タイトルに戻るボタン
	m_imagehandle[13] = LoadGraph(BOTTAN_IMAGE_PATH[7]);		//オプションボタン
	m_imagehandle[14] = LoadGraph(BOTTAN_IMAGE_PATH[8]);		//メニューボタンフレーム画像
	m_imagehandle[15] = LoadGraph(BOTTAN_IMAGE_PATH[9]);		//ステージ選択フレーム画像

	//ステージアイコン
	//x座標
	m_StageIcon_x[0] = 300;
	m_StageIcon_x[1] = 500;
	m_StageIcon_x[2] = 700;
	//y座標
	m_StageIcon_y[0] = 350;
	m_StageIcon_y[1] = 550;
	m_StageIcon_y[2] = 350;

	//起動時ステージ１選択している状態
	m_StageFlag = 1;		//ステージフラグ

	//ステージセレクトループへ
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;
}

//ステージセレクト通常処理
void StageSelect::StepStageSelect()
{
	//メニュー画面へ
	//ボタンが押せるかどうか
	//tabキー押されたなら
	if (IsBottanFlag(30, m_MenuBottanFlame))
	{
		if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_MenuFlag == false)
		{
			m_MenuFlag = true;		//メニューフラグをonに
			//メニューを開いた際に初期化
			m_MenuBottanFlag = 1;		//メニューボタンのフラグ
			m_SceneFlag = 1;		//シーンフラグをショップシーンに
			//メニューボタンフレーム座標
			m_MenuBottanFlame_x = 300;
			m_MenuBottanFlame_y = 300;
		}
		else if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_MenuFlag == true)
		{
			//メニューボタンフレーム座標を初期化
			m_MenuBottanFlame_x = 302;
			m_MenuBottanFlame_y = 324;
			m_StageFlag = 1;		//ステージフラグを初期化
			m_SceneFlag = 0;		//シーンフラグをプレイシーンに
			m_MenuFlag = false;		//メニューフラグをoffに
		}
	}

	//ステージ選択横移動処理
	//左
	//シーンがプレイの時
	if (m_SceneFlag == 0)
	{
		if (IsKeyPush(KEY_INPUT_A) == 1)
		{
			//ステージ２を選択しているときボタン１に
			if (m_StageFlag == 2)
			{
				m_MenuBottanFlame_x -= 200;
				m_MenuBottanFlame_y -= 200;
				m_StageFlag = 1;
			}
			//ステージ３を選択しているときにボタン２に
			if (m_StageFlag == 3)
			{
				m_MenuBottanFlame_x -= 200;
				m_MenuBottanFlame_y += 200;
				m_StageFlag = 2;
			}
		}
		//右
		if (IsKeyPush(KEY_INPUT_D) == 1)
		{
			//ステージ２を選択しているときボタン３に
			if (m_StageFlag == 2)
			{
				m_MenuBottanFlame_x += 200;
				m_MenuBottanFlame_y -= 200;
				m_StageFlag = 3;
			}
			//ステージ１を選択しているときボタン２に
			if (m_StageFlag == 1)
			{
				m_MenuBottanFlame_x += 200;
				m_MenuBottanFlame_y += 200;
				m_StageFlag = 2;
			}
		}
	}

	//シーン遷移処理
	if (m_SceneFlag == 0)
	{
		//プレイシーンへの遷移
		//Enterキー押されたなら
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
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

	//ステージ選択フレーム描画
	DrawRotaGraph(m_MenuBottanFlame_x, m_MenuBottanFlame_y, 0.19f, 0.0f, m_imagehandle[15], true);	
	
	//メニュー画面
	if (m_MenuFlag == true)
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
	//else if (m_SceneFlag == 3)
	//{
	//	//オプションシーンINITへ移動
	//	g_CurrentSceneID = SCENE_ID_INIT_OPTION;
	//}
}

//ステージアイコン選択処理
void StageSelect::StageIconSelect()
{

}

//メニュー処理
void StageSelect::Menu()
{
	//透過背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraph(300, 300, 0.6f, 0.0f, m_imagehandle[11], true);	//ショップボタン
	DrawRotaGraph(600, 300, 0.6f, 0.0f, m_imagehandle[12], true);	//タイトルに戻るボタン
	DrawRotaGraph(900, 300, 0.6f, 0.0f, m_imagehandle[13], true);	//タイトルに戻るボタン
	//メニューボタンフレームパス
	DrawRotaGraph(m_MenuBottanFlame_x, m_MenuBottanFlame_y, 0.25f, 0.0f, m_imagehandle[14], true);	
	DrawRotaGraph(1210, 680, 0.65f, 0.0f, m_imagehandle[2], true);	//戻るボタン
	DrawRotaGraph(1240, 710, 0.07f, 0.0f, m_imagehandle[5], true);	//タブボタン描画

	//メニュー選択横移動処理
	//左
	if (IsKeyPush(KEY_INPUT_A) == 1)
	{
		//ボタン２を選択しているときボタン１に
		if (m_MenuBottanFlag == 2)
		{
			m_MenuBottanFlame_x -= 300;
			m_SceneFlag = 1;	//シーンフラグをショップに
			m_MenuBottanFlag = 1;
		}
		//ボタン３を選択しているときにボタン２に
		if (m_MenuBottanFlag == 3)
		{
			m_MenuBottanFlame_x -= 300;
			m_SceneFlag = 2;	//シーンフラグをタイトルに
			m_MenuBottanFlag = 2;
		}
	}

	//右
	if (IsKeyPush(KEY_INPUT_D) == 1)
	{
		//ボタン２を選択しているときボタン３に
		if (m_MenuBottanFlag == 2)
		{
			m_MenuBottanFlame_x += 300;
			m_SceneFlag = 3;	//シーンフラグをオプションに
			m_MenuBottanFlag = 3;
		}
		//ボタン１を選択しているときボタン２に
		if (m_MenuBottanFlag == 1)
		{
			m_MenuBottanFlame_x += 300;
			m_SceneFlag = 2;	//シーンフラグをショップに	
			m_MenuBottanFlag = 2;
		}


	}

	//シーンへの遷移
	//Enterキー押されたなら
	//オプションシーンは今ないため
	if (m_SceneFlag != 3)
	{
		if (IsBottanFlag(60, m_MenuBottanFlame))
		{
			if (IsKeyPush(KEY_INPUT_RETURN))
			{
				//ステージセレクト後処理へ移動
				g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
			}
		}
	}

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