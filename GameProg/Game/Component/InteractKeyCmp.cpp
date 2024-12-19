#include "Framework.h"

InteractKeyCmp::InteractKeyCmp(Actor* actor, E_INTERACT_KIND kind)
	:Component(actor)
{
}

InteractKeyCmp::~InteractKeyCmp()
{
}

void InteractKeyCmp::Initialize()
{
	Component::Initialize();

	auto pos = m_actor->GetPos();
	switch (m_interactKind)
	{
	case E_INTERACT_KIND::LIGHT:
		//�C���^���N�g�L�[�`��
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 0.1f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_B], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	case E_INTERACT_KIND::MOVE:
		//�C���^���N�g�L�[�`��
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 0.1f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MOVE], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	case E_INTERACT_KIND::INTERACT:
		//�C���^���N�g�L�[�`��
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 0.1f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_ON_LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	case E_INTERACT_KIND::JUMP:
		//�C���^���N�g�L�[�`��
		m_interactPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 80.0f }, 0.1f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_JUMP], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
		Game::gameInstance->GetPictureMNG()->AddPicture(m_interactPicture);

		break;
	}
}

void InteractKeyCmp::Update()
{
	Component::Update();
}

void InteractKeyCmp::Draw()
{
	Component::Draw();
}
