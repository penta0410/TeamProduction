#pragma once
#include "../Title/title.h"

const int GAME_OVER_IMAGE_NUMBER = 10;	//�摜����

//�Q�[���I�[�o�[��ʃp�X
#define GAME_OVER_BACK_PATH			"Data/GameOverImage/GameOver.png"

class GameOver : public Title
{
private:


public:

	//�Q�[���I�[�o�[������
	void InitGameOver();

	//�Q�[���I�[�o�[�ʏ폈��
	void StepGameOver();

	//�Q�[���I�[�o�[�`�揈��
	void DrawGameOver();

	//�Q�[���I�[�o�[�㏈��
	void FinGameOver();

};