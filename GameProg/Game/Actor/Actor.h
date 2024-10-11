#pragma once

class RigidbodyCmp;
class MapCollision;
class Scene;
class Game;

class Actor : public Picture
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Actor(POINT pos, float size, const TCHAR* picture, PIVOT pivot = PIVOT::CENTER, SORT sort = SORT::SORT_ACTOR);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Actor();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �L�����N�^�[�̓���
	/// </summary>
	void Move();


	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	virtual void HitCollision(Actor* other, TAG tag);

	/// <summary>
	/// m_isMove_x,y�̃Z�b�^�[
	/// </summary>
	/// <param name="isMove_x">x���������Ă��邩</param>
	/// <param name="isMove_y">y���������Ă��邩</param>
	void SetMoveCheck(bool isMove_x, bool isMove_y) { m_isMove_x = isMove_x; m_isMove_y = isMove_y; }

	/// <summary>
	/// m_isMove_x,y�̃Q�b�^�[
	/// </summary>
	/// <param name="shaft"></param>
	/// <returns></returns>
	bool GetIsMove(string shaft);

	int m_vx, m_vy;
	std::shared_ptr<MapCollision> m_mapCollision;

protected:
	Scene* m_sceneptr;		//���݂̃V�[��
	Game* m_gameInstance;		//�Q�[���C���X�^���X
	std::shared_ptr<RigidbodyCmp> m_rigidBody;
	bool m_isMove_x;	//x���ɓ����Ă��邩�ǂ���
	bool m_isMove_y;	//y���ɓ����Ă��邩�ǂ���
};

