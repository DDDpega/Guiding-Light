#include "Framework.h"

PastimeGhost::PastimeGhost(Point pos)
	:Actor(pos)
	, m_hitMaxLight(false)
{
}

PastimeGhost::~PastimeGhost()
{
}

void PastimeGhost::Initialize()
{
	Actor::Initialize();

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PASTIME_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_PASTIME], 0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, PASTIME_INFO::COLLISION_SIZE, E_TAG::PASTIME_GHOST));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//�ÈŒ��Ɍ�����摜�̐���
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_PASTIME_EYE], 0));
	Actor::AddComponent(m_darkPictureCmp);
}

void PastimeGhost::Update()
{
	Actor::Update();

	GoalLight* target = nullptr;

	//墂̃^�[�Q�b�g���t�B�M���A�����������
	auto goalLightList = SceneManeger::gameScene->m_goalLightList;

	SceneManeger::gameScene->m_goalLightList.clear();
	if (!goalLightList.empty()) {
		for (int i = 0; i < goalLightList.size(); i++) {
			if (goalLightList[i]->m_lightCmp->m_lightOn) {
				SceneManeger::gameScene->m_goalLightList.push_back(goalLightList[i]);
			}
		}
	}
	//���ݓd�C�����Ă�����̂̃��X�g����
	for (int i = 0; i < goalLightList.size(); i++) {
		if (goalLightList[i]->m_lightCmp->m_lightOn) {
			target = goalLightList[i];
			goalLightList[i]->m_pastimeGhostFirshIndex = true;
			break;
		}
	}

	if (target == nullptr) {
		return;
	}

	//�ړ��̑��x����
	float radial = atan2f((target->GetPos().y - m_pos.y), (target->GetPos().x - m_pos.x));
	m_vx = cos(radial) * Game::gameInstance->GetStatus()->PASTIME_GHOST_SPEED;
	m_vy = sin(radial) * Game::gameInstance->GetStatus()->PASTIME_GHOST_SPEED;

	//���E���]
	if ((int)m_pos.x != (int)target->GetPos().x && (int)m_pos.y != (int)target->GetPos().y) {
		m_pictureCmp->m_picture->m_reverse = (m_vx > 0);
		m_darkPictureCmp->m_darkPicture->m_reverse = (m_vx > 0);
	}

	if (m_hitMaxLight) {
		m_vx = m_vy = 0;
	}

	Actor::Move();

	//�ϐ��̏�����
	m_vy = 0;
	m_vx = 0;

	m_hitMaxLight = false;

}

void PastimeGhost::Draw()
{
	Actor::Draw();
}

void PastimeGhost::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other,tag,selftag);

	if (tag == E_TAG::FIGURERAY || tag == E_TAG::PLAYER_RAY) {
		m_hitMaxLight = true;
	}

	if ((tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY || tag == E_TAG::FIGURERAY || tag == E_TAG::GOALLIGHTRAY) && m_isActive) {
		m_darkPictureCmp->m_darkPicture->SetisVisible(false);
	}
}

void PastimeGhost::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
