#include "Framework.h"


Pisher::Pisher(POINT pos)
	:Actor(pos)
	,m_target(nullptr)
{

}

Pisher::~Pisher()
{

}

void Pisher::Initialize()
{
	Actor::Initialize();

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PISHER_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER],0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 },PISHER_INFO::COLLISION_SIZE, E_TAG::PISHER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//�ÈŒ��Ɍ�����摜�̐���
	auto dark = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER], 1));
	Actor::AddComponent(dark);

	//�v���C���[����肷��
	m_player = SceneManeger::gameScene->GetPlayer();

	//���x����肷��
	m_speed = Game::gameInstance->GetStatus()->PISHER_SPEED;
}

void Pisher::Update()
{
	Actor::Update();

	//�t�B�M���A���^�[�Q�b�g�悾������
	if (!m_isFigure) {

		//�v���C���[�̃��C�g����������^�[�Q�b�g���v���C���[�ɕύX����
		if (m_player->GetLightOn()) {
			m_target = m_player;
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

void Pisher::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other,tag, selftag);
}

void Pisher::NoHitCollision(Actor* other, E_TAG tag)
{
}
