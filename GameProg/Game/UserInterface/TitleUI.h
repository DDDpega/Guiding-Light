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

	/// <summary>
	/// �v���C���[��animation
	/// </summary>
	void PlayerAnim();


	bool m_isVideo;			//���悪�������ǂ���
	bool m_isVideoPlay;		//���悪����Ă��邩�ǂ���
private:
	shared_ptr<Picture> m_startText[3];
	shared_ptr<Picture> m_gameExitText;
	shared_ptr<Picture> m_lamp;
	bool m_isMenuActive;	//���j���[���
	bool m_isFirst;
	shared_ptr<Picture> m_fadeUI;
	shared_ptr<Picture> m_player;
	int m_waittime;
	int m_frame;
	int m_lampFrame;
	int m_animCnt;						//animation�̉摜�؂�ւ�
	bool m_animMax;						//animation�̉摜�̍ő�ɂȂ邩�ǂ���
	shared_ptr<Sound> m_startSound;		//�X�^�[�g����SE
};

