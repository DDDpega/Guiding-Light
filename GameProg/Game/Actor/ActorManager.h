#pragma once
#include "Actor.h"
#include "Component.h"
#include "Scene.h"
#include "CollisionManeger.h"

class Actor;
class CollisionManeger;

class ActorManager
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ActorManager(Game* gameInstance);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~ActorManager();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();
	
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �R���|�[�l���g���X�g�ɒǉ����郁�\�b�h
	/// </summary>
	/// <param name="actor"></param>
	void AddComponent(std::shared_ptr<Component> component, Scene* scene);

	/// <summary>
	/// ���X�g�̍폜
	/// </summary>
	void CleanList() {
		m_componentList.clear();
	}

private:

protected:
	std::list<std::shared_ptr<Component>> m_componentList;

	Game* m_gameInstance;
};

