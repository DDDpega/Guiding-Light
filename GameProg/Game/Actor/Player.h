#pragma once

class Picture;

class Player : public Actor
{
public:

	struct LadderCol
	{
		int		num;
		bool	isLadder;
	};

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	Player(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance_,Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();


	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, TAG tag, TAG selftag);

	/// <summary>
	/// �Փ˂��Ă��Ȃ�
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, TAG tag);

	/// <summary>
	/// ���݃v���C���[�̃��C�g�����Ă��邩�ǂ���
	/// </summary>
	/// <returns></returns>
	bool GetLightOn() {
		return m_lightCmp->m_lightOn;
	}

	/// <summary>
	/// �v���C���[����肷��
	/// </summary>
	/// <returns></returns>
	Player* Getthis();

	void AddisLadder(int num,bool isladder);

	void SetisLadder(int num, bool isladder);

private:
	bool m_firstShot;
	std::shared_ptr<LightCmp> m_lightCmp;
	list <LadderCol> m_isLadder;
};