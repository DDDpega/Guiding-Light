#pragma once

class Slider : public Picture
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Slider(Point barCenter, int max, int iniNum, float barSize, float pinchSize);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Slider();

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


	void ReloadPicture();

	/// <summary>
	/// �E�Ɉړ�
	/// </summary>
	/// <returns></returns>
	int RightMove();

	/// <summary>
	/// ���Ɉړ�
	/// </summary>
	/// <returns></returns>
	int LeftMove();


	bool m_isOperation;
protected:
	shared_ptr<Picture> m_bar;
	shared_ptr<Picture> m_bar2;
	shared_ptr<Picture> m_pinch;

	Point m_barCenter;
	int m_max;
	int m_num;

	float m_plusX;

	float m_barSize;
	float m_pinchSize;
};

