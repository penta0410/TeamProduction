#pragma once
#include "../Title/title.h"

const int SHOP_IMAGE_NUMBER = 20;	//�V���b�v�摜����

#define SHOP_BACK_IMAGE_PATH	"Data/ShopImage/ShopBackImage.png"	//�V���b�v�w�i�摜�p�X
#define SHOP_SCROLL_IMAGE_PATH		"Data/ShopImage/ScrollImage.png"	//�V���b�v�X�N���[���摜�p�X
#define SHOP_PATH				"Data/ShopImage/Shop.png"	//�V���b�v
//�����A�b�v�{�^���p�X
#define HP_UP_BOTTAN_PATH		"Data/ShopImage/HpUPBottanImage.png"
//�U���̓A�b�v�{�^���p�X
#define ATTACK_POWER_UP_BOTTAN_PATH		"Data/ShopImage/AttackPowerBottanImage.png"
//�U���X�s�[�h�A�b�v�{�^���p�X
#define ATTACK_SPEED_UP_BOTTAN_PATH		"Data/ShopImage/AttackIntervalUpBottanImage.png"
//�ړ����x�A�b�v�{�^���p�X
#define MOVE_SPEED_UP_B_PATH			"Data/ShopImage/MoveSpeedUpBottanImage.png"
//�����̗ʃA�b�v�{�^���p�X
#define MONEY_AMMOUNT_UP_BOTTAN_PATH	"Data/ShopImage/MoneyAmmountUpBottanImage.png"
//�X�R�A�A�b�v�{�^���p�X
#define SCORE_UP_BOTTAN_PATH			"Data/ShopImage/ScoreUpBottanImage.png"

class Shop : public Title
{

private:

	

	int m_PlayerHp = 0;					//�v���C���[���������ʂ�ۑ�����
	int m_PlayerAttackPower = 0;		//�v���C���[�U���͑����ʂ�ۑ�����
	int m_PlayerAttackInterval = 0;		//�v���C���[�U���p�x��ۑ�����
	int m_ScoreUp = 0;					//�X�R�A�A�b�v
	int m_MoveSpeed = 0;				//�v���C���[���ړ����x��ۑ�����
	int m_MoneyAmmountUp = 0;			//�����̗ʂ��A�b�v

public:

	//�V���b�v������
	void InitShop();

	//�V���b�v���[�h
	void LoadShop();

	//�V���b�v�ʏ폈��
	void StepShop();

	//�V���b�v�`�揈��
	void DrawShop();

	//�V���b�v�㏈��
	void FinShop();

	//�v���C���[���������ʃZ�b�g����
	void SetPlayerHpUp(int Hp);

	//�v���C���[���������ʃQ�b�g����
	int GetPlayerHpUp() { return m_PlayerHp; };

};
