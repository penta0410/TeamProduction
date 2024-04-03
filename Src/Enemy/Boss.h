#pragma once
#include "enemy.h"

#define BOSS_IMAGE_PATH				//�{�X�摜�p�X
#define BOSS_EXPERIENCE	  (5)		//�{�X�o���l
#define	BOSS_POINT		  (10)		//�{�X����l���ł��链�_
#define	BOSS_HP			  (20)		//�{�X�f�t�H���g�̗�
#define BOSS_ATK		  (3)		//�{�X�f�t�H���g�U����
#define BOSS_W						//�{�X���T�C�Y
#define BOSS_H						//�{�X�c�T�C�Y

class Boss:public Enemy
{
public:

	int Boss_handle = 0;			//�{�X�摜�n���h��
	int Boss_experience = 0;		//�{�X�̌o���l
	int Boss_point = 0;				//�{�X�̓��_
	int Boss_HP = 0;				//�{�X�̗̑�
	int Boss_ATK = 0;				//�{�X�̍U����
	float BossX = 0.0f;				//�{�X��X���W
	float BossY = 0.0f;				//�{�X��Y���W
	bool  Boss_is_alive;			//�{�X�����t���O

	Boss();							//�R���X�g���N�^
	~Boss();						//�f�X�g���N�^

	//�{�X������
	void InitBoss();

	//�{�X�`��
	void DrawBoss();

	//�{�X�U��
	void ATKBoss();

	//�{�X�S�Ń`�F�b�N
	/*bool KillBoss();*/

};
