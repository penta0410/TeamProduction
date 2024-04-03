#include "DxLib.h"
#include "title.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"

//=============================
// �^�C�g���V�[��
//=============================

//�^�C�g���摜�p�X
const char* TITLE_IMAGE_PATH[TITLE_IMAGE_NUMBER] =
{
	START_BOTTAN_IMAGE_PATH,
	TITLE_IMAGE_BACK_PATH,

};

//�^�C�g��������
void Title::InitTitle()
{
	m_imagehandle[0] = LoadGraph(TITLE_IMAGE_PATH[0]);		//�X�^�[�g�{�^���摜
	m_imagehandle[1] = LoadGraph(TITLE_IMAGE_PATH[1]);		//�^�C�g���w�i�摜

	//�^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

//�^�C�g���ʏ폈��
void Title::StepTitle()
{
	//�X�e�[�W�Z���N�g�ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�^�C�g���V�[���t���O���X�e�[�W�Z���N�g�V�[���ɕύX
		m_SceneFlag = 0;

		//'�v���C�㏈��'�ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;

	}

	////�I�v�V�����V�[���ւ̑J��
	////tab(�^�u)�L�[�{�^�������ꂽ�Ȃ�
	//if (IsKeyPush(KEY_INPUT_TAB))
	//{
	//	//�^�C�g���V�[���t���O���I�v�V�����V�[���ɕύX
	//	m_SceneFlag = 1;
	//	//'�v���C�㏈��'�ֈړ�
	//	g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	//}

	//���ߏ���
	m_BottanAlpha = Transparent(m_BottanAlpha);
}

//�^�C�g���`�揈��
void Title::DrawTitle()
{
	//�^�C�g���w�i�`��
	DrawRotaGraph(300, 300, 1.0f, 0.0f, m_imagehandle[1], true);

	//�X�^�[�g�{�^���`��
	//�_�ŃA�j���[�V����(���ߏ���)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BottanAlpha);
	DrawRotaGraph(645, 510, 0.4f, 0.0f, m_imagehandle[0], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, m_BottanAlpha);

	//�}�E�X����
	MouseClick();


	//�f�o�b�O
	/*DrawFormatString(100, 100, GetColor(255, 255, 255),
		"�^�C�g���V�[���ł�", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255),
		"�X�e�[�W�I���V�[���ւ�enter�������Ă��������B", true);*/

}

//�^�C�g���㏈��
void Title::FinTitle()
{
	//�X�e�[�W�Z���N�gINIT�ֈړ�
	if (m_SceneFlag == 0)
	{
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}
	////�I�v�V����INIT�ֈړ�
	//if (m_SceneFlag == 1)
	//{
	//	/*g_CurrentSceneID = SCENE_ID_INIT_OPTION;*/
	//}

}

void Title::MouseClick()
{

	//�}�E�X�ʒu�擾
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);

	////�I�v�V�����V�[���ֈړ�����}�E�X����
	////�{�^���ʒu�ƃ{�^���Ƃ̓����蔻��
	//if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_bottan_x, m_bottan_y, m_bottan_r) == 1)
	//{
	//	//�����w�i
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	//	DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//	//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
	//	SetFontSize(12);
	//	DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<option>\n�{�^�������N���b�N���邩\ntab(�^�u)�L�[�������Ă�������");

	//	//�����T�C�Y�����Ƃ�
	//	SetFontSize(16);

	//	//���N���b�N�����Ƃ�
	//	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	//	{
	//		//�I�v�V�����V�[���ւ̑J��
	//		//��ʏ�̃I�v�V�����{�^�������ꂽ�Ȃ�

	//		//�^�C�g���V�[���t���O���I�v�V�����V�[���ɕύX
	//		m_TitleSceneFlag = false;

	//		//'�^�C�g���㏈��'�ֈړ�
	//		g_CurrentSceneID = SCENE_ID_FIN_TITLE;

	//	}
	//	else
	//	{
	//		//������Ă��Ȃ�
	//	}
	//}




}