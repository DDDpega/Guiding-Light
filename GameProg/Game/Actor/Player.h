#pragma once

class Picture;

class Player : public Actor
{
public:
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
	void HitCollision(Actor* other, TAG tag);


private:
	bool m_firstShot;
	std::shared_ptr<Picture> lightPicture;
	int m_bulletframe;
};