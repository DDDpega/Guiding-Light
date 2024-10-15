#pragma once

class UserInterface : public Picture
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	UserInterface(bool isVisible, bool isInput);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~UserInterface();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// UI�̃s�N�`���[���X�g�ɒǉ�����
	/// </summary>
	void AddPictureInUI(shared_ptr<Picture> picture);

protected:
	bool m_isInput;	//����\���ǂ���
	list<shared_ptr<Picture>> m_pictureList_UI;
	Game* m_gameInstance;
	Scene* m_sceneptr;
	int m_nowcursor;
	POINT m_nowpostion[3];
	std::shared_ptr<Picture> m_arrow;

	shared_ptr<Picture> m_startText[3];
	int m_alpha;	//�摜�̃A���t�@�l
	int m_add;		//�A���t�@�l�̕ύX����l�̗�
	bool m_isMenuActive;	//���j���[���
	shared_ptr<Picture> m_backGround;

	bool m_stage[20];	//�X�e�[�W�N���A���

	shared_ptr<Picture> m_stageArray[3];	//�X�e�[�W�I���̉摜
	POINT m_stageMarkers[3];	//�X�e�[�W�I���̈ʒu
};
