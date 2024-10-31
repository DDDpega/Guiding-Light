#pragma once

class Picture;
class LightCmp;

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
	void AddLightList(LightCmp* lightCmp);

protected:
	int screenA;
	int screenB;
	int screenC;

	list<LightCmp*> lightCmpList;

	int x;
	int y;
};