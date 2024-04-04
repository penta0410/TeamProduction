#include "DxLib.h"
#include "stageselect.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"
#include "../Scene.h"

//=============================
// �X�e�[�W�Z���N�g�V�[��
//=============================

//�X�e�[�W�Z���N�g�摜�p�X
const char* STAGE_SELECT_IMAGE_PATH[STAGE_SELECT_IMAGE_NUMBER] =
{
	STAGE_SELECT_BACK_IMAGE_PATH,		//�X�e�[�W�w�i
	STAGE_SELECT_TITLE_IMAGE_PATH,		//�X�e�[�W�Z���N�g���o��
	STAGE_RETURN_BOTTAN_IMAGE_PATH,		//�߂�{�^��
	STAGE_SHOP_BOTTAN_IMAGE_PATH,		//�V���b�v�{�^��
    STAGE_SELECT_MENU_BOTTAN_IMAGE_PATH		//���j���[�{�^��
	STAGE_ICON_IMAGE_PATH,					//�X�e�[�W�A�C�R��

};

//�{�^���摜�p�X
const char* BOTTAN_IMAGE_PATH[BOTTAN_IMAGE_NUMBER] =
{
	TAB_BOTTAN_IMAGE_PATH,		//�^�u�{�^��
	ENTER_BOTTAN_IMAGE_PATH,	//�G���^�[�{�^��
	LEFT_CLICK_BOTTAN_IMAGE_PATH,	//���N���b�N�{�^��

};

//�X�e�[�W�Z���N�g������
void StageSelect::InitStageSelect()
{
	//�V�[���t���O������
	m_SceneFlag = 0;

	m_imagehandle[0] = LoadGraph(STAGE_SELECT_IMAGE_PATH[0]);	//�X�e�[�W�Z���N�g�w�i�摜
	m_imagehandle[1] = LoadGraph(STAGE_SELECT_IMAGE_PATH[1]);	//�X�e�[�W�Z���N�g�^�C�g���摜
	m_imagehandle[2] = LoadGraph(STAGE_SELECT_IMAGE_PATH[2]);	//�߂�{�^���摜
	m_imagehandle[3] = LoadGraph(STAGE_SELECT_IMAGE_PATH[3]);	//�V���b�v�{�^���摜
	m_imagehandle[4] = LoadGraph(STAGE_SELECT_IMAGE_PATH[4]);	//���j���[�{�^���摜
	m_imagehandle[5] = LoadGraph(BOTTAN_IMAGE_PATH[0]);			//�^�u�{�^���摜
	m_imagehandle[6] = LoadGraph(BOTTAN_IMAGE_PATH[1]);			//�G���^�[�{�^���摜
	m_imagehandle[7] = LoadGraph(STAGE_SELECT_IMAGE_PATH[5]);	//�X�e�[�W�A�C�R���摜
 	
	//�X�e�[�W�Z���N�g���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;

}

//�X�e�[�W�Z���N�g�ʏ폈��
void StageSelect::StepStageSelect()
{
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

		//���j���[��ʂ�
		//tab�L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			
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
	DrawRotaGraph(1240, 705, 0.07f, 0.0f, m_imagehandle[5], true);	//�^�u�{�^���`��
	
	DrawRotaGraph(300, 300, 0.8f, 0.0f, m_imagehandle[7], true);	//�X�e�[�W�A�C�R���`��
	
	//�f�o�b�O
	/*DrawFormatString(100, 100, GetColor(255, 255, 255), 
		"�X�e�[�W�Z���N�g�V�[���ł��B", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255),
		"�v���C�V�[���ւ�enter�������Ă��������B", true);
	DrawFormatString(100, 300, GetColor(255, 255, 255),
		"�V���b�v�V�[���ւ�tab�������Ă��������B", true);
	DrawFormatString(100, 400, GetColor(255, 255, 255),
		"�^�C�g���V�[���ւ͍�ctrl�������Ă��������B", true);*/

}

//�X�e�[�W�Z���N�g�㏈��
void StageSelect::FinStageSelect()
{
	if (m_SceneFlag == 0)
	{
		//�v���C�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}

	if (m_SceneFlag == 1)
	{
		//�V���b�v�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_SHOP;
	}

	if (m_SceneFlag == 2)
	{
		//�^�C�g���V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}

}