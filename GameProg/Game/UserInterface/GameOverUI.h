#pragma once

class GameOverUI : public UserInterface
{
public:
	GameOverUI();

	~GameOverUI();

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

	void ChangeImage(int nowcursor);
	vector<shared_ptr<Picture>> m_picture;


protected:

};

