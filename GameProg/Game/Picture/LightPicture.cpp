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

}

void LightPicture::Draw()
{
	//���߃��[�h�ɕς���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//�摜��`�悷�邽�߂̃X�N���[�����쐬����
	auto screenA = MakeScreen(x, y, true);
	auto screenB = MakeScreen(x, y, true);
	auto screenC = MakeScreen(x, y, true);

	//�X�N���[����F�œh��Ԃ�
	FillGraph(screenA, 0, 0, 0, 255);			//��
	FillGraph(screenB, 0, 0, 0, 255);			//���ɉ摜��`��
	FillGraph(screenC, 255, 255, 255, 255);		//�^����

	//�X�N���[����ݒ肷��
	SetDrawScreen(screenB);

	//----------------------------------------------------------------------
	//���C�g��`�悷��
	for (auto& c : lightCmpList) {

		//�X�N���[��D�ɕ`����ύX����
		auto screenD = MakeScreen(x, y, true);
		FillGraph(screenD, 0, 0, 0, 255);
		SetDrawScreen(screenD);

		//���C�����ɎO�p�`���쐬����
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

			if (!c->m_ray[i]->m_isRayStart)
				continue;

			if (i == GAME_INFO::RAYNUM-1) {
				DrawTriangle(c->m_ray[i]->GetPos().x, c->m_ray[i]->GetPos().y,
					c->m_ray[0]->GetPos().x, c->m_ray[0]->GetPos().y,
					c->GetActor()->GetPos().x, c->GetActor()->GetPos().y,
					GetColor(255, 0, 0), true);
			}
			else {
				DrawTriangle(c->m_ray[i]->GetPos().x, c->m_ray[i]->GetPos().y,
					c->m_ray[i + 1]->GetPos().x, c->m_ray[i + 1]->GetPos().y,
					c->GetActor()->GetPos().x, c->GetActor()->GetPos().y,
					GetColor(255, 0, 0), true);
			}
		}

		auto screenE = MakeScreen(x, y, true);
		FillGraph(screenE, 0, 0, 0, 255);
		SetDrawScreen(screenE);

		//���C�g�̉摜��`��
		DrawRotaGraph2(c->m_lightPicture->GetPos().x, c->m_lightPicture->GetPos().y,
			(c->m_lightPicture->m_pictureSizeX / 2), (c->m_lightPicture->m_pictureSizeY / 2),
			c->m_lightPicture->m_size, 0, c->m_lightPicture->m_handle, true);

		GraphBlend(screenD,screenE, 255, DX_GRAPH_BLEND_RGBA_SELECT_MIX,
			DX_RGBA_SELECT_BLEND_R,    // �o�͌��ʂ̐Ԑ����� AlphaHandle �̗ΐ���
			DX_RGBA_SELECT_SRC_G,    // �o�͌��ʂ̗ΐ����� AlphaHandle �̐Ԑ���
			DX_RGBA_SELECT_SRC_B,    // �o�͌��ʂ̐����� AlphaHandle �̐���
			DX_RGBA_SELECT_SRC_R   // �o�͌��ʂ̃A���t�@������ BlendHandle �̐Ԑ���
		);

		
		//�X�N���[����ݒ肷��
		SetDrawScreen(screenD);
		//�X�N���[�����폜����
		DeleteGraph(screenE);


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

void LightPicture::AddLightList(LightCmp* lightCmp)
{
	lightCmpList.push_back(lightCmp);

}