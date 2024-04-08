#include "DxLib.h"
#include "gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

//=============================
// �Q�[���I�[�o�[�V�[��
//=============================
//
//GAME_OVER_BACK_PATH

//�Q�[���I�[�o�[������
void GameOver::InitGameOver()
{
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
	
	//�f�o�b�O
	DrawFormatString(0, 30, GetColor(255, 255, 255),
		"�Q�[���I�[�o�[�V�[���ł��B", true);
	DrawFormatString(0, 130, GetColor(255, 255, 255), 
		"�X�e�[�W�Z���N�g�ɂ̓G���^�[�������Ă�������", true);

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
