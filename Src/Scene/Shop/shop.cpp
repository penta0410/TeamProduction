#include "DxLib.h"
#include "shop.h"
#include "../../Scene/Scene.h"
#include "../../Input/Input.h"
#include "../StageSelect/stageselect.h"


//=============================
// ショップシーン
//=============================

//ステージセレクト画像パス
const char* SHOP_IMAGE_PATH[SHOP_IMAGE_NUMBER] =
{
	SHOP_BACK_IMAGE_PATH,		//ショップ背景
	SHOP_SCROLL_IMAGE_PATH,		//スクロール
	SHOP_PATH,					//ショップ

};

//ショップ初期化
void Shop::InitShop()
{
	m_imagehandle[0] = LoadGraph(SHOP_IMAGE_PATH[0]);	//ショップ背景
	m_imagehandle[1] = LoadGraph(SHOP_IMAGE_PATH[1]);	//スクロール
	m_imagehandle[2] = LoadGraph(SHOP_IMAGE_PATH[2]);	//ショップ
	m_imagehandle[3] = LoadGraph(STAGE_RETURN_BOTTAN_IMAGE_PATH);		//戻るボタン
	m_imagehandle[4] = LoadGraph(TAB_BOTTAN_IMAGE_PATH);		//タブボタン

	//ショップループへ
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//ショップ通常処理
void Shop::StepShop()
{
	//ステージセレクトシーンへの遷移
	//Tabキー押されたなら
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_SceneFlag = 0;
		//ショップ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

}

//ショップ描画処理
void Shop::DrawShop()
{
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_imagehandle[0], true);	//ショップ背景	
	DrawRotaGraph(390, 360, 1.4f, 0.0f, m_imagehandle[1], true);	//スクロール
	DrawRotaGraph(420, 120, 0.35f, 0.0f, m_imagehandle[2], true);	//ショップ
	DrawRotaGraph(1210, 680, 0.65f, 0.0f, m_imagehandle[3], true);	//戻るボタン描画
	DrawRotaGraph(1240, 710, 0.07f, 0.0f, m_imagehandle[4], true);	//タブボタン描画
	m_PlayerHp = 1000000000;
	SetFontSize(30);
	DrawFormatString(450, 190, GetColor(0, 0, 0), "初期HP：%d", m_PlayerHp, true); //

}

//ショップ後処理
void Shop::FinShop()
{
	if (m_SceneFlag == 0)
	{
		//ステージセレクトシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

	

}
