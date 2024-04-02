#pragma once

const int TITLE_IMAGE_NUMBER = 10;		//�摜����

class Title
{
protected:		//�ق��̃V�[���ł��g������

	//�^�C�g���V�[������̑J�ڑI���t���O
	int m_SceneFlag = 0;

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W

	//�w�i�摜�n���h��
	int m_imagehandle[TITLE_IMAGE_NUMBER] = { 0 };

private:	//�^�C�g���V�[�������Ŏg������

	//�{�^���A�j���[�V�������ߕϐ�
	int m_BottanAlpha = 100;

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