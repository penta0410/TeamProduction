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

};



//�X�e�[�W�Z���N�g������
void StageSelect::InitStageSelect()
{
	m_SceneFlag = 0;	//�V�[���t���O������
	m_Menu_Bottan_Flame = 0;		//���j���[�{�^���t���[��
	m_Menu_Flag = false;	//���j���[�t���O

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

	//�X�e�[�W�A�C�R��
	//x���W
	m_StageIcon_x[0] = 300;
	m_StageIcon_x[1] = 500;
	m_StageIcon_x[2] = 700;
	//y���W
	m_StageIcon_y[0] = 350;
	m_StageIcon_y[1] = 550;
	m_StageIcon_y[2] = 350;


	//�X�e�[�W�Z���N�g���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;
}

//�X�e�[�W�Z���N�g�ʏ폈��
void StageSelect::StepStageSelect()
{
	//���j���[��ʂ�
	//�{�^���������邩�ǂ���
	//tab�L�[�����ꂽ�Ȃ�
	if (IsBottanFlag(30, m_Menu_Bottan_Flame))
	{
		if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_Menu_Flag == false)
		{
			m_Menu_Flag = true;		//���j���[�t���O��on��
		}
		else if (IsKeyPush(KEY_INPUT_TAB) == 1 && m_Menu_Flag == true)
		{
			m_Menu_Flag = false;		//���j���[�t���O��off��
		}
	}

	//�V�[���J�ڏ���
	if (m_SceneFlag == 0)
	{
		//�v���C�V�[���ւ̑J��
		//Enter�L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
			m_SceneFlag = 0;

			//�X�e�[�W�Z���N�g�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}

		//�^�C�g���V�[���ւ̑J��
		
		//m_SceneFlag = 2;

		////�X�e�[�W�Z���N�g�㏈���ֈړ�
		//g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	
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
	

	//���j���[���
	if (m_Menu_Flag == true)
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

}

//�X�e�[�W�A�C�R���I������
void StageSelect::StageIconSelect()
{

}

//���j���[����
void StageSelect::Menu()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
	DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	

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