#include "DxLib.h"
#include "Transparent.h"

//������
int Flag = true;

//���ߊ֐�
int Transparent(int alpha)
{
	//���ߏ���
	//BottanAlphaFlag��true�̎��ɓ��߂���
	if (Flag)
	{
		alpha -= ALPHA_SPEED;
		
		//BottanAlpha��0�ȉ��̎�BottanAlphaFlag��false�ɂ���
		if (alpha <= 0)
		{
			Flag = false;
		}
		
	}
	//BottanAlphaFlag��false�̎��ɒʏ�ɖ߂�
	if (!Flag)
	{
		alpha += ALPHA_SPEED;

		//BottanAlpha��100�ȏ�̎�BottanAlphaFlag��true�ɂ���
		if (alpha >= 100)
		{
			Flag = true;
		}
		
	}
	return alpha;
	
}
