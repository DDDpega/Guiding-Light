#include "Framework.h"


Picture::Picture(Point pos, float size, PICTURE_TYPE* picture, int num, E_PIVOT pivot, E_SORT sort, bool isVisible, bool isAlpha)
	:m_pos(pos)
	, m_size(size)
	, m_picture(picture)
	, m_pivot(pivot)
	, m_isVisible(isVisible)
	, m_sort(sort)
	, m_isActive(true)
	, m_pictureNull(false)
	, m_isAlpha(isAlpha)
	, m_alpha(0)
	, m_isPauseStop(false)
	, m_num(num)
	, m_reverse(false)
	, m_scaleX(1)
	, m_scaleY(1)

{

}

Picture::Picture(E_SORT sort , bool isVisible)
	:m_sort(sort)
	,m_isVisible(isVisible)
	,m_isActive(true)
	,m_pictureNull(true)
	,m_reverse(false)
{

}

Picture::~Picture()
{
}

void Picture::Initialize()
{
	if (!m_pictureNull) {
		ChangePicture(m_picture,m_num);
	}
}

void Picture::Update()
{

}

void Picture::Draw()
{
	if (m_isAlpha) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	}
	else {
		//Œ³‚É–ß‚·
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	
	
	//‰æ‘œ‚Ì•`‰æ
	if (m_pivot == E_PIVOT::CENTER) {
		DrawRotaGraph3(m_pos.x, m_pos.y, (m_pictureSizeX / 2), (m_pictureSizeY / 2), m_scaleX * m_size, m_scaleY * m_size , 0, m_handle, true, m_reverse);
	}
	else if (m_pivot == E_PIVOT::LEFTUP) {
		DrawRotaGraph3(m_pos.x, m_pos.y, 0, 0, m_scaleX * m_size, m_scaleY * m_size, 0, m_handle, true, m_reverse);
	}

	//Œ³‚É–ß‚·
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Picture::ChangePicture(PICTURE_TYPE* picture,int num)
{
	m_num = num;
	m_picture = picture;
 	m_handle = picture->handle[m_num];

	//‰æ‘œƒTƒCƒY‚ÌŽæ“¾
	GetGraphSize(m_handle, &m_pictureSizeX, &m_pictureSizeY);
}

void Picture::ReloadPicture()
{
	if (m_picture != nullptr)
		ChangePicture(m_picture, m_num);
}

void Picture::SetAlpha(int alpha)
{
	m_alpha = alpha;
}
