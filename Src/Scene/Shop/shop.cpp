#include "DxLib.h"
#include "shop.h"
#include "../../Scene/Scene.h"
#include "../../Input/Input.h"
#include "../StageSelect/stageselect.h"


//=============================
// �V���b�v�V�[��
//=============================

//�X�e�[�W�Z���N�g�摜�p�X
const char* SHOP_IMAGE_PATH[SHOP_IMAGE_NUMBER] =
{
	SHOP_BACK_IMAGE_PATH,			//�V���b�v�w�i
	SHOP_SCROLL_IMAGE_PATH,			//�X�N���[��
	SHOP_PATH,						//�V���b�v
	HP_UP_BOTTAN_PATH,				//�����A�b�v�{�^��
	ATTACK_POWER_UP_BOTTAN_PATH,	//�U���̓A�b�v�{�^��
	ATTACK_SPEED_UP_BOTTAN_PATH,	//�U���X�s�[�h�A�b�v�{�^��
	MOVE_SPEED_UP_B_PATH,			//�ړ����x�A�b�v�{�^��
	MONEY_AMMOUNT_UP_BOTTAN_PATH,	//�����̗ʃA�b�v�{�^��
	SHOP_BOTTAN_FLAME_PATH,			//�{�^���t���[��
	KOIN_PATH,						//�R�C��

};

//�V���b�v���[�h
void Shop::LoadShop()
{
	m_imagehandle[0] = LoadGraph(SHOP_IMAGE_PATH[0]);	//�V���b�v�w�i
	m_imagehandle[1] = LoadGraph(SHOP_IMAGE_PATH[1]);	//�X�N���[��
	m_imagehandle[2] = LoadGraph(SHOP_IMAGE_PATH[2]);	//�V���b�v
	m_imagehandle[3] = LoadGraph(STAGE_RETURN_BOTTAN_IMAGE_PATH);		//�߂�{�^��
	m_imagehandle[4] = LoadGraph(TAB_BOTTAN_IMAGE_PATH);		//�^�u�{�^��
	m_imagehandle[5] = LoadGraph(SHOP_IMAGE_PATH[3]);	//�����A�b�v�{�^��
	m_imagehandle[6] = LoadGraph(SHOP_IMAGE_PATH[4]);	//�U���̓A�b�v�{�^��
	m_imagehandle[7] = LoadGraph(SHOP_IMAGE_PATH[5]);	//�U���X�s�[�h�A�b�v�{�^��
	m_imagehandle[8] = LoadGraph(SHOP_IMAGE_PATH[6]);	//�ړ����x�A�b�v�{�^��
	m_imagehandle[9] = LoadGraph(SHOP_IMAGE_PATH[7]);	//�����̗ʃA�b�v�{�^��
	m_imagehandle[10] = LoadGraph(SHOP_IMAGE_PATH[8]);	//�{�^���t���[��
	m_imagehandle[11] = LoadGraph(SHOP_IMAGE_PATH[9]);	//�R�C��

}

//�V���b�v������
void Shop::InitShop()
{
	m_BottanFlag = 0;					//�{�^���I���t���O

	//�{�^���t���[�����W
	m_BottanFlame_x = 193;
	m_BottanFlame_y = 187;

	//�V���b�v���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//�V���b�v�ʏ폈��
void Shop::StepShop()
{
	//�{�^���v�b�V������
	//�G���^�[�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�����A�b�v�{�^����I�����Ă�����
		if (m_BottanFlag == 0)
		{
			m_PlayerHp += 100;
		}
		//�U���̓A�b�v�{�^����I�����Ă�����
		else if (m_BottanFlag == 1)
		{
			m_PlayerAttackPower += 2;
		}
		//�U���X�s�[�h�A�b�v�{�^����I�����Ă�����
		else if (m_BottanFlag == 2)
		{
			m_PlayerAttackInterval += 0.1;
		}
		//�ړ����x�A�b�v�{�^����I�����Ă�����
		else if (m_BottanFlag == 3)
		{
			m_MoveSpeed += 0.1;
		}
		//�����̗ʃA�b�v�{�^����I�����Ă�����
		else if (m_BottanFlag == 4)
		{
			m_MoneyAmmountUp += 1;
		}
	}

	//�{�^���I������
	//��
	if (IsKeyPush(KEY_INPUT_W) == 1)
	{
		//�{�^���Q��I�����Ă���Ƃ��{�^���P��
		if (m_BottanFlag == 1)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 0;
		}
		//�{�^���R��I�����Ă���Ƃ��Ƀ{�^���Q��
		else if (m_BottanFlag == 2)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 1;
		}
		//�{�^���S��I�����Ă���Ƃ��Ƀ{�^���R��
		else if (m_BottanFlag == 3)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 2;
		}
		//�{�^���T��I�����Ă���Ƃ��Ƀ{�^���S��
		else if (m_BottanFlag == 4)
		{
			m_BottanFlame_y -= 90;
			m_BottanFlag = 3;
		}
	}
	//��
	if (IsKeyPush(KEY_INPUT_S) == 1)
	{
		//�{�^���Q��I�����Ă���Ƃ��{�^���R��
		if (m_BottanFlag == 1)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 2;
		}
		//�{�^���P��I�����Ă���Ƃ��{�^���Q��
		else if (m_BottanFlag == 0)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 1;
		}
		//�{�^���R��I�����Ă���Ƃ��{�^���S��
		else if (m_BottanFlag == 2)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 3;
		}
		//�{�^���S��I�����Ă���Ƃ��{�^���T��
		else if (m_BottanFlag == 3)
		{
			m_BottanFlame_y += 90;
			m_BottanFlag = 4;
		}
	}
	



	//�X�e�[�W�Z���N�g�V�[���ւ̑J��
	//Tab�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_SceneFlag = 0;
		//�V���b�v�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

}

//�V���b�v�`�揈��
void Shop::DrawShop()
{
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_imagehandle[0], true);	//�V���b�v�w�i	
	DrawRotaGraph(390, 360, 1.4f, 0.0f, m_imagehandle[1], true);	//�X�N���[��
	DrawRotaGraph(420, 120, 0.35f, 0.0f, m_imagehandle[2], true);	//�V���b�v
	DrawRotaGraph(1210, 680, 0.65f, 0.0f, m_imagehandle[3], true);	//�߂�{�^���`��
	DrawRotaGraph(1240, 710, 0.07f, 0.0f, m_imagehandle[4], true);	//�^�u�{�^���`��
	DrawRotaGraph(195 - 15, 190, 0.2f, 0.0f, m_imagehandle[5], true);	//�����A�b�v�{�^���`��
	DrawRotaGraph(189 - 15, 280, 0.2f, 0.0f, m_imagehandle[6], true);	//�U���̓A�b�v�{�^���`��
	DrawRotaGraph(195 - 15, 370, 0.2f, 0.0f, m_imagehandle[7], true);	//�U���X�s�[�h�A�b�v�{�^���`��
	DrawRotaGraph(195 - 15, 460, 0.2f, 0.0f, m_imagehandle[8], true);	//�ړ����x�A�b�v�{�^���`��
	DrawRotaGraph(195 - 15, 550, 0.2f, 0.0f, m_imagehandle[9], true);	//�����̗ʃA�b�v�{�^���`��
	//�{�^���t���[���`��
	DrawRotaGraph(m_BottanFlame_x - 20, m_BottanFlame_y,
		0.2f, 0.0f,m_imagehandle[10], true);

	int Koin_y = 190;	//�R�C��y���W�i�`�悷�邽�߂Ɏg�p�j
	SetFontSize(32);
	//�R�C���`��
	for (int i = 0; i < 5; i++)
	{
		DrawRotaGraph(290, Koin_y, 0.3f, 0.0f, m_imagehandle[11], true);
		DrawFormatString(310, Koin_y - 20, GetColor(0, 0, 0), "���R", true);
		Koin_y += 90;
	}

	
	SetFontSize(36);

	//�v���C���[�����A�b�v�ʕ\��
	DrawFormatString(400, 170, GetColor(0, 0, 0), "HPUp�ʁF%d", m_PlayerHp , true); 
	//�v���C���[�U���̓A�b�v�ʕ\��
	DrawFormatString(400, 260, GetColor(0, 0, 0), "ATKUp�ʁF%d", m_PlayerAttackPower, true);
	//�U���X�s�[�h�A�b�v�ʕ\��
	DrawFormatString(400, 350, GetColor(0, 0, 0), "ATKSPDUp�ʁF%0.1f", m_PlayerAttackInterval, true);
	//�ړ����x�A�b�v�ʕ\��
	DrawFormatString(400, 440, GetColor(0, 0, 0), "SPDUp�ʁF%0.1f", m_MoveSpeed, true);
	//�����̗ʃA�b�v�ʕ\��
	DrawFormatString(400, 530, GetColor(0, 0, 0), "�����̗�Up�ʁF%d", m_MoneyAmmountUp, true);
	
	
	SetFontSize(16);

}

//�V���b�v�㏈��
void Shop::FinShop()
{
	if (m_SceneFlag == 0)
	{
		//�X�e�[�W�Z���N�g�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

	

}

//�v���C���[���������ʃZ�b�g����
void Shop::SetPlayerHpUp(int Hp)
{
	m_PlayerHp += Hp;
}

//�v���C���[�U���͑����ʃZ�b�g
void Shop::SetPlayerAttackUp(int attack)
{
	m_PlayerAttackPower += attack;
}

//�v���C���[�U���p�x�A�b�v�ʃZ�b�g
void Shop::SetPlayerAttackSpeedUp(float attackspeed)
{
	m_PlayerAttackInterval += attackspeed;
}

//�v���C���[���ړ����x�A�b�v�ʃZ�b�g
void Shop::SetPlayerMoveSpeedUp(float movespeed)
{
	m_MoveSpeed += movespeed;
}

//�����̗ʃA�b�v�ʃZ�b�g
void Shop::SetMoneyAmmountUp(int moneyammount)
{
	m_MoneyAmmountUp += moneyammount;
}




