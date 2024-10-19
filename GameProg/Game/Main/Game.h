#pragma once

//�}�l�[�W���[�̃N���X

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

	InputManager* GetInputMNG() {
		return m_inputMNG;
	}

private:
	//�}�l�[�W���[�̐錾
	CollisionManeger* m_collisionMNG;
	PictureManeger* m_pictureMNG;
	SceneManeger* m_sceneMNG;
	InputManager* m_inputMNG;

	//�X�e�[�^�X
	Status* m_status;
};

