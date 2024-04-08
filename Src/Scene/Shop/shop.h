#pragma once
#include "../Title/title.h"

const int SHOP_IMAGE_NUMBER = 20;	//ショップ画像枚数

#define SHOP_BACK_IMAGE_PATH	"Data/ShopImage/ShopBackImage.png"	//ショップ背景画像パス
#define SHOP_SCROLL_IMAGE_PATH		"Data/ShopImage/ScrollImage.png"	//ショップスクロール画像パス
#define SHOP_PATH				"Data/ShopImage/Shop.png"	//ショップ
//ｈｐアップボタンパス
#define HP_UP_BOTTAN_PATH		"Data/ShopImage/HpUPBottanImage.png"
//攻撃力アップボタンパス
#define ATTACK_POWER_UP_BOTTAN_PATH		"Data/ShopImage/AttackPowerBottanImage.png"
//攻撃スピードアップボタンパス
#define ATTACK_SPEED_UP_BOTTAN_PATH		"Data/ShopImage/AttackIntervalUpBottanImage.png"
//移動速度アップボタンパス
#define MOVE_SPEED_UP_B_PATH			"Data/ShopImage/MoveSpeedUpBottanImage.png"
//お金の量アップボタンパス
#define MONEY_AMMOUNT_UP_BOTTAN_PATH	"Data/ShopImage/MoneyAmmountUpBottanImage.png"
//ボタンフレームパス
#define SHOP_BOTTAN_FLAME_PATH			"Data/ShopImage/BottanFlame.png"
//コインパス
#define KOIN_PATH						"Data/PlayImage/coin.png"

class Shop : public Title
{

private:

	int m_PlayerHp = 0;					//プレイヤーｈｐ増加量を保存する
	int m_PlayerAttackPower = 0;		//プレイヤー攻撃力増加量を保存する
	float m_PlayerAttackInterval = 0;		//プレイヤー攻撃頻度を保存する
	float m_MoveSpeed = 0;				//プレイヤー横移動速度を保存する
	int m_MoneyAmmountUp = 0;			//お金の量がアップ

	int m_BottanFlag = 0;					//ボタン選択フラグ

	//ボタンフレーム座標
	int m_BottanFlame_x = 0;
	int m_BottanFlame_y = 0;

public:

	//ショップ初期化
	void InitShop();

	//ショップロード
	void LoadShop();

	//ショップ通常処理
	void StepShop();

	//ショップ描画処理
	void DrawShop();

	//ショップ後処理
	void FinShop();

	//プレイヤーｈｐ増加量セット
	void SetPlayerHpUp(int Hp);

	//プレイヤーｈｐ増加量ゲット
	int GetPlayerHpUp() { return m_PlayerHp; };

	//プレイヤー攻撃力増加量セット
	void SetPlayerAttackUp(int attack);

	//プレイヤー攻撃力アップ量ゲット
	int GetPlayerAttackUp() { return m_PlayerAttackPower; };

	//プレイヤー攻撃頻度アップ量セット
	void SetPlayerAttackSpeedUp(float attackspeed);

	//プレイヤー攻撃頻度アップ量ゲット
	float GetPlayerAttackSpeedUp() { return m_PlayerAttackInterval; };

	//プレイヤー横移動速度アップ量セット
	void SetPlayerMoveSpeedUp(float movespeed);

	//プレイヤー横移動速度アップ量ゲット
	float GetPlayerMoveSpeedUp() { return m_MoveSpeed; };

	//お金の量アップ量セット
	void SetMoneyAmmountUp(int moneyammount);

	//お金の量アップ量ゲット
	int GetMoneyAmmountUp() { return m_MoneyAmmountUp; };

};
