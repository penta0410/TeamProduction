#include "DxLib.h"
#include "shop.h"
#include "../../Scene/Scene.h"
#include "../../Input/Input.h"

//=============================
// �V���b�v�V�[��
//=============================

//�V���b�v������
void Shop::InitShop()
{
	//�V���b�v���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//�V���b�v�ʏ폈��
void Shop::StepShop()
{

	//�X�e�[�W�Z���N�g�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_SceneFlag = 0;

		//�V���b�v�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

	////�V�[���ւ̑J��
	////Tab�L�[�����ꂽ�Ȃ�
	//if (IsKeyPush(KEY_INPUT_TAB))
	//{
	//	m_SceneFlag = 1;

	//	//�V���b�v�㏈���ֈړ�
	//	g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	//}

}

//�V���b�v�`�揈��
void Shop::DrawShop()
{
	//�V���b�v�w�i	
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_imagehandle[0], true);

	//�f�o�b�O
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�V���b�v�V�[���ł�", true);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "�X�e�[�W�Z���N�g�ɖ߂�ɂ�enter�������Ă��������B", true);

}

//�V���b�v�㏈��
void Shop::FinShop()
{
	if (m_SceneFlag == 0)
	{
		//�X�e�[�W�Z���N�g�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

	/*if (m_SceneFlag == 1)
	{
		
	}*/

}
