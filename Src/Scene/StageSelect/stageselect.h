#pragma once
#include "../../Scene/Scene.h"
#include "../../Scene/Title/title.h"

const int STAGE_SELECT_IMAGE_NUMBER = 10; //�X�e�[�W�Z���N�g�摜����

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

//�^�u�{�^���p�X
#define TAB_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/TabkeyBottanImage.png"
//�G���^�[�{�^���p�X
#define ENTER_BOTTAN_IMAGE_PATH		"Data/StageSelectImage/EnterKeyBottanImage.png"
//���N���b�N�{�^���p�X
#define LEFT_CLICK_BOTTAN_IMAGE_PATH	"Data/StageSelectImage/LeftClickBottanImage.png"

class StageSelect : public Title
{
private:
	
	//�X�e�[�W�A�C�R�����W
	int m_StageIcon_x[STAGE_NUM] = { 0 };
	int m_StageIcon_y[STAGE_NUM] = { 0 };

public:

	StageSelect();		//�R���X�g���N�^
	~StageSelect();		//�f�X�g���N�^

	//�X�e�[�W�Z���N�g������
	void InitStageSelect();

	//�X�e�[�W�Z���N�g�ʏ폈��
	void StepStageSelect();

	//�X�e�[�W�Z���N�g�`�揈��
	void DrawStageSelect();

	//�X�e�[�W�Z���N�g�㏈��
	void FinStageSelect();
};
