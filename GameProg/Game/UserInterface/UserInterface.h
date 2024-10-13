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

};

