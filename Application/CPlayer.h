#pragma once

#include"CBullet.h"
#include"CSword.h"
#include"CBomb.h"

//�N���X�̑O���錾
class Scene;

enum eDirection	//�����Ă������
{
	Up,
	Down,
	Left,
	Right
};

//����Z���N�g
enum eClick
{
	eShuriken,
	eSword,
	eBomb
};

//�藠���̗v�f��
constexpr int BULLET_MAX = 20;

//�v���C���[�N���X
class CPlayer
{
public:

	CPlayer();	//�R���X�g���N�^
	~CPlayer();	//�f�X�g���N�^

	//�v���C���[
	void Init();
	void Updata();
	void Draw();
	const bool IsAlive();
	void SetTexture(KdTexture* apTexture);
	void SetBulletTexture(KdTexture* apTexture);
	void SetSlashTexture(KdTexture* apTexture);
	void SetBombTexture(KdTexture* apTexture);
	void SetOwner(Scene* apOwner);

	Math::Vector2 GetScrPos();
	const Math::Vector2 GetPos();		//�v���C���[���W�擾
	const int GetHp();
	

private:		//�O������A�N�Z�X�s��

	eDirection		m_direction;
	eClick			m_LClick;
	eClick			m_RClick;

	KdTexture* m_pTexture;//�摜(�e�N�X�`��)
	Math::Vector2	 m_pos;		//���W
	Math::Vector2	 m_moveVal;	//�ړ���
	Math::Matrix	 m_mat;		//�s��
	bool			 m_bAlive;  //�����t���O
	Scene* m_pOwner;	//�I�[�i�[�擾�p
	int	m_hp;					//HP
	int m_hpCount;				//���G����
	float m_alpha;				//�摜�̓����x

	void HitCheckMap();			//�}�b�v�Ƃ̓����蔻��
	void HitCheckEnemy();		//�G�Ƃ̓����蔻��
	void InviTime();			//���G����

	CBullet m_bulletList[BULLET_MAX];
	void SetShuriken();
	CSword  m_swordList;
	void SetSword();
	CBomb  m_bombList;
	void SetBomb();
};