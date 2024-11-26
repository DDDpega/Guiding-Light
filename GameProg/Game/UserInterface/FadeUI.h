#pragma once

class FadeUI :
    public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	FadeUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~FadeUI();

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
	/// Fade�𓮂���
	/// </summary>
	void MoveFeed(bool IsfeedIn);

private:
	shared_ptr<Picture> m_feedIn;
	shared_ptr<Picture> m_feedOut;
	bool m_isFeedIn;
};

