#include <math.h>
#include "DxLib.h"
#include "play.h"
#include "../Scene.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Common.h"
#include "../Play/play.h"
#include "../../Screen/Screen.h"

//=============================
// �v���C�V�[��
//=============================

Play::Play() {}		//�R���X�g���N�^
Play::~Play() {}	//�f�X�g���N�^

//�v���C�V�[���摜�p�X
const char* PLAY_IMAGE_PATH[PLAY_IMAGE_NUMBER] =
{
	PLAY_BACK_PATH,		//�v���C�w�i�p�X


};

//�v���C������  
void Play::InitPlay()
{
	m_imagehandle[0] = LoadGraph(PLAY_IMAGE_PATH[0]);	//�v���C�w�i�摜

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
	DrawRotaGraph(645, 359, 1.01f, 0.0f, m_imagehandle[0], true); //�v���C�w�i�`��

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