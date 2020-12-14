#pragma once

class Scene;

class CBomb
{
public:
	CBomb();
	~CBomb();

	void Init();
	void Updata();
	void Draw();
	const bool IsAlive();
	void SetTexture(KdTexture* apTexture);
	void SetAlive(const float bAlive);			//�t���O��Ԑݒ�
	void InstBomb(const Math::Vector2 aBombPos);
	const Math::Vector2 CBomb::GetPos();		//���W�擾

private:
	KdTexture* m_pTexture;		//�摜
	Math::Vector2 m_pos;
	Math::Matrix m_mat;
	bool m_bAlive;
	int	 m_aCnt;
	int m_aTimer;
};
