#pragma once

class StageSelectUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	StageSelectUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~StageSelectUI();

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

	void LordFile();
private:

};

