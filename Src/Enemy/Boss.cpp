#include "DxLib.h"
#include "Boss.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

//Boss::Boss(){}		//�R���X�g���N�^
//Boss::~Boss(){}		//�f�X�g���N�^


void Boss::InitBoss()						//�v���C������
{
	Boss_handle = 0;						//�摜�n���h��

	Boss_ATK = BOSS_ATK;					//�{�X�U����
	Boss_HP = BOSS_HP;						//�{�X�̗�
	Boss_point = BOSS_POINT;				//�{�X�|�C���g
	Boss_experience = BOSS_EXPERIENCE;		//�{�X�o���l
	Boss_is_alive = true;					//�{�X�����t���O

}

void Boss::LoadBoss()						//�{�X�ǂݍ���
{
	//Boss_handle = LoadGraph(BOSS_IMAGE_PATH);	//�摜���ł���܂�
}

void Boss::DrawBoss()						//�{�X�`��
{
	/*for (int i = 0; i < BOSS_MAX_NUM; i++)
	{
		if (Boss_is_alive)
		{
			DrawRotaGraph()
		}
	}*/
	
}

void Boss::ATKBoss()						//�{�X�U��
{
	
}

bool Boss::FinBoss()						//�{�X�㏈��
{

	for (int i = 0; i < BOSS_MAX_NUM; i++)
	{
		if (Boss_is_alive) {
			//�{�X�������Ă���
			return false;
		}
	}

	//�{�X���|���ꂽ
	return true;
}