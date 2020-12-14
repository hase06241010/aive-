#pragma once

//��ʏ��
namespace Screen
{
	const int Width = 1280;				//��ʕ�
	const int Height = 720;				//��ʍ�
	const int HalfWidth = Width / 2;	//��ʕ�����
	const int HalfHeight = Height / 2;	//��ʍ�����

}

//�L�������
namespace Infor
{
	//���a���
	const float RADIUS_32 = 32.0f;
	const float RADIUS_16 = 16.0f;
	const float RADIUS_8 = 8.0f;

}

//�ėp������
namespace Utility
{
	/*�����蔻�菈��*/
	//0��1��Ԋҁi�L�����P���W�A�L�����P�ړ��ʁA�L�����Q���W�A�L�����P���a�A�L�����Q���a�j
	bool bHitCheck(Math::Vector2 aScrPos,Math::Vector2 aScrMove, Math::Vector2 aDestPos, float aScrRad, float aDesRad);				
	//0�܂���1�`4��Ԋ�
	int  iHitCheck(Math::Vector2 aScrPos,Math::Vector2 aScrMove, float aDestPosX, float aDestPosY, float aScrRad, float aDesRad);

}