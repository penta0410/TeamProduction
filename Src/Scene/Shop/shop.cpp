#include "DxLib.h"
#include "shop.h"
#include "../../Scene/Scene.h"
#include "../../Input/Input.h"

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

	//ショップループへ
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//ショップ通常処理
void Shop::StepShop()
{

	//ステージセレクトシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_SceneFlag = 0;

		//ショップ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

	////シーンへの遷移
	////Tabキー押されたなら
	//if (IsKeyPush(KEY_INPUT_TAB))
	//{
	//	m_SceneFlag = 1;
	//	//ショップ後処理へ移動
	//	g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	//}

}

//ショップ描画処理
void Shop::DrawShop()
{
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_imagehandle[0], true);	//ショップ背景	
	DrawRotaGraph(390, 360, 1.4f, 0.0f, m_imagehandle[1], true);	//スクロール
	DrawRotaGraph(420, 120, 0.35f, 0.0f, m_imagehandle[2], true);	//ショップ

}

//ショップ後処理
void Shop::FinShop()
{
	if (m_SceneFlag == 0)
	{
		//ステージセレクトシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

	/*if (m_SceneFlag == 1)
	{
		
	}*/

}
