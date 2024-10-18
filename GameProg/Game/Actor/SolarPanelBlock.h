#pragma once

class SolarPanelBlock :public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	SolarPanelBlock(POINT pos,bool isBlock, Scene* scene);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~SolarPanelBlock();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance_, Scene* scene);

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

	bool GetIsBlock() {
		return m_isBlock;
	}

private:
	bool m_isBlock;
	Scene* m_scene;
};

