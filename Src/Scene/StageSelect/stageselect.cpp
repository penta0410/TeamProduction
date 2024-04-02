#include "DxLib.h"
#include "stageselect.h"
#include "../../Input/Input.h"

//=============================
// �X�e�[�W�Z���N�g�V�[��
//=============================

//�X�e�[�W�Z���N�g������
void Stage_Select::InitStageSelect()
{
	//�X�e�[�W�Z���N�g���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;

	//�X�e�[�W�Z���N�g�V�[���t���O
	m_SceneFlag = 0;

}

//�X�e�[�W�Z���N�g�ʏ폈��
void Stage_Select::StepStageSelect()
{
	//�X�e�[�W�Z���N�g����
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

	}
}

//�X�e�[�W�Z���N�g�`�揈��
void Stage_Select::DrawStageSelect()
{
	//�X�e�[�W�Z���N�g��ʕ`��
	DrawGraph(0, 0, m_imagehandle[0], true);

	//�f�o�b�O
	DrawFormatString(100, 100, GetColor(0, 0, 0), 
		"�X�e�[�W�I����ʂł�", true);

}

//�X�e�[�W�Z���N�g�㏈��
void Stage_Select::FinStageSelect()
{
	if (m_SceneFlag == 0)
	{
		//�v���C�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}