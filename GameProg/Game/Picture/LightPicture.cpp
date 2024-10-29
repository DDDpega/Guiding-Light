#include "Framework.h"



LightPicture::LightPicture()
	:Picture(E_SORT::SORT_LIGHT,true)
{

}

LightPicture::~LightPicture()
{

}

void LightPicture::Initialize()
{
	Picture::Initialize();

	x = WINDOW_INFO::GAME_WIDTH;
	y = WINDOW_INFO::GAME_HEIGHT;
}

void LightPicture::Update()
{
	Picture::Update();

	//�s�N�`���[���X�g�̈ꕔ�폜
	for (auto i = pictureList.cbegin(); i != pictureList.cend();) {
		if (i->get()->m_isActive) {
			i++;
		}
		else {
			i = pictureList.erase(i);
		}
	}
}

void LightPicture::Draw()
{
	//���߃��[�h�ɕς���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//�摜��`�悷�邽�߂̃X�N���[�����쐬����
	screenA = MakeScreen(x, y, true);
	screenB = MakeScreen(x, y, true);
	screenC = MakeScreen(x, y, true);

	//�X�N���[����F�œh��Ԃ�
	FillGraph(screenA, 0, 0, 0, 255);			//��
	FillGraph(screenB, 0, 0, 0, 255);			//���ɉ摜��`��
	FillGraph(screenC, 255, 255, 255, 255);		//�^����

	//�X�N���[����ݒ肷��
	SetDrawScreen(screenB);

	//----------------------------------------------------------------------
	//���C�g��`�悷��
	for (auto& c : pictureList) {

		//�摜�������邩�ǂ���
		if (!c->GetisVisible()) {
			continue;
		}

		//�X�N���[��D�ɕ`����ύX����
		auto screenD = MakeScreen(x, y, true);
		FillGraph(screenD, 0, 0, 0, 255);
		SetDrawScreen(screenD);

		//�摜�̕\��
		DrawRotaGraph2(c->GetPos().x, c->GetPos().y,
			(c->m_pictureSizeX / 2), (c->m_pictureSizeY / 2),
			c->m_size, 0, c->m_handle, true);

		//�X�N���[��B�ɃX�N���[��D�����Z����
		GraphBlendBlt(screenB, screenD, screenB, 255,
			DX_GRAPH_BLEND_PMA_LIGHTEN);

		//�X�N���[����ݒ肷��
		SetDrawScreen(screenB);

		//�X�N���[�����폜����
		DeleteGraph(screenD);
	}
	//-----------------------------------------------------------------------
	
	//�ԐF�����𓧖������Ɉڂ��ւ���
	GraphBlendBlt(screenB, screenB, screenB, 255,
		DX_GRAPH_BLEND_RGBA_SELECT_MIX,
		DX_RGBA_SELECT_SRC_R,
		DX_RGBA_SELECT_SRC_G,
		DX_RGBA_SELECT_SRC_B,
		DX_RGBA_SELECT_SRC_INV_R
	);

	//screenB�̓��������݂̂�screenA�Ɉڂ��ւ������̂�screenC�ɂ���
	GraphBlendBlt(screenA, screenB, screenC, 255,
		DX_GRAPH_BLEND_MULTIPLE_A_ONLY);

	//��ʂ����ɖ߂�
	SetDrawScreen(DX_SCREEN_BACK);

	//�X�N���[����`�悷��
	DrawGraph(0, 0, screenC, true);

	//�X�N���[�����폜����
	DeleteGraph(screenA);
	DeleteGraph(screenB);
	DeleteGraph(screenC);
}

void LightPicture::AddLightList(shared_ptr<Picture> picture)
{
	picture->Initialize();
	pictureList.push_back(picture);
}