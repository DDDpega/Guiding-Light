#pragma once


class TitleUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TitleUI(bool isFirst);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~TitleUI();

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
	/// �t�F�[�h�C���A�E�g���Ǘ�
	/// </summary>
	/// <param name="frame"></param>
	void FadeInOut(bool isFadeIn);


	bool m_isVideo;			//���悪�������ǂ���
	bool m_isVideoPlay;		//���悪����Ă��邩�ǂ���
private:
	shared_ptr<Picture> m_startText[3];
	shared_ptr<Picture> m_gameExitText;
	bool m_isMenuActive;	//���j���[���
	bool m_isFirst;
	shared_ptr<Picture> m_fadeUI;

};

