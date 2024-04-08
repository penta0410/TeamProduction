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
	SHOP_BACK_IMAGE_PATH,			//ショップ背景
	SHOP_SCROLL_IMAGE_PATH,			//スクロール
	SHOP_PATH,						//ショップ
	HP_UP_BOTTAN_PATH,				//ｈｐアップボタン
	ATTACK_POWER_UP_BOTTAN_PATH,	//攻撃力アップボタン
	ATTACK_SPEED_UP_BOTTAN_PATH,	//攻撃スピードアップボタン
	MOVE_SPEED_UP_B_PATH,			//移動速度アップボタン
	MONEY_AMMOUNT_UP_BOTTAN_PATH,	//お金の量アップボタン
	SHOP_BOTTAN_FLAME_PATH,			//ボタンフレーム
	KOIN_PATH,						//コイン

};

//ショップロード
void Shop::LoadShop()
{
	m_imagehandle[0] = LoadGraph(SHOP_IMAGE_PATH[0]);	//ショップ背景
	m_imagehandle[1] = LoadGraph(SHOP_IMAGE_PATH[1]);	//スクロール
	m_imagehandle[2] = LoadGraph(SHOP_IMAGE_PATH[2]);	//ショップ
	m_imagehandle[3] = LoadGraph(STAGE_RETURN_BOTTAN_IMAGE_PATH);		//戻るボタン
	m_imagehandle[4] = LoadGraph(TAB_BOTTAN_IMAGE_PATH);		//タブボタン
	m_imagehandle[5] = LoadGraph(SHOP_IMAGE_PATH[3]);	//ｈｐアップボタン
	m_imagehandle[6] = LoadGraph(SHOP_IMAGE_PATH[4]);	//攻撃力アップボタン
	m_imagehandle[7] = LoadGraph(SHOP_IMAGE_PATH[5]);	//攻撃スピードアップボタン
	m_imagehandle[8] = LoadGraph(SHOP_IMAGE_PATH[6]);	//移動速度アップボタン
	m_imagehandle[9] = LoadGraph(SHOP_IMAGE_PATH[7]);	//お金の量アップボタン
	m_imagehandle[10] = LoadGraph(SHOP_IMAGE_PATH[8]);	//ボタンフレーム
	m_imagehandle[11] = LoadGraph(SHOP_IMAGE_PATH[9]);	//コイン

}

//ショップ初期化
void Shop::InitShop()
{
	m_BottanFlag = 0;					//ボタン選択フラグ

	//ボタンフレーム座標
	m_BottanFlame_x = 193;
	m_BottanFlame_y = 187;

	//ショップループへ
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//ショップ通常処理
void Shop::StepShop()
{
	//ボタンプッシュ処理
	//エンターキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//ｈｐアップボタンを選択していたら
		if (m_BottanFlag == 0)
		{
			m_PlayerHp += 100;
		}
		//攻撃力アップボタンを選択していたら
		else if (m_BottanFlag == 1)
		{
			m_PlayerAttackPower += 2;
		}
		//攻撃スピードアップボタンを選択していたら
		else if (m_BottanFlag == 2)
		{
			m_PlayerAttackInterval += 0.1;
		}
		//移動速度アップボタンを選択していたら
		else if (m_BottanFlag == 3)
		{
			m_MoveSpeed += 0.1;
		}
		//お金の量アップボタンを選択していたら
		else if (m_BottanFlag == 4)
		{
			m_MoneyAmmountUp += 1;
		}
	}

	//ボタン選択処理
	//上
	if (IsKeyPush(KEY_INPUT_W) == 1)
	{
		//ボタン２を選択しているときボタン１に
		if (m_BottanFlag == 1)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 0;
		}
		//ボタン３を選択しているときにボタン２に
		else if (m_BottanFlag == 2)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 1;
		}
		//ボタン４を選択しているときにボタン３に
		else if (m_BottanFlag == 3)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 2;
		}
		//ボタン５を選択しているときにボタン４に
		else if (m_BottanFlag == 4)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 3;
		}
	}
	//下
	if (IsKeyPush(KEY_INPUT_S) == 1)
	{
		//ボタン２を選択しているときボタン３に
		if (m_BottanFlag == 1)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 2;
		}
		//ボタン１を選択しているときボタン２に
		else if (m_BottanFlag == 0)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 1;
		}
		//ボタン３を選択しているときボタン４に
		else if (m_BottanFlag == 2)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 3;
		}
		//ボタン４を選択しているときボタン５に
		else if (m_BottanFlag == 3)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 4;
		}
	}
	



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
	DrawRotaGraph(195 - 15, 190, 0.2f, 0.0f, m_imagehandle[5], true);	//ｈｐアップボタン描画
	DrawRotaGraph(189 - 15, 280, 0.2f, 0.0f, m_imagehandle[6], true);	//攻撃力アップボタン描画
	DrawRotaGraph(195 - 15, 370, 0.2f, 0.0f, m_imagehandle[7], true);	//攻撃スピードアップボタン描画
	DrawRotaGraph(195 - 15, 460, 0.2f, 0.0f, m_imagehandle[8], true);	//移動速度アップボタン描画
	DrawRotaGraph(195 - 15, 550, 0.2f, 0.0f, m_imagehandle[9], true);	//お金の量アップボタン描画
	//ボタンフレーム描画
	DrawRotaGraph(m_BottanFlame_x - 20, m_BottanFlame_y,
		0.2f, 0.0f,m_imagehandle[10], true);

	int Koin_y = 190;	//コインy座標（描画するために使用）
	SetFontSize(32);
	//コイン描画
	for (int i = 0; i < 5; i++)
	{
		DrawRotaGraph(290, Koin_y, 0.3f, 0.0f, m_imagehandle[11], true);
		DrawFormatString(310, Koin_y - 20, GetColor(0, 0, 0), "ｘ３", true);
		Koin_y += 90;
	}

	
	SetFontSize(36);

	//プレイヤーｈｐアップ量表示
	DrawFormatString(400, 170, GetColor(0, 0, 0), "HPUp量：%d", m_PlayerHp , true); 
	//プレイヤー攻撃力アップ量表示
	DrawFormatString(400, 260, GetColor(0, 0, 0), "ATKUp量：%d", m_PlayerAttackPower, true);
	//攻撃スピードアップ量表示
	DrawFormatString(400, 350, GetColor(0, 0, 0), "ATKSPDUp量：%0.1f", m_PlayerAttackInterval, true);
	//移動速度アップ量表示
	DrawFormatString(400, 440, GetColor(0, 0, 0), "SPDUp量：%0.1f", m_MoveSpeed, true);
	//お金の量アップ量表示
	DrawFormatString(400, 530, GetColor(0, 0, 0), "お金の量Up量：%d", m_MoneyAmmountUp, true);
	
	
	SetFontSize(16);

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

//プレイヤーｈｐ増加量セット処理
void Shop::SetPlayerHpUp(int Hp)
{
	m_PlayerHp += Hp;
}

//プレイヤー攻撃力増加量セット
void Shop::SetPlayerAttackUp(int attack)
{
	m_PlayerAttackPower += attack;
}

//プレイヤー攻撃頻度アップ量セット
void Shop::SetPlayerAttackSpeedUp(float attackspeed)
{
	m_PlayerAttackInterval += attackspeed;
}

//プレイヤー横移動速度アップ量セット
void Shop::SetPlayerMoveSpeedUp(float movespeed)
{
	m_MoveSpeed += movespeed;
}

//お金の量アップ量セット
void Shop::SetMoneyAmmountUp(int moneyammount)
{
	m_MoneyAmmountUp += moneyammount;
}




