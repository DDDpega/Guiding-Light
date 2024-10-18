#pragma once


class Picture;

class TitleScene : public Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TitleScene(Game* gameInstance);

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

	/// <summary>
	/// Player�̃Q�b�^�[
	/// </summary>
	Player* GetPlayer() {
		return nullptr;
	}

private:
	POINT m_nowpostion[3];
	int m_nowcursor;
	std::shared_ptr<Picture> m_arrow;
};
