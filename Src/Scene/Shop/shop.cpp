#include "DxLib.h"
#include "shop.h"
#include "../../Scene/Scene.h"
#include "../../Input/Input.h"

//=============================
// ショップシーン
//=============================

//ショップ初期化
void Shop::InitShop()
{
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
	//ショップ背景	
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_imagehandle[0], true);

	//デバッグ
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ショップシーンです", true);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "ステージセレクトに戻るにはenterを押してください。", true);

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
