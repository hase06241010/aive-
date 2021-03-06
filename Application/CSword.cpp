#include "CSword.h"

CSword::CSword()
	:m_pTexture(nullptr)
	,m_pos(0,0)
	,m_move(0,0)
	,m_mat()
	,m_bSlash(false)
{
}

CSword::~CSword()
{
}

//初期化
void CSword::Init()
{
	m_pos = { 0,0 };
	m_move = { 0,0 };
	m_bSlash = false;
	m_direction = 0;
	m_scrollPos = { 0,0 };

}

//更新処理
void CSword::Updata()
{
	if (!m_bSlash)return;

	m_move = { 0,0 };

	//攻撃方向
	switch (m_direction) {
	case 0:
		m_move.y = 64;
		m_pos.y += m_move.y;
		break;
	case 1:
		m_move.y = -64;
		m_pos.y += m_move.y;
		break;
	case 2:
		m_move.x = -64;
		m_pos.x += m_move.x;
		break;
	case 3:
		m_move.x = 64;
		m_pos.x += m_move.x;
		break;
	}

	const int CNT_MAX = 2;
	if (m_slashCnt >= CNT_MAX)
	{
		m_bSlash = false;
		m_slashCnt = 0;
	}
	m_slashCnt++;

	//行列作成
	m_mat = DirectX::XMMatrixTranslation(m_pos.x, m_pos.y, 0.0f);
}

//描画処理
void CSword::Draw()
{
	if (!m_bSlash) return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_pTexture, Math::Rectangle(0, 0, 64, 64), 1.0f);

}

//テクスチャ設定
void CSword::SetTexture(KdTexture* apTexture)
{
	if (apTexture == nullptr)return;

	m_pTexture = apTexture;
}

//座標取得
const Math::Vector2 CSword::GetPos()
{
	return m_pos;
}

//移動量取得
const Math::Vector2 CSword::GetMove()
{
	return m_move;
}

//攻撃処理
void CSword::Slash(Math::Vector2 Pos, const int Direct)
{
	m_bSlash = true;
	m_pos = Pos;
	m_direction = Direct;
}

//フラグ状態取得
const bool CSword::bGetSlash()
{
	return m_bSlash;
}


void CSword::SetScrollPos(Math::Vector2 scrPos)
{
	m_scrollPos = scrPos;
}
