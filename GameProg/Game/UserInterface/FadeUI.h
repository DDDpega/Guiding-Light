#pragma once

class FadeUI :
    public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	FadeUI(bool isFirstTitle = false);

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
	/// �|�W�V������m_isMove�����Z�b�g����
	/// </summary>
	void Reset();

	/// <summary>
	/// Fade�𓮂���
	/// </summary>
	void MoveFeed(bool IsfeedIn,bool IsLeft);

private:
	shared_ptr<Picture> m_feedLeft;
	shared_ptr<Picture> m_feedRight;
	bool m_isFeedIn;
	bool m_isMove;
	bool m_isFirstTitle;
	bool m_isInitialize;
};

