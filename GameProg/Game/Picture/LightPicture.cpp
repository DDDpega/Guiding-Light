#include "Framework.h"



LightPicture::LightPicture()
	:Picture(SORT::SORT_LIGHT,true)
{

}

LightPicture::~LightPicture()
{

}

void LightPicture::Initialize(Game* gameInstance, Scene* scene)
{
	Picture::Initialize(gameInstance, scene);

	x = scene->screenX;
	y = scene->screenY;
}

void LightPicture::Update()
{
	Picture::Update();
}

void LightPicture::Draw()
{
	//�摜��`�悷�邽�߂̃X�N���[�����쐬����
	screenA = MakeScreen(x, y, true);
	screenB = MakeScreen(x, y, true);
	screenC = MakeScreen(x, y, true);

	//�X�N���[����F�œh��Ԃ�
	FillGraph(screenA, 0, 0, 0, 255);		//�^����
	FillGraph(screenB, 0, 0, 0, 0);	//���ɉ摜��`��
	FillGraph(screenC, 255, 255, 255, 255);		//�Ȃɂ��Ȃ�

	//�X�N���[����ݒ肷��
	SetDrawScreen(screenB);

	//-----
	//���C�g��`�悷��
	for (auto& c : pictureList) {
		DrawRotaGraph2(c->GetPos().x, c->GetPos().y,
			(c->m_pictureSizeX / 2), (c->m_pictureSizeY / 2),
			c->m_size, 0, c->m_handle, true);
	}
	//------
	
	//�ԐF�����𓧖������Ɉڂ��ւ���
	GraphBlendBlt(screenB, screenB, screenB, 255,
		DX_GRAPH_BLEND_RGBA_SELECT_MIX,
		DX_RGBA_SELECT_SRC_R,
		DX_RGBA_SELECT_SRC_G,
		DX_RGBA_SELECT_SRC_B,
		DX_RGBA_SELECT_SRC_INV_R
	);

	//���������݂̂�screenA�Ɉڂ��ւ������̂�screenC�ɂ���
	GraphBlendBlt(screenA, screenB, screenC, 255,
		DX_GRAPH_BLEND_MULTIPLE_A_ONLY);

	//��ʂ����ɖ߂�
	SetDrawScreen(DX_SCREEN_BACK);


	//���߃��[�h�ɕς���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//�X�N���[����`�悷��
	DrawGraph(0, 0, screenC, true);

	//�X�N���[�����폜����
	DeleteGraph(screenA);
	DeleteGraph(screenB);
	DeleteGraph(screenC);
}

void LightPicture::AddLightList(shared_ptr<Picture> picture)
{
	picture->Initialize(m_gameInstance,m_sceneptr);
	pictureList.push_back(picture);
}