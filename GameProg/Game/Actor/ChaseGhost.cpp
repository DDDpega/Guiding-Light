#include "Framework.h"


ChaseGhost::ChaseGhost(Point pos)
	:Actor(pos)
	,m_target(nullptr)
{

}

ChaseGhost::~ChaseGhost()
{

}

void ChaseGhost::Initialize()
{
	Actor::Initialize();
	m_soundFrame = 0;
	m_pictureNumber = 0;

	m_sound= shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::GHOST], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound);

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, CHASE_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_CHASE],0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, CHASE_INFO::COLLISION_SIZE, E_TAG::GHOST));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);

	//�ÈŒ��Ɍ�����摜�̐���
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_CHASE_EYE], 0));
	Actor::AddComponent(m_darkPictureCmp);

	//�v���C���[����肷��
	m_player = SceneManeger::gameScene->GetPlayer();

	//���x����肷��
	m_speed = Game::gameInstance->GetStatus()->PISHER_SPEED;

	SetIsPisher(true);
}

void ChaseGhost::Update()
{
	Actor::Update();

	//���ݓd�C�����Ă�����̂̃��X�g����
	auto figureList = SceneManeger::gameScene->m_figureList;

	//�摜�̕ύX
	if (++m_frame % 30 == 0) {
		m_pictureNumber = m_pictureNumber == 0 ? 1 : 0;
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_CHASE], m_pictureNumber);
		m_darkPictureCmp->m_darkPicture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_CHASE_EYE], m_pictureNumber);
	}

	//墂̃^�[�Q�b�g���t�B�M���A�����������
	SceneManeger::gameScene->m_figureList.clear();
	for (int i = 0; i < figureList.size(); i++) {
		if (figureList[i]->m_lightOn) {
			SceneManeger::gameScene->m_figureList.push_back(figureList[i]);
		}
	}

	for (int i = 0; i < figureList.size(); i++) {
		if (figureList[i]->m_lightOn) {
			m_isFigure = true;
			m_target = figureList[i];
			break;
		}
		else {
			m_isFigure = false;
		}
	}

	if (figureList.empty()) {
		m_isFigure = false;
	}



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
		//�}�b�v�̃|�W�V�������v���X����
		auto targetPos = m_target->GetPos();
		//targetPos.x += Game::gameInstance->GetSceneMNG()->gameScene->m_map->getPos().x;
		//�^�[�Q�b�g�̈ʒu
		
		if (m_isFigure) {
			targetPos.y -= 80;
		}
		//�ړ��̑��x����
		float radial = atan2f((targetPos.y - m_pos.y), (targetPos.x - m_pos.x));
		m_vx = cos(radial) * m_speed;
		m_vy = sin(radial) * m_speed;

		//���E���]
		if ((int)m_pos.x != (int)targetPos.x && (int)m_pos.y != (int)targetPos.y) {
			m_pictureCmp->m_picture->m_reverse = (m_vx > 0);
			m_darkPictureCmp->m_darkPicture->m_reverse = (m_vx > 0);
		}

		//10�t���[�����Ƃɉ摜��ύX����
		/*if (Game::gameInstance->m_framecnt % 10 == 0) {
			if (m_pictureCmp->m_picture->m_handle == ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER].handle[0]) {
				m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER], 1);
			}
			else {
				m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER], 0);
			}
		}*/
	}

	//�T�E���h
	float distance = (1.0f/sqrt(abs(m_pos.x - m_player->GetPos().x) + abs(m_pos.y - m_player->GetPos().y)))*10;
	distance = int(distance * 100.0f) / 100.0f;
	if (distance >= 1.0f) {
		distance = 1.0f;
	}
	
	if (m_soundFrame-- < 0) {
		m_sound->SoundStop();
		m_sound->SetPlaySoundVolume(distance);
		m_sound->SoundPlay(Sound::BACK);
		m_soundFrame = GHOSTSOUNDSEC;
	}


	//printfDx("%f\n", distance);

	Actor::Move();

	//�ϐ��̏�����
	m_vy = 0;
	m_vx = 0;


}

void ChaseGhost::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other,tag, selftag);

	if ((tag == E_TAG::SPOT_LIGHT_RAY || tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY || tag == E_TAG::FIGURERAY || tag == E_TAG::GOALLIGHTRAY) && m_isActive) {
		m_darkPictureCmp->m_darkPicture->SetisVisible(false);
	}
}

void ChaseGhost::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	//�Â����ɗ���
	if (tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY && m_isActive) {

	}
}
