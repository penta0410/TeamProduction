#pragma once
#include "../../Scene/Scene.h"
#include "../../Scene/Title/title.h"

const int STAGE_SELECT_IMAGE_NUMBER = 10; //�X�e�[�W�Z���N�g�摜����

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
