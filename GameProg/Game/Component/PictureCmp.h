#pragma once

class PictureCmp : public Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="actor">�e�A�N�^�[</param>
	PictureCmp(Actor* actor, float size, const char* picture, E_PIVOT pivot, E_SORT sort);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~PictureCmp();

	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="gameInstance_">�Q�[���C���X�^���X</param>
	/// <param name="scene">�V�[���̃|�C���^</param>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();


	/// <summary>
	/// �摜
	/// </summary>
	shared_ptr<Picture> m_picture;

private:
	
	/// <summary>
	/// �摜�̏��
	/// </summary>
	const char* m_pictureType;

	/// <summary>
	/// �摜�̃T�C�Y
	/// </summary>
	float m_size;

	E_PIVOT m_pivot;
	E_SORT m_sort;
};