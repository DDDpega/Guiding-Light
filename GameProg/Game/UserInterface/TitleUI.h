#pragma once

class TitleUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TitleUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~TitleUI();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
private:
	//shared_ptr<Picture> m_startText[3];
	//int m_alpha;	//�摜�̃A���t�@�l
	//int m_add;		//�A���t�@�l�̕ύX����l�̗�
	//bool m_isMenuActive;	//���j���[���
	//shared_ptr<Picture> m_backGround;
};

