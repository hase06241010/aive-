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
	void SetAlive(const float bAlive);			//フラグ状態設定
	void InstBomb(const Math::Vector2 aBombPos);
	const Math::Vector2 CBomb::GetPos();		//座標取得

	void SetScrollPos(Math::Vector2 scrPos);

private:
	KdTexture* m_pTexture;		//画像
	Math::Vector2 m_pos;
	Math::Matrix m_mat;
	bool m_bAlive;
	int	 m_aCnt;
	int m_aTimer;
	Math::Vector2 m_scrollPos;
};
