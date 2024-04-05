#pragma once

const int TITLE_IMAGE_NUMBER = 15;		//�摜����

#define START_BOTTAN_IMAGE_PATH	"Data/TitleImage/StartBottanImage.png"		//�X�^�[�g�{�^���摜�p�X
#define TITLE_IMAGE_BACK_PATH	"Data/TitleImage/TitleBackGroundImage.png"		//�^�C�g���w�i�摜�p�X
#define TITLE_IMAGE_NAME_PATH	"Data/TitleImage/TitleImage.png"		//�^�C�g�����O�摜�p�X

class Title
{
protected:		//�ق��̃V�[���ł��g������

	//�^�C�g���V�[������̑J�ڑI���t���O
	int m_SceneFlag = 0;

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W

	int m_Back_x = 0;	//x���W
	int m_Back_y = 0;	//y���W

	//�X�N���[���p
	int m_Back_x_2 = 0;	//x���W
	int m_Back_y_2 = 0;	//y���W

	//�w�i�摜�n���h��
	int m_imagehandle[TITLE_IMAGE_NUMBER] = { 0 };

private:	//�^�C�g���V�[�������Ŏg������

	//�{�^���A�j���[�V�������ߕϐ�
	int m_BottanAlpha = 200;

	//���߃t���O
	bool m_BottanAlphaFlag = true;


public:

	// �^�C�g��������
	void InitTitle();

	//�^�C�g���ʏ폈��
	void StepTitle();

	//�^�C�g���`�揈��
	void DrawTitle();

	//�^�C�g���㏈��
	void FinTitle();

	//�}�E�X�N���b�N����
	void MouseClick();

};