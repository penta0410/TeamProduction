#include "DxLib.h"
#include "clear.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// �N���A�V�[��
//=============================

//�v���C������  
void Clear::InitClear()
{
	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//�v���C�ʏ폈��
void Clear::StepClear()
{
	//�X�e�[�W�I���ւ̑J��
	//ENTER�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_SceneFlag = 0;

		//�v���C�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}

}

//�v���C�`�揈��
void Clear::DrawClear()
{


	//�f�o�b�O
	DrawFormatString(100, 100, GetColor(255, 255, 255),
		"�N���A�V�[���ł�", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255),
		"�X�e�[�W�Z���N�g�ւ�enter�������Ă�������", true);

}

//�v���C�㏈��
void Clear::FinClear()
{
	if (m_SceneFlag == 0)
	{
		//�X�e�[�W�Z���N�gINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

}
