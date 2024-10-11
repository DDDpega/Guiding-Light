#pragma once

#include "include.h"
#include "ActorManager.h"
#include "CollisionManeger.h"
#include "SceneManeger.h"
#include "PictureManeger.h"

//�}�l�[�W���[�̃N���X
class ActorManager;
class CollisionManeger;
class PictureManeger;
class SceneManeger;

class Status;

class Game 
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Game();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Game();

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

	/// <summary>
	/// �e��X�e�[�^�X����肷��
	/// </summary>
	/// <returns></returns>
	Status* GetStatus() {
		return m_status;
	}

	/// <summary>
	/// actorManager�̃Q�b�^�[
	/// </summary>
	ActorManager* GetActorMNG() const {
		return m_actorMNG;
	}

	/// <summary>
	/// �V�[���}�l�[�W���[�̃Q�b�^�[
	/// </summary>
	/// <returns></returns>
	SceneManeger* GetSceneMNG() {
		return m_sceneMNG;
	}

	/// <summary>
	/// �R���W�����}�l�[�W���[����肷��
	/// </summary>
	/// <returns></returns>
	CollisionManeger* GetCollisionMNG() {
		return m_collisionMNG;
	}

	/// <summary>
	/// �s�N�`���[�}�l�[�W���[����肷��
	/// </summary>
	/// <returns></returns>
	PictureManeger* GetPictureMNG() {
		return m_pictureMNG;
	}

private:
	//�}�l�[�W���[�̐錾
	ActorManager* m_actorMNG;
	CollisionManeger* m_collisionMNG;
	PictureManeger* m_pictureMNG;
	SceneManeger* m_sceneMNG;

	//�X�e�[�^�X
	Status* m_status;
};

