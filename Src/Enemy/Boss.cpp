#include "DxLib.h"
#include "Boss.h"
#include "../Common.h"
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

//�{�X�e������
void InitBossBullet()
{
	for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
	{
		bossbulletIndex->bosshandle = 0;
		bossbulletIndex->x = 0;
		bossbulletIndex->y = 0;
		bossbulletIndex->BossbulletUse = false;
	}
}

//bool Boss::BossShotBullet(int shotPosX, int shotPosY)
//{
//	for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
//	{
//		if (bossbulletIndex[i].BossbulletUse)
//		{
//			//�e���W�̏����ʒu�ɓG�̍��W
//			bossbulletIndex[i].x = shotPosX;
//			bossbulletIndex[i].y = shotPosY + BOSS_H;
//			bossbulletIndex[i].BossbulletUse = true;
//
//			//���ː���
//			return true;
//		}
//	}
//	//���s
//	return false;
//}

//�{�X�e�ǂݍ���
void Boss::LoadBossBullet()
{
	//bossbulletIndex->bosshandle = LoadGraph(BOSS_BULLET_PATH);
}

//�{�X�e�`��
void Boss::DrawBossBullet()
{
	/*for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
	{
		if (bossbulletIndex->isuse)
		{
			DrawRotaGraph();
		}
	}*/
}

//�{�X�e�ړ�����
void Boss::MoveBossBullet()
{
	for (int i = 0; i < BOSS_BULLET_MAX_NUM; i++)
	{
		if (bossbulletIndex[i].BossbulletUse)
		{
			bossbulletIndex->y += 3;

			//��ʊO�ɏo���疢�g�p�ɖ߂�
			if (bossbulletIndex[i].y < WINDOW_HEIGHT)
			{
				bossbulletIndex->BossbulletUse = false;
			}
		}
	}
}
