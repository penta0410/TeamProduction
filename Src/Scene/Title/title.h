#pragma once

const int TITLE_IMAGE_NUMBER = 15;		//画像枚数

#define START_BOTTAN_IMAGE_PATH	"Data/TitleImage/StartBottanImage.png"		//スタートボタン画像パス
#define TITLE_IMAGE_BACK_PATH	"Data/TitleImage/TitleBackGroundImage.png"		//タイトル背景画像パス
#define TITLE_IMAGE_NAME_PATH	"Data/TitleImage/TitleImage.png"		//タイトル名前画像パス

class Title
{
protected:		//ほかのシーンでも使うもの

	//タイトルシーンからの遷移選択フラグ
	int m_SceneFlag = 0;

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標

	int m_Back_x = 0;	//x座標
	int m_Back_y = 0;	//y座標

	//スクロール用
	int m_Back_x_2 = 0;	//x座標
	int m_Back_y_2 = 0;	//y座標

	//背景画像ハンドル
	int m_imagehandle[TITLE_IMAGE_NUMBER] = { 0 };

private:	//タイトルシーンだけで使うもの

	//ボタンアニメーション透過変数
	int m_BottanAlpha = 200;

	//透過フラグ
	bool m_BottanAlphaFlag = true;


public:

	// タイトル初期化
	void InitTitle();

	//タイトル通常処理
	void StepTitle();

	//タイトル描画処理
	void DrawTitle();

	//タイトル後処理
	void FinTitle();

	//マウスクリック処理
	void MouseClick();

};