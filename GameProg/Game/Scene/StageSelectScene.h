#pragma once
#include "Scene.h"
class StageSelectScene :public Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	StageSelectScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~StageSelectScene();

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

protected:
	int m_stageNum;
};

