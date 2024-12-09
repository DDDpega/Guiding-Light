#pragma once

class ClearLightCmp : public Component
{
public:
	ClearLightCmp(Actor* actor);

	virtual ~ClearLightCmp();

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

	shared_ptr<Picture> m_lightPicture;

private :
	int m_framecnt;
};

