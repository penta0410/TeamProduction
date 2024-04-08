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
//�{�^���t���[���p�X
#define SHOP_BOTTAN_FLAME_PATH			"Data/ShopImage/BottanFlame.png"
//�R�C���p�X
#define KOIN_PATH						"Data/PlayImage/coin.png"

class Shop : public Title
{

private:

	int m_PlayerHp = 0;					//�v���C���[���������ʂ�ۑ�����
	int m_PlayerAttackPower = 0;		//�v���C���[�U���͑����ʂ�ۑ�����
	float m_PlayerAttackInterval = 0;		//�v���C���[�U���p�x��ۑ�����
	float m_MoveSpeed = 0;				//�v���C���[���ړ����x��ۑ�����
	int m_MoneyAmmountUp = 0;			//�����̗ʂ��A�b�v

	int m_BottanFlag = 0;					//�{�^���I���t���O

	//�{�^���t���[�����W
	int m_BottanFlame_x = 0;
	int m_BottanFlame_y = 0;

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

	//�v���C���[���������ʃZ�b�g
	void SetPlayerHpUp(int Hp);

	//�v���C���[���������ʃQ�b�g
	int GetPlayerHpUp() { return m_PlayerHp; };

	//�v���C���[�U���͑����ʃZ�b�g
	void SetPlayerAttackUp(int attack);

	//�v���C���[�U���̓A�b�v�ʃQ�b�g
	int GetPlayerAttackUp() { return m_PlayerAttackPower; };

	//�v���C���[�U���p�x�A�b�v�ʃZ�b�g
	void SetPlayerAttackSpeedUp(float attackspeed);

	//�v���C���[�U���p�x�A�b�v�ʃQ�b�g
	float GetPlayerAttackSpeedUp() { return m_PlayerAttackInterval; };

	//�v���C���[���ړ����x�A�b�v�ʃZ�b�g
	void SetPlayerMoveSpeedUp(float movespeed);

	//�v���C���[���ړ����x�A�b�v�ʃQ�b�g
	float GetPlayerMoveSpeedUp() { return m_MoveSpeed; };

	//�����̗ʃA�b�v�ʃZ�b�g
	void SetMoneyAmmountUp(int moneyammount);

	//�����̗ʃA�b�v�ʃQ�b�g
	int GetMoneyAmmountUp() { return m_MoneyAmmountUp; };

};
