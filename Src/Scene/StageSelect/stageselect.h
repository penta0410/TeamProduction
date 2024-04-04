#pragma once
#include "../../Scene/Scene.h"
#include "../../Scene/Title/title.h"

const int STAGE_SELECT_IMAGE_NUMBER = 10; //ステージセレクト画像枚数

const int BOTTAN_IMAGE_NUMBER = 5;		//ボタン画像枚数

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

//タブボタンパス
#define TAB_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/TabkeyBottanImage.png"
//エンターボタンパス
#define ENTER_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/EnterKeyBottanImage.png"
//左クリックボタンパス
#define LEFT_CLICK_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/LeftClickBottanImage.png"

class StageSelect : public Title
{
private:

	

public:

	//ステージセレクト初期化
	void InitStageSelect();

	//ステージセレクト通常処理
	void StepStageSelect();

	//ステージセレクト描画処理
	void DrawStageSelect();

	//ステージセレクト後処理
	void FinStageSelect();
};
