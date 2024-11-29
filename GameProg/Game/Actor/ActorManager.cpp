#include "Framework.h"

ActorManager::ActorManager()
{
}

ActorManager::~ActorManager()
{
	
}

void ActorManager::Initialize()
{
	m_actorList.clear();
	m_waitList.clear();
}

void ActorManager::Update()
{
	//�A�N�^�[���X�g�̍폜
	for (auto i = m_actorList.cbegin(); i != m_actorList.cend();) {
		if (i->get()->m_isActive) {
			i++;
		}
		else {
			i = m_actorList.erase(i);
		}
	}

	if (SceneManeger::gameScene->m_isPause)
		return;

	for (auto& actor : m_actorList) {
		if (actor->m_darkPictureCmp != nullptr) {
			actor->m_darkPictureCmp->m_darkPicture->SetisVisible(true);
		}
	}

	//�A�N�^�[���X�g�̍X�V����
	for (auto& actor : m_actorList) {
		actor->Update();
	}

	for (auto& actor : m_waitList) {
		m_actorList.push_back(actor);
	}
	m_waitList.clear();
}

void ActorManager::Draw()
{
	//�A�N�^�[���X�g�̕`�揈��
	for (auto& actor : m_actorList) {
		actor->Draw();
	}
}

void ActorManager::AddActor(shared_ptr<Actor> actor)
{
	m_waitList.push_back(actor);

	actor->Initialize();
}
