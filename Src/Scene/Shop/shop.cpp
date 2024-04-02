#include "DxLib.h"
#include "shop.h"
#include "../../Scene/Scene.h"
#include "../../Input/Input.h"

//=============================
// �V���b�v�V�[��
//=============================

//�V���b�v������
void SHOP::InitShop()
{
	//�V���b�v���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//�V���b�v�ʏ폈��
void SHOP::StepShop()
{

	//�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_SceneFlag = 0;

		//�V���b�v�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

	//�V�[���ւ̑J��
	//Tab�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_SceneFlag = 1;

		//�V���b�v�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

}

//�V���b�v�`�揈��
void SHOP::DrawShop()
{
	//�V���b�v�w�i	
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_imagehandle[0], true);

	//�f�o�b�O
	DrawFormatString(0, 0, GetColor(0, 0, 0), "�V���b�v�V�[���ł�", true);

}

//�V���b�v�㏈��
void SHOP::FinShop()
{
	if (m_SceneFlag == 0)
	{
		
	}

	if (m_SceneFlag == 1)
	{
		
	}

}
