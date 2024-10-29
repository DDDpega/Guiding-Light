#pragma once

class Picture;
class Actor;

class LightPicture : public Picture
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	LightPicture();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~LightPicture();

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
	/// ���C�g��ǉ�����
	/// </summary>
	void AddLightList(shared_ptr<Picture> picture);

protected:
	int screenA;
	int screenB;
	int screenC;

	list<shared_ptr<Picture>> pictureList;

	int x;
	int y;
};