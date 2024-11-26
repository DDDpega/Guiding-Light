#pragma once

class CreditUI :
    public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CreditUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CreditUI();

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

private:
	shared_ptr<Picture> m_nameText[5];
	shared_ptr<Picture> m_jobText[3];
	shared_ptr<Picture> m_creditTitle;



};

