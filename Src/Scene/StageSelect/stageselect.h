#pragma once
#include "../../Scene/Scene.h"
#include "../../Scene/Title/title.h"

const int STAGE_SELECT_IMAGE_NUMBER = 20; //�X�e�[�W�Z���N�g�摜����

const int BOTTAN_IMAGE_NUMBER = 10;		//�{�^���摜����

const int STAGE_NUM = 3;		//�X�e�[�W��

//�X�e�[�W�Z���N�g�w�i�p�X
#define STAGE_SELECT_BACK_IMAGE_PATH	"Data/StageSelectImage/StageSelectBackImage.png"	
//�X�e�[�W�Z���N�g�^�C�g���p�X
#define STAGE_SELECT_TITLE_IMAGE_PATH	"Data/StageSelectImage/StageSelectTitleImage.png"	
//�߂�{�^���p�X
#define STAGE_RETURN_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/ReturnBottanImage.png"			
//�V���b�v�{�^���p�X
#define STAGE_SHOP_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/ShopBottanImage.png"
//���j���[�{�^���p�X
#define STAGE_SELECT_MENU_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/MenuBottanImage.png"
//�X�e�[�W�A�C�R���p�X
#define STAGE_ICON_IMAGE_PATH		"Data/StageSelectImage/StageIconImage.png"
//�X�e�[�W�P�p�X
#define STAGE1_PATH		"Data/StageSelectImage/STAGE1.png"
//�X�e�[�W2�p�X
#define STAGE2_PATH		"Data/StageSelectImage/STAGE2.png"
//�X�e�[�W3�p�X
#define STAGE3_PATH		"Data/StageSelectImage/STAGE3.png"
//�t���[���p�X
#define Flame_PATH		"Data/StageSelectImage/Flame.png"

//�^�u�{�^���p�X
#define TAB_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/TabkeyBottanImage.png"
//�G���^�[�{�^���p�X
#define ENTER_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/EnterKeyBottanImage.png"
//���N���b�N�{�^���p�X
#define LEFT_CLICK_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/LeftClickBottanImage.png"
//�^�C�g���ɖ߂�{�^���p�X
#define RETURN_TITLE_BOTTAN_PATH		"Data/StageSelectImage/returntitleBottan.png"
//�I�v�V�����{�^���p�X
#define OPITON_BOTTAN_PATH				"Data/StageSelectImage/OptionBottanImage.png" 

//�X�e�[�W�I���t���[���p�X
#define STAGE_FLAME_PATH		"Data/StageSelectImage/Flame.png"
//���j���[�{�^���t���[���p�X
#define BOTTAN_FLAME_PATH		"Data/StageSelectImage/MenuBottanFlame.png"

class StageSelect : public Title
{
private:
	
	//�X�e�[�W�A�C�R�����W
	int m_StageIcon_x[STAGE_NUM] = { 0 };
	int m_StageIcon_y[STAGE_NUM] = { 0 };
	int m_StageFlag = 0;			//�X�e�[�W�t���O
	int m_MenuBottanFlame = 0;		//���j���[�{�^���t���[��
	bool m_MenuFlag = false;	//���j���[�t���O
	
	int m_MenuBottanFlag = 0;		//���j���[�{�^���̃t���O

	//���j���[�{�^���t���[�����W
	int m_MenuBottanFlame_x = 0;		
	int m_MenuBottanFlame_y = 0;

public:

	//�X�e�[�W�Z���N�g������
	void InitStageSelect();

	//�X�e�[�W�Z���N�g�ʏ폈��
	void StepStageSelect();

	//�X�e�[�W�Z���N�g�`�揈��
	void DrawStageSelect();

	//�X�e�[�W�Z���N�g�㏈��
	void FinStageSelect();

	//�X�e�[�W�A�C�R���I������
	void StageIconSelect();

	//���j���[����
	void Menu();
	
	//�{�^���������邩�ǂ���
	//�����P �@�{�^���Ԋu�w��
	//�����Q	�t���[���ϐ��w��
	bool IsBottanFlag(int sconds, int Flame);

};
