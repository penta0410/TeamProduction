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

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

//���݂̃V�[��ID(�N�����ŏ��ɕ\�������V�[��)
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

//�N���X�錾
Title m_title;	//�^�C�g��
StageSelect m_stageselect;	//�X�e�[�W�I��
Shop m_shop;		//�V���b�v
Play m_play;    //�v���C
Clear m_clear;	//�N���A
GameOver m_gameover;		//�Q�[���I�[�o�[

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {return -1;}

	// ��ʃT�C�Y��ύX
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//���͐��䏉����
	InitInput();

	//----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���

	//----------------------------------------
	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//�V�X�e���ɏ�����Ԃ�

		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// ���݂̎��Ԃ��A�O��̃t���[�������
		// 1000/60�~���b�i1/60�b�j�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			//���͐���X�e�b�v
			StepInput();

			//�V�[��ID�ɂ���ď����̐U�蕪��
			switch (g_CurrentSceneID)
			{
			case SCENE_ID_INIT_TITLE:
			{
				//�^�C�g��������
				m_title.InitTitle();
			} break;
			case SCENE_ID_LOOP_TITLE:
			{
				//�^�C�g���ʏ폈��
				m_title.StepTitle();
				//�^�C�g���`�揈��
				m_title.DrawTitle();
			} break;
			case SCENE_ID_FIN_TITLE:
			{
				//�^�C�g���㏈��
				m_title.FinTitle();
			} break;
			case SCENE_ID_INIT_STAGE_SELECT:
			{
				//�X�e�[�W�Z���N�g������
				m_stageselect.InitStageSelect();
			} break;
			case SCENE_ID_LOOP_STAGE_SELECT:
			{
				//�X�e�[�W�Z���N�g�ʏ폈��
				m_stageselect.StepStageSelect();
				//�X�e�[�W�Z���N�g�`�揈��
				m_stageselect.DrawStageSelect();
			} break;
			case SCENE_ID_FIN_STAGE_SELECT:
			{
				//�X�e�[�W�Z���N�g�㏈��
				m_stageselect.FinStageSelect();
			} break;
			case SCENE_ID_INIT_SHOP:
			{
				//�V���b�v���[�h
				m_shop.LoadShop();
				//�V���b�v������
				m_shop.InitShop();
			} break;
			case SCENE_ID_LOOP_SHOP:
			{
				//�V���b�v�ʏ폈��
				m_shop.StepShop();
				//�V���b�v�`�揈��
				m_shop.DrawShop();
			} break;
			case SCENE_ID_FIN_SHOP:
			{
				//�V���b�v�㏈��
				m_shop.FinShop();
			} break;
			case SCENE_ID_INIT_PLAY:
			{
				//�v���C������
				m_play.InitPlay();
			} break;
			case SCENE_ID_LOOP_PLAY:
			{
				//�v���C�`�揈��
				m_play.DrawPlay(m_shop.GetPlayerHpUp());
				//�v���C�ʏ폈��
				m_play.StepPlay(m_shop.GetPlayerHpUp());

			} break;
			case SCENE_ID_FIN_PLAY:
			{
				//�v���C�㏈��
				m_play.FinPlay();
			} break;
			case SCENE_ID_INIT_CLEAR:
			{
				//�N���A������
				m_clear.InitClear();
			} break;
			case SCENE_ID_LOOP_CLEAR:
			{
				//�N���A�ʏ폈��
				m_clear.StepClear();
				//�N���A�`�揈��
				m_clear.DrawClear();
			} break;
			case SCENE_ID_FIN_CLEAR:
			{
				//�N���A�㏈��
				m_clear.FinClear();
			} break;
			case SCENE_ID_INIT_GAMEOVER:
			{
				//�Q�[���I�[�o�[������
				m_gameover.InitGameOver();
			} break;
			case SCENE_ID_LOOP_GAMEOVER:
			{
				//�Q�[���I�[�o�[�ʏ폈��
				m_gameover.StepGameOver();
				//�Q�[���I�[�o�[�`�揈��
				m_gameover.DrawGameOver();
			} break;
			case SCENE_ID_FIN_GAMEOVER:
			{
				//�Q�[���I�[�o�[�㏈��
				m_gameover.FinGameOver();
			}

			}//�V�[���U�蕪����switch���I��

			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();

			//���[�v�̏I����
			//�t���b�v�֐�
			ScreenFlip();

		}//�t���[�����[�g��if���I���

	}//���C�����[�v�̏I���

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

