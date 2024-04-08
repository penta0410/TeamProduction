#include <math.h>
#include "DxLib.h"
#include "play.h"
#include "../Scene.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Common.h"
#include "../Play/play.h"
#include "../../Screen/Screen.h"

//=============================
// �v���C�V�[��
//=============================

Play::Play() {}		//�R���X�g���N�^
Play::~Play() {}	//�f�X�g���N�^

//�v���C�V�[���摜�p�X
const char* PLAY_IMAGE_PATH[PLAY_IMAGE_NUMBER] =
{
	PLAY_BACK_PATH,		//�v���C�w�i�p�X
	ITEM_SELECT_PATH,	//�Ŕp�X

};

//�v���C������  
void Play::InitPlay()
{
	//�v���C���[������
	m_player.Init();

	//�v���C���[�ǂݍ���
	m_player.LoadPlayer();

	//�G������
	m_enemy.InitEnemy();

	//�G�ǂݍ���
	m_enemy.LoadEnemy();

	//�G�e������
	m_enemy.InitEnemyBullet();

	//�G�e�ǂݍ���
	m_enemy.LoadEnemyBullet();
	
	//�w�i���W
	m_Back_x = BACK_X;
	m_Back_y = BACK_Y;
	m_Back_x_2 = -m_Back_x;
	m_Back_y_2 = -m_Back_y;

	m_SignBoard_x[0] = 500;
	m_SignBoard_x[1] = 800;
	
	m_SignBoard_y[1] = -1400;
	m_SignBoard_y[2] = -2600;
	m_SignBoard_y[3] = -3800;
	m_SignBoard_y[4] = -5000;

	m_scrollFlame = 0;		//�X�N���[���t���[��

	m_imagehandle[0] = LoadGraph(PLAY_IMAGE_PATH[0]);	//�v���C�w�i�摜
	m_imagehandle[1] = LoadGraph(PLAY_IMAGE_PATH[1]);	//�Ŕ�

	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�ʏ폈��
void Play::StepPlay(int hp)
{
	//�t���[���J�E���g
	m_scrollFlame++;

	//�v���C�V�[���ɍs����3�b��~
	if (m_scrollFlame >= 180)
	{
		m_Back_y += BACK_SPEED;
		m_Back_y_2 += BACK_SPEED;
	}

	//�X�N���[������
	if (m_Back_y > 360 + 710)
	{
		m_Back_y = -BACK_Y;
	}
	if (m_Back_y_2 > 360 + 710)
	{
		m_Back_y_2 = -BACK_Y;
	}




	//�G�e���ˏ����@�@����
	m_enemy.shotEnemyBullet();

	//�G�e�ړ������@�@����
	m_enemy.MoveEnemyBullet();

	//�G�ʏ폈��
	m_enemy.StepEnemy();

	//�G�����@�@����
	m_enemy.KillEnemy();

	//�v���C���[����
	m_player.MovePlayer();

	//�N���A�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�v���C�V�[���t���O���N���A�V�[���ɕύX
		m_SceneFlag = 0;

		//'�v���C�㏈��'�ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	}

	//�Q�[���I�[�o�[�V�[���ւ̑J��
	//Tab�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		//�v���C�V�[���t���O���N���A�V�[���ɕύX
		m_SceneFlag = 1;

		//'�v���C�㏈��'�ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	}
	//�����蔻��
	for (int m_enemy_num = 0; m_enemy_num <= ENEMY_MAX_NUM; m_enemy_num++)
	{
		if (m_player.IsHit_Enemy(m_enemy.EnemyPosx[m_enemy_num], m_enemy.EnemyPosx[m_enemy_num], m_enemy.Radius))
		{
			//�v���C�V�[���t���O���N���A�V�[���ɕύX
			m_SceneFlag = 1;

			//'�v���C�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		}
	}
}

//�v���C�`�揈��
void Play::DrawPlay(int hp)
{
	//�v���C�w�i�`��
	DrawRotaGraph(m_Back_x, m_Back_y, 1.0f, 0.0f, m_imagehandle[0], true);
	DrawRotaGraph(m_Back_x, m_Back_y_2, 1.0f, 0.0f, m_imagehandle[0], true);


	//�Ŕ`��
	for (int i = 0; i < 5; i++)
	{
		/*DrawRotaGraph(m_SignBoard_x[i], m_SignBoard_y[i], 1.0f, 0.0f, m_imagehandle[1], true);*/
	}

	//�v���C���[�`��
	m_player.DrawPlayer();
	
	//�G�`��@�@����
	m_enemy.DrawEnemy();
	m_enemy.DrawEnemyBullet();

}

//�v���C�㏈��
void Play::FinPlay()
{
	//�摜����
	for (int i = 0; i < PLAY_IMAGE_NUMBER; i++)
	{
		DeleteGraph(m_imagehandle[i]);
	}

	//�N���A�V�[����
	if (m_SceneFlag == 0)
	{
		//�Q�[���N���A�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}

	//�Q�[���I�[�o�[�V�[����
	if (m_SceneFlag == 1)
	{
		//�Q�[���I�[�o�[�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;

	}
}


