#pragma once


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
	void AddLineLightList(LineLightCmp* lightCmp);
	void AddClearLightList(ClearLightCmp* lightCmp);

protected:


	list<LightCmp*> lightCmpList;
	list<LineLightCmp*> lineLightCmpList;
	vector<ClearLightCmp*> clearLightCmpList;

	int x;
	int y;
};