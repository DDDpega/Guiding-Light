#pragma once
#include "DxLib.h"

class Game;
class Scene;

enum PIVOT
{
	CENTER,LEFTUP
};

enum SORT
{
	SORT_UI,
	SORT_ACTOR,
	SORT_LIGHT,
	SORT_MAP,
	SORT_BACKGROUND,
};

class Picture
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Picture(POINT pos, float size, const TCHAR* picture, PIVOT pivot, SORT sort, bool isVisible=true);

	/// <summary>
	/// �`�悵�Ȃ�Picture
	/// </summary>
	Picture(SORT sort);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Picture();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// �摜�̕ύX
	/// </summary>
	/// <param name="picture"></param>
	void ChangePicture(const TCHAR* picture);

	/// <summary>
	/// ���݂̃|�W�V�����𓾂�
	/// </summary>
	/// <returns></returns>
	POINT GetPos() {
		return m_pos;
	}

	/// <summary>
	/// �|�W�V�����̕ύX
	/// </summary>
	/// <returns></returns>
	void SetPos(POINT changepos) {
		m_pos = changepos;
	}

	/// <summary>
	/// �����ڂ̕ύX
	/// </summary>
	/// <param name="islook"></param>
	void SetisLook(bool islook) {
		m_isVisible = islook;
	}

	SORT GetSort() {
		return m_sort;
	}

	bool m_isActive;			//�������邩�ǂ���

protected:
	SORT m_sort;			//�`�揇��
	POINT m_pos;			//�ʒu
	float m_size;		//�摜�̔{��
	int m_handle;				// �f�[�^�n���h���i�[�p�ϐ�
	const TCHAR* m_picture;	//�摜�̃t�@�C����
	int m_framecnt;			//�t���[���J�E���g
	int m_pictureSizeX;		//�摜�T�C�Y
	int m_pictureSizeY;		//�摜�T�C�Y
	PIVOT m_pivot;			//�摜�̒��S�ʒu
	bool m_isVisible;			//�����ڂ�����
	bool m_pictureNull;			//�`�悵�Ȃ�Picture
};

