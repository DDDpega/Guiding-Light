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
	//コンポーネントリストの更新処理
	for (auto& c : m_componentList) {
		c->Update();
	}

	//コンポーネントリストの中身削除
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
	//コンポーネントリストの描画
	for (auto& c : m_componentList) {
		c->Draw();
	}
}

void ActorManager::AddComponent(std::shared_ptr<Component> component,Scene* scene)
{
	//コンポーネントのList追加と初期化
	component->Initialize(scene);
	m_componentList.push_back(component);
}
