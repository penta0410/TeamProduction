#include "DxLib.h"
#include "Boss.h"
#include "enemy.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"


void Boss::InitBoss()						//�v���C������
{
	Boss_handle = 0;						//�摜�n���h��

	Boss_ATK = BOSS_ATK;					//�{�X�U����
	Boss_HP = BOSS_HP;						//�{�X�̗�
	Boss_point = BOSS_POINT;				//�{�X�|�C���g
	Boss_experience = BOSS_EXPERIENCE;


}

void Boss::DrawBoss()						//�{�X�`��
{

}

void Boss::ATKBoss()						//�{�X�U��
{

}

//bool Boss::KillBoss()						//�{�X�S�Ń`�F�b�N
//{
//
//}