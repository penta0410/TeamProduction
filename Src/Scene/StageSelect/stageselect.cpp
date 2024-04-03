#include "DxLib.h"
#include "stageselect.h"
#include "../../Input/Input.h"

//=============================
// �X�e�[�W�Z���N�g�V�[��
//=============================

//�X�e�[�W�Z���N�g������
void StageSelect::InitStageSelect()
{
	//�X�e�[�W�Z���N�g���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;

	//�X�e�[�W�Z���N�g�V�[���t���O
	m_SceneFlag = 0;

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

		//�v���C�V�[���ւ̑J��
		//tab�L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			m_SceneFlag = 1;

			//�X�e�[�W�Z���N�g�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}

		//�^�C�g���V�[���ւ̑J��
		//���R���g���[���L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_LCONTROL))
		{
			m_SceneFlag = 2;

			//�X�e�[�W�Z���N�g�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}
	}
	
}

//�X�e�[�W�Z���N�g�`�揈��
void StageSelect::DrawStageSelect()
{
	//�X�e�[�W�Z���N�g��ʕ`��
	DrawGraph(0, 0, m_imagehandle[0], true);

	//�f�o�b�O
	DrawFormatString(100, 100, GetColor(255, 255, 255), 
		"�X�e�[�W�Z���N�g�V�[���ł��B", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255),
		"�v���C�V�[���ւ�enter�������Ă��������B", true);
	DrawFormatString(100, 300, GetColor(255, 255, 255),
		"�V���b�v�V�[���ւ�tab�������Ă��������B", true);
	DrawFormatString(100, 400, GetColor(255, 255, 255),
		"�^�C�g���V�[���ւ͍�ctrl�������Ă��������B", true);

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