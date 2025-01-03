#pragma once

class InteractKeyCmp : public Component
{
public:
	InteractKeyCmp(Actor* actor, E_INTERACT_KIND kind);

	virtual ~InteractKeyCmp();

	/// <summary>
	/// ����������
	/// </summary>
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
	/// �摜���폜����
	/// </summary>
	void DeletePicture();

	/// <summary>
	/// �p�����[�^�[�ݒ�
	/// </summary>
	void SetParam(E_INTERACT_KIND kind);

	/// <summary>
	/// �摜�؂�ւ�
	/// </summary>
	void PictureSwitch();

	/// <summary>
	/// ���͂���������摜���폜����
	/// </summary>
	void IsInput_PictureDelete();

	shared_ptr<Picture> m_interactPicture;
	E_INTERACT_KIND m_interactKind;
	int m_pictureNum;
};

