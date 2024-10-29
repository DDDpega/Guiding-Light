#pragma once

class ActorManager
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="gameInstance">�Q�[���C���X�^���X</param>
	ActorManager();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~ActorManager();

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
	/// �A�N�^�[���쐬����
	/// </summary>
	/// <param name="actor">�쐬�����A�N�^�[</param>
	void AddActor(shared_ptr<Actor> actor);

	/// <summary>
	/// ���X�g�̍폜
	/// </summary>
	void CleanList() {
		m_actorList.clear();
		m_waitList.clear();
	}

private:

	/// <summary>
	/// �����̃A�N�^�[���X�g
	/// </summary>
	vector<shared_ptr<Actor>> m_actorList;
	vector<shared_ptr<Actor>> m_waitList;
};

