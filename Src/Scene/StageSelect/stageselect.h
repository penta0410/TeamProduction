#pragma once
#include "../../Scene/Scene.h"
#include "../../Scene/Title/title.h"

const int STAGE_SELECT_IMAGE_NUMBER = 20; //ステージセレクト画像枚数

const int BOTTAN_IMAGE_NUMBER = 10;		//ボタン画像枚数

const int STAGE_NUM = 3;		//ステージ数

//ステージセレクト背景パス
#define STAGE_SELECT_BACK_IMAGE_PATH	"Data/StageSelectImage/StageSelectBackImage.png"	
//ステージセレクトタイトルパス
#define STAGE_SELECT_TITLE_IMAGE_PATH	"Data/StageSelectImage/StageSelectTitleImage.png"	
//戻るボタンパス
#define STAGE_RETURN_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/ReturnBottanImage.png"			
//ショップボタンパス
#define STAGE_SHOP_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/ShopBottanImage.png"
//メニューボタンパス
#define STAGE_SELECT_MENU_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/MenuBottanImage.png"
//ステージアイコンパス
#define STAGE_ICON_IMAGE_PATH		"Data/StageSelectImage/StageIconImage.png"
//ステージ１パス
#define STAGE1_PATH		"Data/StageSelectImage/STAGE1.png"
//ステージ2パス
#define STAGE2_PATH		"Data/StageSelectImage/STAGE2.png"
//ステージ3パス
#define STAGE3_PATH		"Data/StageSelectImage/STAGE3.png"
//フレームパス
#define Flame_PATH		"Data/StageSelectImage/Flame.png"

//タブボタンパス
#define TAB_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/TabkeyBottanImage.png"
//エンターボタンパス
#define ENTER_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/EnterKeyBottanImage.png"
//左クリックボタンパス
#define LEFT_CLICK_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/LeftClickBottanImage.png"
//タイトルに戻るボタンパス
#define RETURN_TITLE_BOTTAN_PATH		"Data/StageSelectImage/returntitleBottan.png"
//オプションボタンパス
#define OPITON_BOTTAN_PATH				"Data/StageSelectImage/OptionBottanImage.png" 

//ステージ選択フレームパス
#define STAGE_FLAME_PATH		"Data/StageSelectImage/Flame.png"
//メニューボタンフレームパス
#define BOTTAN_FLAME_PATH		"Data/StageSelectImage/MenuBottanFlame.png"

class StageSelect : public Title
{
private:
	
	//ステージアイコン座標
	int m_StageIcon_x[STAGE_NUM] = { 0 };
	int m_StageIcon_y[STAGE_NUM] = { 0 };
	int m_StageFlag = 0;			//ステージフラグ
	int m_MenuBottanFlame = 0;		//メニューボタンフレーム
	bool m_MenuFlag = false;	//メニューフラグ
	
	int m_MenuBottanFlag = 0;		//メニューボタンのフラグ

	//メニューボタンフレーム座標
	int m_MenuBottanFlame_x = 0;		
	int m_MenuBottanFlame_y = 0;

public:

	//ステージセレクト初期化
	void InitStageSelect();

	//ステージセレクト通常処理
	void StepStageSelect();

	//ステージセレクト描画処理
	void DrawStageSelect();

	//ステージセレクト後処理
	void FinStageSelect();

	//ステージアイコン選択処理
	void StageIconSelect();

	//メニュー処理
	void Menu();
	
	//ボタンが押せるかどうか
	//引数１ 　ボタン間隔指定
	//引数２	フレーム変数指定
	bool IsBottanFlag(int sconds, int Flame);

};
