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
	bool m_isPause;			//�|�[�Y��Ԃ��ǂ���


protected:
	const char* m_sceneName;	//���݂̃V�[���̖��O
	Game* m_gameInstance;		//�Q�[���C���X�^���X
};