#pragma once
#include "Scene.h"
class OptionScene :
    public Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	OptionScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~OptionScene();

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
private:
};

