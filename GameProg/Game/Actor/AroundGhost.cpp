#include "Framework.h"

AroundGhost::AroundGhost(Point pos)
	:Actor(pos)
{
}

AroundGhost::~AroundGhost()
{
}

void AroundGhost::Initialize()
{
	Actor::Initialize();

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, AROUND_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_AROUND], 0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, AROUND_INFO::COLLISION_SIZE, E_TAG::GHOST));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);

	//�ÈŒ��Ɍ�����摜�̐���
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_AROUND_EYE], 0));
	Actor::AddComponent(m_darkPictureCmp);


}

void AroundGhost::CreateRoute(int number)
{
	//�X�e�[�^�X�̎擾
	auto data = Status::ReadAroundGhostStatus(SceneManeger::gameScene->GetNumStage(), number);
	m_DrawBox = {
		m_pos.x - (data.pos.x * 40),
		m_pos.x + (data.pos.x * 40),
		m_pos.y - (data.pos.y * 40),
		m_pos.y + (data.pos.y * 40),
	};

	//�ړ���̐ݒ�
	m_movePos.push_back(Point{ m_DrawBox.left , m_DrawBox.top});
	m_movePos.push_back(Point{ m_DrawBox.right , m_DrawBox.top });
	m_movePos.push_back(Point{ m_DrawBox.right , m_DrawBox.bottom });
	m_movePos.push_back(Point{ m_DrawBox.left , m_DrawBox.bottom });

	//�����l�ɕύX
	m_right = data.right;
	SetPos(m_movePos[0]);
	m_otherTarget = m_otherTargetOld = false;
	m_stopTime = 0;
	if (m_right) {
		m_nowNumber = 1;
	}
	else {
		m_nowNumber = 3;
	}
}

void AroundGhost::Update()
{
	Actor::Update();

	m_targetPos = m_movePos[m_nowNumber];


	//���ݓd�C�����Ă�����̂̃��X�g����
	auto figureList = SceneManeger::gameScene->m_figureList;
	auto speed = Game::gameInstance->GetStatus()->AROUND_GHOST_ROUTE_SPEED;
	m_otherTarget = false;

	//墂̃^�[�Q�b�g���t�B�M���A�����������
	SceneManeger::gameScene->m_figureList.clear();
	for (int i = 0; i < figureList.size(); i++) {
		if (figureList[i]->m_lightOn) {
			SceneManeger::gameScene->m_figureList.push_back(figureList[i]);
		}
	}

	for (int i = 0; i < figureList.size(); i++) {
		if (figureList[i]->m_lightOn) {
			m_otherTarget = true;
			m_targetPos = figureList[i]->GetPos();
			m_targetPos.y -= 80;

			speed = Game::gameInstance->GetStatus()->AROUND_GHOST_TARGET_SPEED;
			break;
		}
		else {
			m_otherTarget = false;
		}
	}



	//�t�B�M���A���^�[�Q�b�g�悾������
	if (!m_otherTarget) {

		//�v���C���[�̃��C�g����������^�[�Q�b�g���v���C���[�ɕύX����
		auto player = SceneManeger::gameScene->GetPlayer();
		if (player->GetLightOn()) {
			m_targetPos = player->GetPos();
			m_otherTarget = true;
			speed = Game::gameInstance->GetStatus()->AROUND_GHOST_TARGET_SPEED;
		}
	}

	//�ϐ��̕ύX
	if (!m_otherTarget && m_otherTargetOld) {
		m_stopTime = 60;
	}
	m_otherTargetOld = m_otherTarget;

	if (m_stopTime > 0) {
		--m_stopTime;
		return;
	}

	float radial = atan2f((m_targetPos.y - m_pos.y), (m_targetPos.x - m_pos.x));
	m_vx = cos(radial) * speed;
	m_vy = sin(radial) * speed;

	//���E���]
	m_pictureCmp->m_picture->m_reverse = (m_vx > 0.0f);
	m_darkPictureCmp->m_darkPicture->m_reverse = (m_vx > 0.0f);	

	if (abs(m_targetPos.x- m_pos.x)<=1  &&
		abs(m_targetPos.y- m_pos.y) <= 1) {

		if (m_right) {
			if (++m_nowNumber == 4) {
				m_nowNumber = 0;
			}
		}
		else {
			if (--m_nowNumber == -1) {
				m_nowNumber = 3;
			}
		}
	}

	Actor::Move();

	//�ϐ��̏�����
	m_vy = 0;
	m_vx = 0;


}

void AroundGhost::Draw()
{
	Actor::Draw();


	//�����蔻��̕\��
	if (GAME_INFO::DEBUG) {
		DrawBox(m_DrawBox.left, m_DrawBox.top, m_DrawBox.right, m_DrawBox.bottom
			, GetColor(0, 255, 0), false);
		DrawLine(m_DrawBox.left, m_DrawBox.top, m_DrawBox.right, m_DrawBox.bottom, GetColor(0, 255, 0));
		DrawLine(m_DrawBox.right, m_DrawBox.top, m_DrawBox.left, m_DrawBox.bottom, GetColor(0, 255, 0));
	}
}

void AroundGhost::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other,tag,selftag);

	if ((tag==E_TAG::SPOT_LIGHT_RAY || tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY || tag == E_TAG::FIGURERAY || tag == E_TAG::GOALLIGHTRAY) && m_isActive) {
		m_darkPictureCmp->m_darkPicture->SetisVisible(false);
	}
}

void AroundGhost::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
