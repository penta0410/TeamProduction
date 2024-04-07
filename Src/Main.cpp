#include "DxLib.h"
#include "Scene/Scene.h"
#include "../Src/Scene/Title/title.h"
#include "../Src/Scene/StageSelect/stageselect.h"
#include "../Src/Scene/Shop/shop.h"
#include "../Src/Scene/Play/play.h"
#include "../Src/Scene/Clear/clear.h"
#include "../Src/Scene/GameOver/gameover.h"
#include "Collision/Collision.h"
#include "Input/Input.h"
#include "Common.h"
#include "FPS/fps.h"

//フレームレート情報変数
FrameRateInfo frameRateInfo;

//現在のシーンID(起動時最初に表示されるシーン)
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

//クラス宣言
Title m_title;	//タイトル
StageSelect m_stageselect;	//ステージ選択
Shop m_shop;		//ショップ
Play m_play;    //プレイ
Clear m_clear;	//クリア
GameOver m_gameover;		//ゲームオーバー

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {return -1;}

	// 画面サイズを変更
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//入力制御初期化
	InitInput();

	//----------------------------------------
	//一番最初に１回だけやる処理をここに書く

	//----------------------------------------
	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//システムに処理を返す

		//現在の時間を取得
		frameRateInfo.currentTime = GetNowCount();

		//最初のループなら
		//現在の時間を、FPSの計算をした時間に設定
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// 現在の時間が、前回のフレーム時より
		// 1000/60ミリ秒（1/60秒）以上経過していたら処理を実行する
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//フレーム数をカウント
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//エスケープキーが押されたら終了
				break;
			}

			//画面に表示されたものを初期化
			ClearDrawScreen();

			//入力制御ステップ
			StepInput();

			//シーンIDによって処理の振り分け
			switch (g_CurrentSceneID)
			{
			case SCENE_ID_INIT_TITLE:
			{
				//タイトル初期化
				m_title.InitTitle();
			} break;
			case SCENE_ID_LOOP_TITLE:
			{
				//タイトル通常処理
				m_title.StepTitle();
				//タイトル描画処理
				m_title.DrawTitle();
			} break;
			case SCENE_ID_FIN_TITLE:
			{
				//タイトル後処理
				m_title.FinTitle();
			} break;
			case SCENE_ID_INIT_STAGE_SELECT:
			{
				//ステージセレクト初期化
				m_stageselect.InitStageSelect();
			} break;
			case SCENE_ID_LOOP_STAGE_SELECT:
			{
				//ステージセレクト通常処理
				m_stageselect.StepStageSelect();
				//ステージセレクト描画処理
				m_stageselect.DrawStageSelect();
			} break;
			case SCENE_ID_FIN_STAGE_SELECT:
			{
				//ステージセレクト後処理
				m_stageselect.FinStageSelect();
			} break;
			case SCENE_ID_INIT_SHOP:
			{
				//ショップロード
				m_shop.LoadShop();
				//ショップ初期化
				m_shop.InitShop();
			} break;
			case SCENE_ID_LOOP_SHOP:
			{
				//ショップ通常処理
				m_shop.StepShop();
				//ショップ描画処理
				m_shop.DrawShop();
			} break;
			case SCENE_ID_FIN_SHOP:
			{
				//ショップ後処理
				m_shop.FinShop();
			} break;
			case SCENE_ID_INIT_PLAY:
			{
				//プレイ初期化
				m_play.InitPlay();
			} break;
			case SCENE_ID_LOOP_PLAY:
			{
				//プレイ描画処理
				m_play.DrawPlay(m_shop.GetPlayerHpUp());
				//プレイ通常処理
				m_play.StepPlay(m_shop.GetPlayerHpUp());

			} break;
			case SCENE_ID_FIN_PLAY:
			{
				//プレイ後処理
				m_play.FinPlay();
			} break;
			case SCENE_ID_INIT_CLEAR:
			{
				//クリア初期化
				m_clear.InitClear();
			} break;
			case SCENE_ID_LOOP_CLEAR:
			{
				//クリア通常処理
				m_clear.StepClear();
				//クリア描画処理
				m_clear.DrawClear();
			} break;
			case SCENE_ID_FIN_CLEAR:
			{
				//クリア後処理
				m_clear.FinClear();
			} break;
			case SCENE_ID_INIT_GAMEOVER:
			{
				//ゲームオーバー初期化
				m_gameover.InitGameOver();
			} break;
			case SCENE_ID_LOOP_GAMEOVER:
			{
				//ゲームオーバー通常処理
				m_gameover.StepGameOver();
				//ゲームオーバー描画処理
				m_gameover.DrawGameOver();
			} break;
			case SCENE_ID_FIN_GAMEOVER:
			{
				//ゲームオーバー後処理
				m_gameover.FinGameOver();
			}

			}//シーン振り分けのswitch分終了

			//FPS計算
			CalcFPS();

			//FPS表示
			DrawFPS();

			//ループの終わりに
			//フリップ関数
			ScreenFlip();

		}//フレームレートのif分終わり

	}//メインループの終わり

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

