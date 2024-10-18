#include "Framework.h"

InGameUI::InGameUI()
	:UserInterface(true, true)
{
}

InGameUI::~InGameUI()
{
}

void InGameUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);

	m_fontHandle = CreateFontToHandle("MS ゴシック", 36, 10);
}

void InGameUI::Update()
{
	UserInterface::Update();

}

void InGameUI::Draw()
{
	UserInterface::Draw();

	DrawFormatStringFToHandle(20, 20, GetColor(255, 255, 255), m_fontHandle, "ステージ%d", m_stageNum);
	DrawFormatStringFToHandle(m_sceneptr->screenX-310, 20, GetColor(255, 255, 255), m_fontHandle, "残りのランプ　%d", m_lightnum);
}