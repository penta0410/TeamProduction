#include "DxLib.h"
#include "stageselect.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"
#include "../Scene.h"
#include "../../Common.h"

//=============================
// �X�e�[�W�Z���N�g�V�[��
//=============================

//�X�e�[�W�Z���N�g�摜�p�X
const char* STAGE_SELECT_IMAGE_PATH[STAGE_SELECT_IMAGE_NUMBER] =
{
	STAGE_SELECT_BACK_IMAGE_PATH,		//�X�e�[�W�w�i
	STAGE_SELECT_TITLE_IMAGE_PATH,		//�X�e�[�W�Z���N�g���o��
	STAGE_ICON_IMAGE_PATH,					//�X�e�[�W�A�C�R��
	STAGE1_PATH,				
    STAGE2_PATH,		
	STAGE3_PATH,
	
};

//�{�^���摜�p�X
const char* BOTTAN_IMAGE_PATH[BOTTAN_IMAGE_NUMBER] =
{
	STAGE_RETURN_BOTTAN_IMAGE_PATH,		//�߂�{�^��
	STAGE_SHOP_BOTTAN_IMAGE_PATH,		//�V���b�v�{�^��
	STAGE_SELECT_MENU_BOTTAN_IMAGE_PATH,		//���j���[�{�^��
	TAB_BOTTAN_IMAGE_PATH,		//�^�u�{�^��
	ENTER_BOTTAN_IMAGE_PATH,	//�G���^�[�{�^��
	LEFT_CLICK_BOTTAN_IMAGE_PATH,	//���N���b�N�{�^��
	RETURN_TITLE_BOTTAN_PATH,		//�^�C�g���ɖ߂�{�^��
	OPITON_BOTTAN_PATH,				//�I�v�V�����{�^��
	BOTTAN_FLAME_PATH,		//���j���[�{�^���t���[��
	STAGE_FLAME_PATH,		//�X�e�[�W�I���t���[��
};



//�X�e�[�W�Z���N�g������
void StageSelect::InitStageSelect()
{
	m_SceneFlag = 0;	//�V�[���t���O������

	m_MenuBottanFlame = 0;		//���j���[�{�^���t���[��
	m_MenuFlag = false;	//���j���[�t���O
	m_MenuBottanFlag = 1;		//���j���[�{�^���̃t���O
	//���j���[�{�^���t���[�����W
	m_MenuBottanFlame_x = 302;
	m_MenuBottanFlame_y = 324;


	m_imagehandle[0] = LoadGraph(STAGE_SELECT_IMAGE_PATH[0]);	//�X�e�[�W�Z���N�g�w�i�摜
	m_imagehandle[1] = LoadGraph(STAGE_SELECT_IMAGE_PATH[1]);	//�X�e�[�W�Z���N�g�^�C�g���摜
	m_imagehandle[2] = LoadGraph(BOTTAN_IMAGE_PATH[0]);			//�߂�{�^���摜
	m_imagehandle[3] = LoadGraph(BOTTAN_IMAGE_PATH[1]);			//�V���b�v�{�^���摜
	m_imagehandle[4] = LoadGraph(BOTTAN_IMAGE_PATH[2]);			//���j���[�{�^���摜
	m_imagehandle[5] = LoadGraph(BOTTAN_IMAGE_PATH[3]);			//�^�u�{�^���摜
	m_imagehandle[6] = LoadGraph(BOTTAN_IMAGE_PATH[4]);			//�G���^�[�{�^���摜
	m_imagehandle[7] = LoadGraph(STAGE_SELECT_IMAGE_PATH[2]);	//�X�e�[�W�A�C�R���摜
	m_imagehandle[8] = LoadGraph(STAGE_SELECT_IMAGE_PATH[3]);	//�X�e�[�W��1
	m_imagehandle[9] = LoadGraph(STAGE_SELECT_IMAGE_PATH[4]);	//�X�e�[�W��2
	m_imagehandle[10] = LoadGraph(STAGE_SELECT_IMAGE_PATH[5]);	//�X�e�[�W��3
	m_imagehandle[11] = LoadGraph(BOTTAN_IMAGE_PATH[1]);		//�V���b�v�{�^���摜
	m_imagehandle[12] = LoadGraph(BOTTAN_IMAGE_PATH[6]);		//�^�C�g���ɖ߂�{�^��
	m_imagehandle[13] = LoadGraph(BOTTAN_IMAGE_PATH[7]);		//�I�v�V�����{�^��
	m_imagehandle[14] = LoadGraph(BOTTAN_IMAGE_PATH[8]);		//���j���[�{�^���t���[���摜
	m_imagehandle[15] = LoadGraph(BOTTAN_IMAGE_PATH[9]);		//�X�e�[�W�I���t���[���摜

	//�X�e�[�W�A�C�R��
	//x���W
	m_StageIcon_x[0] = 300;
	m_StageIcon_x[1] = 500;
	m_StageIcon_x[2] = 700;
	//y���W
	m_StageIcon_y[0] = 350;
	m_StageIcon_y[1] = 550;
	m_StageIcon_y[2] = 350;

	//�N�����X�e�[�W�P�I�����Ă�����
	m_StageFlag = 1;		//�X�e�[�W�t���O

	//�X�e�[�W�Z���N�g���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;
}

//�X�e�[�W�Z���N�g�ʏ폈��
void StageSelect::StepStageSelect()
{
	//���j���[��ʂ�
	//�{�^���������邩�ǂ���
	//tab�L�[�����ꂽ�Ȃ�
	if (IsBottanFlag(30, m_MenuBottanFlame))
	{
		if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_MenuFlag == false)
		{
			m_MenuFlag = true;		//���j���[�t���O��on��
			//���j���[���J�����ۂɏ�����
			m_MenuBottanFlag = 1;		//���j���[�{�^���̃t���O
			m_SceneFlag = 1;		//�V�[���t���O���V���b�v�V�[����
			//���j���[�{�^���t���[�����W
			m_MenuBottanFlame_x = 300;
			m_MenuBottanFlame_y = 300;
		}
		else if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_MenuFlag == true)
		{
			//���j���[�{�^���t���[�����W��������
			m_MenuBottanFlame_x = 302;
			m_MenuBottanFlame_y = 324;
			m_StageFlag = 1;		//�X�e�[�W�t���O��������
			m_SceneFlag = 0;		//�V�[���t���O���v���C�V�[����
			m_MenuFlag = false;		//���j���[�t���O��off��
		}
	}

	//�X�e�[�W�I�����ړ�����
	//��
	//�V�[�����v���C�̎�
	if (m_SceneFlag == 0)
	{
		if (IsKeyPush(KEY_INPUT_A) == 1)
		{
			//�X�e�[�W�Q��I�����Ă���Ƃ��{�^���P��
			if (m_StageFlag == 2)
			{
				m_MenuBottanFlame_x -= 200;
				m_MenuBottanFlame_y -= 200;
				m_StageFlag = 1;
			}
			//�X�e�[�W�R��I�����Ă���Ƃ��Ƀ{�^���Q��
			if (m_StageFlag == 3)
			{
				m_MenuBottanFlame_x -= 200;
				m_MenuBottanFlame_y += 200;
				m_StageFlag = 2;
			}
		}
		//�E
		if (IsKeyPush(KEY_INPUT_D) == 1)
		{
			//�X�e�[�W�Q��I�����Ă���Ƃ��{�^���R��
			if (m_StageFlag == 2)
			{
				m_MenuBottanFlame_x += 200;
				m_MenuBottanFlame_y -= 200;
				m_StageFlag = 3;
			}
			//�X�e�[�W�P��I�����Ă���Ƃ��{�^���Q��
			if (m_StageFlag == 1)
			{
				m_MenuBottanFlame_x += 200;
				m_MenuBottanFlame_y += 200;
				m_StageFlag = 2;
			}
		}
	}

	//�V�[���J�ڏ���
	if (m_SceneFlag == 0)
	{
		//�v���C�V�[���ւ̑J��
		//Enter�L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
			//�X�e�[�W�Z���N�g�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}
	}
	
}

//�X�e�[�W�Z���N�g�`�揈��
void StageSelect::DrawStageSelect()
{
	DrawRotaGraph(645, 359, 1.01f, 0.0f, m_imagehandle[0], true); //�X�e�[�W�Z���N�g�w�i�`��
	DrawRotaGraph(200, 50, 0.25f, 0.0f, m_imagehandle[1], true);	//�X�e�[�W�Z���N�g�^�C�g���`��
	
	DrawRotaGraph(1210, 680, 1.1f, 0.0f, m_imagehandle[4], true);	//���j���[�{�^���`��
	DrawRotaGraph(1240, 710, 0.07f, 0.0f, m_imagehandle[5], true);	//�^�u�{�^���`��
	
	//�X�e�[�W�A�C�R���`��
	for (int i = 0; i < STAGE_NUM; i++)
	{
		//�X�e�[�W�A�C�R��
		DrawRotaGraph(m_StageIcon_x[i], m_StageIcon_y[i], 0.2f, 0.0f, m_imagehandle[7], true);
		//�X�e�[�W��
		DrawRotaGraph(m_StageIcon_x[i] + 20, m_StageIcon_y[i] - 30, 0.4f, 0.0f, m_imagehandle[i + 8], true);
	
	}

	//�X�e�[�W�I���t���[���`��
	DrawRotaGraph(m_MenuBottanFlame_x, m_MenuBottanFlame_y, 0.19f, 0.0f, m_imagehandle[15], true);	
	
	//���j���[���
	if (m_MenuFlag == true)
	{
		Menu();		//���j���[����
	}

}

//�X�e�[�W�Z���N�g�㏈��
void StageSelect::FinStageSelect()
{
	if (m_SceneFlag == 0)
	{
		//�v���C�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
	else if (m_SceneFlag == 1)
	{
		//�V���b�v�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_SHOP;
	}
	else if (m_SceneFlag == 2)
	{
		//�^�C�g���V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
	//else if (m_SceneFlag == 3)
	//{
	//	//�I�v�V�����V�[��INIT�ֈړ�
	//	g_CurrentSceneID = SCENE_ID_INIT_OPTION;
	//}
}

//�X�e�[�W�A�C�R���I������
void StageSelect::StageIconSelect()
{

}

//���j���[����
void StageSelect::Menu()
{
	//���ߔw�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraph(300, 300, 0.6f, 0.0f, m_imagehandle[11], true);	//�V���b�v�{�^��
	DrawRotaGraph(600, 300, 0.6f, 0.0f, m_imagehandle[12], true);	//�^�C�g���ɖ߂�{�^��
	DrawRotaGraph(900, 300, 0.6f, 0.0f, m_imagehandle[13], true);	//�^�C�g���ɖ߂�{�^��
	//���j���[�{�^���t���[���p�X
	DrawRotaGraph(m_MenuBottanFlame_x, m_MenuBottanFlame_y, 0.25f, 0.0f, m_imagehandle[14], true);	
	DrawRotaGraph(1210, 680, 0.65f, 0.0f, m_imagehandle[2], true);	//�߂�{�^��
	DrawRotaGraph(1240, 710, 0.07f, 0.0f, m_imagehandle[5], true);	//�^�u�{�^���`��

	//���j���[�I�����ړ�����
	//��
	if (IsKeyPush(KEY_INPUT_A) == 1)
	{
		//�{�^���Q��I�����Ă���Ƃ��{�^���P��
		if (m_MenuBottanFlag == 2)
		{
			m_MenuBottanFlame_x -= 300;
			m_SceneFlag = 1;	//�V�[���t���O���V���b�v��
			m_MenuBottanFlag = 1;
		}
		//�{�^���R��I�����Ă���Ƃ��Ƀ{�^���Q��
		if (m_MenuBottanFlag == 3)
		{
			m_MenuBottanFlame_x -= 300;
			m_SceneFlag = 2;	//�V�[���t���O���^�C�g����
			m_MenuBottanFlag = 2;
		}
	}

	//�E
	if (IsKeyPush(KEY_INPUT_D) == 1)
	{
		//�{�^���Q��I�����Ă���Ƃ��{�^���R��
		if (m_MenuBottanFlag == 2)
		{
			m_MenuBottanFlame_x += 300;
			m_SceneFlag = 3;	//�V�[���t���O���I�v�V������
			m_MenuBottanFlag = 3;
		}
		//�{�^���P��I�����Ă���Ƃ��{�^���Q��
		if (m_MenuBottanFlag == 1)
		{
			m_MenuBottanFlame_x += 300;
			m_SceneFlag = 2;	//�V�[���t���O���V���b�v��	
			m_MenuBottanFlag = 2;
		}


	}

	//�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	//�I�v�V�����V�[���͍��Ȃ�����
	if (m_SceneFlag != 3)
	{
		if (IsBottanFlag(60, m_MenuBottanFlame))
		{
			if (IsKeyPush(KEY_INPUT_RETURN))
			{
				//�X�e�[�W�Z���N�g�㏈���ֈړ�
				g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
			}
		}
	}

}

//�{�^���������邩�ǂ���
bool StageSelect::IsBottanFlag(int seconds, int Flame)
{
	//�t���[���C���N�������g
	Flame++;

	//0.5�b��������
	if(Flame >= seconds)
	{
		//������ꍇtrue��Ԃ�
		return true;
	}
}