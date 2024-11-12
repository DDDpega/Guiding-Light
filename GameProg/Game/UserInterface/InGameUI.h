#pragma once

class InGameUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	InGameUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~InGameUI();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �c��̃��C�g�̐�
	/// </summary>
	/// <param name="num"></param>
	void ChangeLight(int num);


protected:
	shared_ptr<Picture> m_pictureLightNum;
};


