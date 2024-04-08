#include "DxLib.h"
#include "gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// �Q�[���I�[�o�[�V�[��
//=============================


//�X�e�[�W�Z���N�g�摜�p�X
const char* GAME_OVER_IMAGE_PATH[GAME_OVER_IMAGE_NUMBER] =
{
	GAME_OVER_BACK_PATH,			//�Q�[���I�[�o�[���

};

//�Q�[���I�[�o�[������
void GameOver::InitGameOver()
{
	m_imagehandle[0] = LoadGraph(GAME_OVER_IMAGE_PATH[0]);

	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�ʏ폈��
void GameOver::StepGameOver()
{
	//ENTER�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�X�e�[�W�I���V�[����
		m_SceneFlag = 0;

		//�v���C�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}

}

//�Q�[���I�[�o�[�`�揈��
void GameOver::DrawGameOver()
{
	//�Q�[���I�[�o�[�w�i�`��
	DrawRotaGraph(640, 360, 01.0f, 0.0f, m_imagehandle[0], true);

}

//�Q�[���I�[�o�[�㏈��
void GameOver::FinGameOver()
{
	if (m_SceneFlag == 0)
	{
		//�X�e�[�W�Z���N�gINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}
}
