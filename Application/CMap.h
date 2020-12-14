#pragma once

//�}�b�v�V�[��
enum eSceneData
{
	OutSide,	//��O
	OneFloor,	//1�K�w
	TwoFloor	//2�K�w
};

class Scene;

constexpr int MAP_CHIP_H = 40;					//�c�T�C�Y
constexpr int MAP_CHIP_W = 40;					//���T�C�Y

class CMap
{
public:
	CMap();
	~CMap();

	void Init();
	void Update();
	void Draw();
	void SetTexture(KdTexture* apTexture);
	float (*GetPosX())[MAP_CHIP_W];		//X���W�擾
	float (*GetPosY())[MAP_CHIP_W];		//Y���W�擾
	int (*GetChipData())[MAP_CHIP_W];	//�}�b�v�f�[�^�擾
	Math::Vector2 GetscrollPos();		//�X�N���[���ʎ擾
	void SetOwner(Scene* apOwner);		//�I�[�i�[�ݒ�
	void SetMapData();					//�}�b�v�f�[�^�̕ύX

	void LoadMapFile();		//�}�b�v�t�@�C���ǂݍ���
	void CreateConsole();	// �R���\�[���쐬
	void DestroyConsole();	// �R���\�[���j��

private:

	eSceneData			mapData;

	KdTexture*			m_pTexture;								//�摜(�e�N�X�`��)
	int					m_ChipData[MAP_CHIP_H][MAP_CHIP_W];		//�}�b�v�f�[�^
	float				m_chipX[MAP_CHIP_H][MAP_CHIP_W];		//���W
	float				m_chipY[MAP_CHIP_H][MAP_CHIP_W];		//���W
	Math::Matrix		m_mat[MAP_CHIP_H][MAP_CHIP_W];			//�s��
	Math::Vector2		m_scroll;								//�X�N���[����
	Scene* m_pOwner;											//�I�[�i�[�擾�p

	void Scroll();			//�X�N���[������
	void ScrollRemit();		//��ʒ[���~�b�g

	FILE* fp_c;			//�R���\�[���p
	

};
