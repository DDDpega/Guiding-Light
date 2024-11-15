#pragma once

class TitleVideoUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TitleVideoUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~TitleVideoUI();

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
	shared_ptr<Picture> m_startText;
	shared_ptr<Picture> m_demoText;

};

