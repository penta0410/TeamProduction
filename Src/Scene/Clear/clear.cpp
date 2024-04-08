#include "DxLib.h"
#include "clear.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// �N���A�V�[��
//=============================

//�X�e�[�W�N���A�摜�p�X
const char* CLEAR_PATH[CLEAR_IMAGE_NUMBER] =
{
	STAGRE_CLEAR_BACK_PATH,			//�X�e�[�W�N���A���

};

//�N���A���[�h
void Clear::LoadClear()
{
	m_imagehandle[0] = LoadGraph(CLEAR_PATH[0]);	//�N���A���

}

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

	DrawRotaGraph(640, 360, 1.01f, 0.0f, m_imagehandle[0], true);
	

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
