#include "Framework.h"


Picture::Picture(POINT pos, float size, const TCHAR* picture, E_PIVOT pivot, E_SORT sort, bool isVisible, bool isAlpha)
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
{

}

Picture::Picture(E_SORT sort , bool isVisible)
	:m_sort(sort)
	,m_isVisible(isVisible)
	,m_isActive(true)
	,m_pictureNull(true)
{

}

Picture::~Picture()
{
	DeleteGraph(m_handle);
}

void Picture::Initialize()
{
	if (!m_pictureNull) {
		ChangePicture(m_picture);
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
		//元に戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//画像の描画
	if (m_pivot == E_PIVOT::CENTER) {
		DrawRotaGraph2(m_pos.x, m_pos.y, (m_pictureSizeX/2), (m_pictureSizeY / 2), m_size, 0,  m_handle, true);
	}
	else if (m_pivot == E_PIVOT::LEFTUP) {
		DrawRotaGraph2(m_pos.x, m_pos.y, 0, 0, m_size, 0, m_handle, true);
	}
}

void Picture::ChangePicture(const TCHAR* picture) 
{

	m_handle = LoadGraph(picture); // 画像をロード

	//画像サイズの取得
	GetGraphSize(m_handle, &m_pictureSizeX, &m_pictureSizeY);
}

void Picture::SetAlpha(int alpha)
{
	m_alpha = alpha;
}
