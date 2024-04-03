#pragma once
#include "../../Scene/Scene.h"
#include "../../Scene/Title/title.h"

const int STAGE_SELECT_IMAGE_NUMBER = 10; //�X�e�[�W�Z���N�g�摜����

//�X�e�[�W�Z���N�g�w�i�p�X
#define STAGE_SELECT_BACK_IMAGE_PATH	"Data/StageSelectImage/StageSelectBackImage.png"	
//�X�e�[�W�Z���N�g�^�C�g���p�X
#define STAGE_SELECT_TITLE_IMAGE_PATH	"Data/StageSelectImage/StageSelectTitleImage.png"	

class StageSelect : public Title
{
private:

	

public:

	//�X�e�[�W�Z���N�g������
	void InitStageSelect();

	//�X�e�[�W�Z���N�g�ʏ폈��
	void StepStageSelect();

	//�X�e�[�W�Z���N�g�`�揈��
	void DrawStageSelect();

	//�X�e�[�W�Z���N�g�㏈��
	void FinStageSelect();
};
