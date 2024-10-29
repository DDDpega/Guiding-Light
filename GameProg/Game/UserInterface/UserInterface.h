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
	virtual void Initialize();

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
	list<shared_ptr<Picture>> m_pictureList_UI;	//UI�̒��ŕ\������摜�̃��X�g
	int m_nowcursor;							//���݂̃J�[�\���ʒu
	POINT m_nowpostion[3];						//
	std::shared_ptr<Picture> m_arrow;			//���̉摜
	int m_fontHandle;	//�t�H���g

	int m_alpha;	//�摜�̃A���t�@�l
	int m_add;		//�A���t�@�l�̕ύX����l�̗�
	shared_ptr<Picture> m_backGround;

	
};
