#include "DxLib.h"
#include "title.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"

//=============================
// タイトルシーン
//=============================

//タイトル初期化
void Title::InitTitle()
{
	//タイトルループへ
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

//タイトル通常処理
void Title::StepTitle()
{
	//ステージセレクトへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//タイトルシーンフラグをステージセレクトシーンに変更
		m_SceneFlag = 0;

		//'プレイ後処理'へ移動
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;

	}

	////オプションシーンへの遷移
	////tab(タブ)キーボタン押されたなら
	//if (IsKeyPush(KEY_INPUT_TAB))
	//{
	//	//タイトルシーンフラグをオプションシーンに変更
	//	m_SceneFlag = 1;
	//	//'プレイ後処理'へ移動
	//	g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	//}

	//透過処理
	m_BottanAlpha = Transparent(m_BottanAlpha);
}

//タイトル描画処理
void Title::DrawTitle()
{
	//スタートボタン描画
	//点滅アニメーション(透過処理)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BottanAlpha);
	DrawRotaGraph(645, 510, 0.15f, 0.0f, m_imagehandle[0], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, m_BottanAlpha);

	//マウス処理
	MouseClick();

	//デバッグ
	DrawFormatString(100, 100, GetColor(255, 255, 255),
		"タイトルシーンです", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255),
		"ステージ選択シーンへはenterを押してください。", true);

}

//タイトル後処理
void Title::FinTitle()
{
	//ステージセレクトINITへ移動
	if (m_SceneFlag == 0)
	{
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}
	////オプションINITへ移動
	//if (m_SceneFlag == 1)
	//{
	//	/*g_CurrentSceneID = SCENE_ID_INIT_OPTION;*/
	//}
}

void Title::MouseClick()
{
	//マウス位置取得
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);

	////オプションシーンへ移動するマウス操作
	////ボタン位置とボタンとの当たり判定
	//if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_bottan_x, m_bottan_y, m_bottan_r) == 1)
	//{
	//	//文字背景
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	//	DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//	//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
	//	SetFontSize(12);
	//	DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<option>\nボタンを左クリックするか\ntab(タブ)キーを押してください");

	//	//文字サイズをもとに
	//	SetFontSize(16);

	//	//左クリックしたとき
	//	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	//	{
	//		//オプションシーンへの遷移
	//		//画面上のオプションボタン押されたなら

	//		//タイトルシーンフラグをオプションシーンに変更
	//		m_TitleSceneFlag = false;

	//		//'タイトル後処理'へ移動
	//		g_CurrentSceneID = SCENE_ID_FIN_TITLE;

	//	}
	//	else
	//	{
	//		//押されていない
	//	}
	//}




}