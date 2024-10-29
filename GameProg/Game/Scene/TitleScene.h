#pragma once


class Picture;

class TitleScene : public Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TitleScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~TitleScene();

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
	POINT m_nowpostion[3];
	int m_nowcursor;
	std::shared_ptr<Picture> m_arrow;
};
