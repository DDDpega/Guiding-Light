#include "Framework.h"

InteractKeyCmp::InteractKeyCmp(Actor* actor, E_INTERACT_KIND kind)
	:Component(actor)
{
}

InteractKeyCmp::~InteractKeyCmp()
{
	DeletePicture();
}

void InteractKeyCmp::Initialize()
{
	Component::Initialize();
	SetParam(m_interactKind);
}

void InteractKeyCmp::Update()
{
	Component::Update();

	if (m_interactPicture == nullptr) return;

	//入力確認
	IsInput_PictureDelete();

	//画像切り替え
	PictureSwitch();
}

void InteractKeyCmp::Draw()
{
	Component::Draw();
}

void InteractKeyCmp::DeletePicture()
{
	if (m_interactPicture != nullptr) m_interactPicture->m_isActive = false;
}

void InteractKeyCmp::SetParam(E_INTERACT_KIND kind)
{

	if (m_interactKind == kind) return;

	DeletePicture();


	auto pos = m_actor->GetPos();
	m_interactKind = kind;
	m_pictureNum = 0;

	switch (m_interactKind)
	{
	case E_INTERACT_KIND::NONE:
		break;
	case E_INTERACT_KIND::LIGHT:
		//インタラクトキー描画
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 2.5f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MYLGIHT_ON], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	case E_INTERACT_KIND::MOVE:
		//インタラクトキー描画
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 2.5f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MOVE], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	case E_INTERACT_KIND::INTERACT:
		//インタラクトキー描画
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 2.5f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_INTERACT], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	case E_INTERACT_KIND::JUMP:
		//インタラクトキー描画
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 2.5f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_JUMP], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	}
}

void InteractKeyCmp::PictureSwitch()
{
	switch (m_interactKind)
	{
	case E_INTERACT_KIND::NONE:
		break;
	case E_INTERACT_KIND::LIGHT:
		if (Game::gameInstance->m_framecnt % 20 == 0) {
			m_interactPicture->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MYLGIHT_ON], m_pictureNum);

			//次の画像を変える
			if ((m_pictureNum+1) < UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MYLGIHT_ON].path.size())
				m_pictureNum ++;
			else
				m_pictureNum = 0;
		}
		break;
	case E_INTERACT_KIND::MOVE:
		if (Game::gameInstance->m_framecnt % 20 == 0) {
			m_interactPicture->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MOVE], m_pictureNum);

			//次の画像を変える
			if ((m_pictureNum + 1) < UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MOVE].path.size())
				m_pictureNum++;
			else
				m_pictureNum = 0;
		}
		break;
	case E_INTERACT_KIND::INTERACT:
		if (Game::gameInstance->m_framecnt % 20 == 0) {
			m_interactPicture->ChangePicture(& UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_INTERACT], m_pictureNum);

			//次の画像を変える
			if ((m_pictureNum + 1) < UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_INTERACT].path.size())
				m_pictureNum++;
			else
				m_pictureNum = 0;
		}
		break;
	case E_INTERACT_KIND::JUMP:
		if (Game::gameInstance->m_framecnt % 20 == 0) {
			m_interactPicture->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_JUMP], m_pictureNum);

			//次の画像を変える
			if ((m_pictureNum + 1) < UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_JUMP].path.size())
				m_pictureNum++;
			else
				m_pictureNum = 0;
		}
		break;
	}
}

void InteractKeyCmp::IsInput_PictureDelete()
{
	switch (m_interactKind)
	{
	case E_INTERACT_KIND::NONE:
		break;
	case E_INTERACT_KIND::LIGHT:
		if (Game::gameInstance->GetInputMNG()->Click(L"LIGHT_CHANGE")) {
			DeletePicture();
		}
		break;
	case E_INTERACT_KIND::MOVE:
		if (Game::gameInstance->GetInputMNG()->Down(L"RIGHT")) {
			DeletePicture();
		}
		break;
	case E_INTERACT_KIND::INTERACT:
		if (Game::gameInstance->GetInputMNG()->Down(L"UP")) {
			DeletePicture();
		}
		break;
	case E_INTERACT_KIND::JUMP:
		if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
			DeletePicture();
		}
		break;
	}
}
