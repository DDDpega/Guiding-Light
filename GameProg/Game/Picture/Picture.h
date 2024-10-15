#pragma once


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
	Picture(POINT pos, float size, const TCHAR* picture, PIVOT pivot, SORT sort, bool isVisible = true, bool isAlpha = false);

	/// <summary>
	/// �`�悵�Ȃ�Picture
	/// </summary>
	Picture(SORT sort, bool isVisible);

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
	void SetisVisible(bool islook) {
		m_isVisible = islook;
	}

	/// <summary>
	/// �����ڂ̎擾
	/// </summary>
	/// <returns></returns>
	bool GetisVisible() {
		return m_isVisible;
	}

	SORT GetSort() {
		return m_sort;
	}

	/// <summary>
	/// �A���t�@�l�ɉ����ĕs�����x��ύX����
	/// </summary>
	/// <param name="alpha">�A���t�@�l</param>
	void SetAlpha(int alpha);

	/// <summary>
	/// �A���t�@�l��ύX���\�ɂ���Z�b�^�[
	/// </summary>
	/// <param name="isAlpha">�A���t�@�l��ύX���\���ǂ���</param>
	void SetIsAlpha(bool isAlpha) {
		m_isAlpha = isAlpha;
	}

	bool m_isActive;			//�������邩�ǂ���
	int m_pictureSizeX;		//�摜�T�C�Y
	int m_pictureSizeY;		//�摜�T�C�Y
	float m_size;		//�摜�̔{��
	int m_handle;				// �f�[�^�n���h���i�[�p�ϐ�

	Scene* m_sceneptr;
	Game* m_gameInstance;

protected:
	SORT m_sort;			//�`�揇��
	POINT m_pos;			//�ʒu
	const TCHAR* m_picture;	//�摜�̃t�@�C����
	int m_framecnt;			//�t���[���J�E���g
	PIVOT m_pivot;			//�摜�̒��S�ʒu
	bool m_isVisible;			//�����ڂ�����
	bool m_pictureNull;			//�`�悵�Ȃ�Picture
	bool m_isAlpha;			//�A���t�@�l��ύX
	int m_alpha;			//�A���t�@�l
};

