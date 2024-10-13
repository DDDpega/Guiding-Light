#pragma once

class GamePauseUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GamePauseUI(bool isVisible);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GamePauseUI();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
};

