#pragma once

class BatteryPictureCmp : public Component
{
public:
	BatteryPictureCmp(Actor* actor);

	virtual ~BatteryPictureCmp();

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

	/// <summary>
	/// �p�����[�^�[�ݒ�
	/// </summary>
	void SetParam(int maxFrame,int start);

	/// <summary>
	/// ���݂̃t���[���𑗐M����
	/// </summary>
	/// <param name="frame"></param>
	void NowFrame(int frame);

private:

	shared_ptr<Picture> m_batteryPicture;
	int m_maxFrame;
	int m_nowFrame;
	int m_pictureNumber;
	bool up;
};

