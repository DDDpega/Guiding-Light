#pragma once
#include "Scene.h"
class CreditScene :
    public Scene
{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CreditScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CreditScene();

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

