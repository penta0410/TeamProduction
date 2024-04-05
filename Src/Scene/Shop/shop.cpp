#include "DxLib.h"
#include "shop.h"
#include "../../Scene/Scene.h"
#include "../../Input/Input.h"

//=============================
// �V���b�v�V�[��
//=============================

//�X�e�[�W�Z���N�g�摜�p�X
const char* SHOP_IMAGE_PATH[SHOP_IMAGE_NUMBER] =
{
	SHOP_BACK_IMAGE_PATH,		//�V���b�v�w�i
	SHOP_SCROLL_IMAGE_PATH,		//�X�N���[��
	SHOP_PATH,					//�V���b�v

};

//�V���b�v������
void Shop::InitShop()
{
	m_imagehandle[0] = LoadGraph(SHOP_IMAGE_PATH[0]);	//�V���b�v�w�i
	m_imagehandle[1] = LoadGraph(SHOP_IMAGE_PATH[1]);	//�X�N���[��
	m_imagehandle[2] = LoadGraph(SHOP_IMAGE_PATH[2]);	//�V���b�v

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
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_imagehandle[0], true);	//�V���b�v�w�i	
	DrawRotaGraph(390, 360, 1.4f, 0.0f, m_imagehandle[1], true);	//�X�N���[��
	DrawRotaGraph(420, 120, 0.35f, 0.0f, m_imagehandle[2], true);	//�V���b�v

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
