#include "Framework.h"


Pisher::Pisher(POINT pos)
	:Actor(pos,0.5,"Picture/UFO_dot.png")
	,m_target(nullptr)
{

}

Pisher::~Pisher()
{

}

void Pisher::Initialize(Game* gameInstance_, Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 40,40 }, TAG::PISHER));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

	//�ÈŒ��Ɍ�����摜�̐���
	auto dark = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this,"Picture/pisherEye.png"));
	Actor::AddComponent(dark, scene);

	//�v���C���[����肷��
	m_player = scene->GetPlayer();

	//���x����肷��
	m_speed = m_gameInstance->GetStatus()->PISHER_SPEED;
}

void Pisher::Update()
{
	Actor::Update();

	//�t�B�M���A���^�[�Q�b�g�悾������
	if (!m_isFigure) {

		//�v���C���[�̃��C�g����������^�[�Q�b�g���v���C���[�ɕύX����
		if (m_player->GetLightOn()) {
			//m_target = m_player;
		}
		else {
			m_target = nullptr;
		}
	}

	//�^�[�Q�b�g�����݂�����
	if (m_target != nullptr) {

		//�^�[�Q�b�g�̈ʒu
		auto targetPos = m_target->GetPos();

		//�^�[�Q�b�g��ǂ�������X
		if (m_pos.x - targetPos.x >= 0) {
			m_vx = -m_speed;
		}
		else {
			m_vx  = m_speed;
		}

		//�^�[�Q�b�g��ǂ�������Y
		if (m_pos.y - targetPos.y >= 0) {
			m_vy = -m_speed;
		}
		else {
			m_vy = m_speed;
		}
	}

	Actor::Move();

	//�ϐ��̏�����
	m_vy = 0;
	m_vx = 0;
}

void Pisher::HitCollision(Actor* other, TAG tag,TAG selftag)
{
	Actor::HitCollision(other,tag, selftag);
}

void Pisher::NoHitCollision(Actor* other, TAG tag)
{
}
