#pragma once

const int TITLE_IMAGE_NUMBER = 10;		//画像枚数

class Title
{
protected:		//ほかのシーンでも使うもの

	//タイトルシーンからの遷移選択フラグ
	int m_SceneFlag = 0;

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標

	//背景画像ハンドル
	int m_imagehandle[TITLE_IMAGE_NUMBER] = { 0 };

private:	//タイトルシーンだけで使うもの

	//ボタンアニメーション透過変数
	int m_BottanAlpha = 100;

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