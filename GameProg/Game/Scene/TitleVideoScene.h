#pragma once

class TitleVideoScene :
    public Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TitleVideoScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~TitleVideoScene();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();
private:
	int m_waitTime;
	int m_videoHandle;
};

