#pragma once

class CSword
{
public:
	CSword();
	~CSword();

	void Init();
	void Updata();
	void Draw();
	void SetTexture(KdTexture* apTexture);
	
	//�U������
	void Slash(Math::Vector2 Pos, const int Direct);
	const bool bGetSlash();		//�t���O��Ԏ擾

private:

	KdTexture*		 m_pTexture;	//�摜(�e�N�X�`��)
	Math::Vector2	 m_pos;			//���W
	Math::Vector2	 m_move;		//���W
	Math::Matrix	 m_mat;			//�s��
	bool			 m_bSlash;		//�U���t���O
	int				 m_slashCnt;	//�U����������
	int				 m_direction;	//����
};
