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

	//�o�[�̕\��
	m_bar = shared_ptr<Picture>(new Picture(m_barCenter,m_barSize,UI::OPTION_LIST[UI::OPTION_TYPE::BAR],0,E_PIVOT::CENTER,E_SORT::SORT_UI));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_bar);

	//�܂݂̕\��
	m_pinch = shared_ptr<Picture>(new Picture(Point{ m_bar->GetPos().x + ((m_bar->m_pictureSizeX*m_barSize) / 2),m_bar->GetPos().y }, m_pinchSize, UI::OPTION_LIST[UI::OPTION_TYPE::PINCH], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_pinch);
}

void Slider::Update()
{
	Picture::Update();
}

void Slider::Draw()
{
	Picture::Draw();
}

int Slider::RightMove()
{
	auto pinchPos = m_pinch->GetPos();

	if (m_num <= m_max) {
		pinchPos.x++;
		m_pinch->SetPos(pinchPos);
		m_num++;
	}

	return m_num;
}

int Slider::LeftMove()
{
	auto pinchPos = m_pinch->GetPos();

	if (m_num > 0) {
		pinchPos.x--;
		m_pinch->SetPos(pinchPos);
		m_num--;
	}

	return m_num;
}
