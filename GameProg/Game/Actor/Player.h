#pragma once
#include "Actor.h"
#include <memory>
#include "ActorManager.h"


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

	/// <summary>
	/// ����
	/// </summary>
	void Shot();

	/// <summary>
	/// �A�N�^�[��ǉ����郁�\�b�h
	/// </summary>
	/// <param name="actor"></param>
	void AddChild(Scene* scene);

private:
	bool m_firstShot;
	shared_ptr<Picture> lightPicture;
	int m_bulletframe;
};