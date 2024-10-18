#pragma once

class InGameUI : public UserInterface
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	InGameUI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~InGameUI();

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

	/// <summary>
	/// �c��̃��C�g�̐�
	/// </summary>
	/// <param name="num"></param>
	void ChangeLight(int num) {
		m_lightnum = num;
	}


protected:
	int m_stageNum;		//�X�e�[�W��
	int m_lightnum;		//�c��̃��C�g�̐�
};


