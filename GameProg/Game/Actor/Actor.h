#pragma once

class RigidbodyCmp;
class MapCollision;


class Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Actor(POINT pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Actor();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// �L�����N�^�[�̓���
	/// </summary>
	void Move();


	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	virtual void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// �Փ˂��Ă��Ȃ�
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	virtual void NoHitCollision(Actor* other, E_TAG tag) = 0;

	/// <summary>
	/// �R���|�[�l���g���X�g�ɒǉ����郁�\�b�h
	/// </summary>
	/// <param name="actor"></param>
	void AddComponent(std::shared_ptr<Component> component);



	/// <summary>
	/// m_isMove_x,y�̃Z�b�^�[
	/// </summary>
	/// <param name="isMove_x">x���������Ă��邩</param>
	/// <param name="isMove_y">y���������Ă��邩</param>
	void SetMoveCheck(bool isMove_x, bool isMove_y) {
		m_isMove_x = isMove_x;
		m_isMove_y = isMove_y;
	}

	/// <summary>
	/// m_isMove_x,y�̃Q�b�^�[
	/// </summary>
	/// <param name="shaft"></param>
	/// <returns></returns>
	bool GetIsMove(string shaft);

	/// <summary>
	/// �X�|�[�����ɉE���ɂ��炷
	/// </summary>
	void SpawnMove(int x, int y);

	/// <summary>
	/// ���݂̃|�W�V�����𓾂�
	/// </summary>
	/// <returns></returns>
	POINT GetPos() {
		return m_pos;
	}

	/// <summary>
	/// �|�W�V�����̕ύX
	/// </summary>
	/// <returns></returns>
	void SetPos(POINT changepos) {
		m_pos = changepos;
	}


	float m_vx, m_vy;
	std::shared_ptr<MapCollision> m_mapCollision;
	std::shared_ptr<RigidbodyCmp> m_rigidBody;
	shared_ptr<PictureCmp> m_pictureCmp;
	bool m_isActive;			//�������邩�ǂ���

protected:
	bool m_isMove_x;	//x���ɓ����Ă��邩�ǂ���
	bool m_isMove_y;	//y���ɓ����Ă��邩�ǂ���
	std::list<std::shared_ptr<Component>> m_componentList;
	POINT m_pos;	//�ʒu
};