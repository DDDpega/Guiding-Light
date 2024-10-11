#pragma once
#include "Picture.h"
#include "DxLib.h"

class LightPicture : public Picture
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	LightPicture(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~LightPicture();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
};