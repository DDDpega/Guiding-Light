#pragma once


class Game;

class Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Scene(Game* gameInstance, const char* name);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Scene();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();


	int screenX, screenY;	//��ʃT�C�Y


protected:
	const char* m_sceneName;	//���݂̃V�[���̖��O
	bool m_isPause;			//�|�[�Y��Ԃ��ǂ���
	Game* m_gameInstance;		//�Q�[���C���X�^���X
};