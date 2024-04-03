#include <math.h>
#include "DxLib.h"
#include "play.h"
#include "../Scene.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Common.h"

//=============================
// �v���C�V�[��
//=============================

Play::Play() {}		//�R���X�g���N�^
Play::~Play() {}	//�f�X�g���N�^

//�v���C������  
void Play::InitPlay()
{
	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�ʏ폈��
void Play::StepPlay()
{
	//�N���A�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�v���C�V�[���t���O���N���A�V�[���ɕύX
		m_SceneFlag = 0;

		//'�v���C�㏈��'�ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	}

	//�Q�[���I�[�o�[�V�[���ւ̑J��
	//Tab�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		//�v���C�V�[���t���O���N���A�V�[���ɕύX
		m_SceneFlag = 1;

		//'�v���C�㏈��'�ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	}

}

//�v���C�`�揈��
void Play::DrawPlay()
{
	//�f�o�b�O
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�v���C�V�[���ł�", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "�N���A�V�[���ւ�enter", true);
	DrawFormatString(100, 300, GetColor(255, 255, 255), "�Q�[���I�[�o�[�V�[���ւ�tab", true);

}

//�v���C�㏈��
void Play::FinPlay()
{
	//�N���A�V�[����
	if (m_SceneFlag == 0)
	{
		//�Q�[���N���A�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}

	//�Q�[���I�[�o�[�V�[����
	if (m_SceneFlag == 1)
	{
		//�Q�[���I�[�o�[�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;

	}
}