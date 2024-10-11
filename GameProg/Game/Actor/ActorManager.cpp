#include "ActorManager.h"
#include "Game.h"

ActorManager::ActorManager(Game* gameInstance)
	:m_componentList()
	,m_gameInstance(gameInstance)
{
}

ActorManager::~ActorManager()
{

}

void ActorManager::Initialize()
{
	m_componentList.clear();
}

void ActorManager::Update()
{
	//�R���|�[�l���g���X�g�̍X�V����
	for (auto& c : m_componentList) {
		c->Update();
	}

	//�R���|�[�l���g���X�g�̒��g�폜
	for (auto i = m_componentList.cbegin(); i != m_componentList.cend();) {
		if (i->get()->GetActor()->m_isActive) {
			i++;
		}
		else {
			i->get()->Destroy(true);
			m_gameInstance->GetCollisionMNG()->ListDestroy();
			i = m_componentList.erase(i);
		}
	}
}

void ActorManager::Draw()
{
	//�R���|�[�l���g���X�g�̕`��
	for (auto& c : m_componentList) {
		c->Draw();
	}
}

void ActorManager::AddComponent(std::shared_ptr<Component> component,Scene* scene)
{
	//�R���|�[�l���g��List�ǉ��Ə�����
	component->Initialize(scene);
	m_componentList.push_back(component);
}
