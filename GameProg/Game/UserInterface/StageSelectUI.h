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
	bool m_stage[20];	//�X�e�[�W�N���A���

	shared_ptr<Picture> m_stageArray[3];	//�X�e�[�W�I���̉摜
	POINT m_stageMarkers[3];	//�X�e�[�W�I���̈ʒu
};

