#pragma once

class DarkPictureCmp : public Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="actor"></param>
	/// <param name="picture"></param>
	DarkPictureCmp(Actor* actor, PICTURE_TYPE picture,int number);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~DarkPictureCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	shared_ptr<Picture> m_darkPicture;

protected:
	PICTURE_TYPE m_picture;
	int m_number;
};

