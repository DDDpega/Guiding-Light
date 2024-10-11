#include "Framework.h"



LightPicture::LightPicture(POINT pos)
	:Picture(pos, 10, "Picture/AllBlack.png", PIVOT::LEFTUP,SORT::SORT_LIGHT)
{

}

LightPicture::~LightPicture()
{

}

void LightPicture::Initialize(Game* gameInstance, Scene* scene)
{
	Picture::Initialize(gameInstance, scene);
}

void LightPicture::Update()
{
	Picture::Update();
}

void LightPicture::Draw()
{
	////ìßñæìxÇÃê›íË
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	auto handle = LoadGraph("Picture/arrow.png");
	
	
	GraphBlend(m_handle, handle,GetColor(255,255,255), DX_GRAPH_BLEND_MULTIPLE_A_ONLY);

	//SetTransColor(255, 255, 255);

	//DrawRotaGraph2(m_pos.x, m_pos.y, (m_pictureSizeX / 2), (m_pictureSizeY / 2),m_size, 0, Phandle, true);

	//ê›íËÇå≥Ç…ñﬂÇ∑ÅB
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}