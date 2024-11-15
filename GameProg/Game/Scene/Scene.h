#pragma once




class Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Scene( const char* name);

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

	bool m_isPause;			//�|�[�Y��Ԃ��ǂ���


protected:
	const char* m_sceneName;	//���݂̃V�[���̖��O
	shared_ptr<Sound>m_bgm;		//BGM
};