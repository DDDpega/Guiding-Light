#include "Framework.h"

Slider::Slider(Point barCenter,int max,int iniNum,float barSize,float pinchSize)
	:Picture(E_SORT::SORT_UI, true)
	,m_barCenter(barCenter)
	,m_max(max)
	,m_num(iniNum)
	,m_barSize(barSize)
	,m_pinchSize(pinchSize)
	,m_isOperation(false)
{
	
}

Slider::~Slider()
{

}

void Slider::Initialize()
{
	Picture::Initialize();

	//バーの表示
	m_bar = shared_ptr<Picture>(new Picture(m_barCenter, m_barSize, &UI::OPTION_LIST[UI::OPTION_TYPE::BAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_bar);

	//1つのメモリ当たりの増加量
	float rightPointX = m_bar->GetPos().x + ((m_bar->m_pictureSizeX * m_barSize) / 2);
	float leftPointX = m_bar->GetPos().x - ((m_bar->m_pictureSizeX * m_barSize) / 2);
	m_plusX = ((rightPointX - leftPointX) / m_max);

	//バーの表示
	m_bar2 = shared_ptr<Picture>(new Picture(m_barCenter, m_barSize, &UI::OPTION_LIST[UI::OPTION_TYPE::BAR], 1, E_PIVOT::CENTER, E_SORT::SORT_UI));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_bar2);

	
	//つまみの表示
	m_pinch = shared_ptr<Picture>(new Picture(Point{ rightPointX - (m_num * m_plusX),m_bar->GetPos().y }, m_pinchSize, &UI::OPTION_LIST[UI::OPTION_TYPE::PINCH], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_pinch);

}
	

void Slider::Update()
{
	Picture::Update();

	m_bar2->m_scaleX = (float)m_num / m_max;
	float leftPointX = m_bar->GetPos().x - ((m_bar->m_pictureSizeX * m_barSize) / 2);
	float rightPointX = m_bar->GetPos().x + ((m_bar->m_pictureSizeX * m_barSize) / 2);
	float middolePointX = leftPointX + m_num * m_plusX;

	middolePointX =leftPointX- (leftPointX - m_pinch->GetPos().x) / 2;

	
	m_bar2->SetPos(Point{ middolePointX ,m_bar2->GetPos().y});

}

void Slider::Draw()
{
	Picture::Draw();
}

int Slider::RightMove()
{
	auto pinchPos = m_pinch->GetPos();

	if (m_num <= m_max) {
		pinchPos.x+= m_plusX;
		m_pinch->SetPos(pinchPos);
		m_num++;
	}

	return m_num;
}

int Slider::LeftMove()
{
	auto pinchPos = m_pinch->GetPos();

	if (m_num > 0) {
		pinchPos.x-= m_plusX;
		m_pinch->SetPos(pinchPos);
		m_num--;
	}

	return m_num;
}
