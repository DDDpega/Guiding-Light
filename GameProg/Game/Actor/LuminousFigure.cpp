#include "Framework.h"

LuminousFigure::LuminousFigure(Point pos)
	:Actor(pos)
	, m_lightOn(false)
	,m_time(0)
	,m_shareNow(false)
{
}

LuminousFigure::~LuminousFigure()
{
}

void LuminousFigure::Initialize()
{
	Actor::Initialize();

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, LUMINOUSFIGURE_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::FIGUA],0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, LUMINOUSFIGURE_INFO::COLLISION_SIZE, E_TAG::LUMINOUSFIGURE));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);

	//���C�g�R���|�[�l���g�̍쐬
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, Game::gameInstance->GetStatus()->FIGURE_LIGHT,E_TAG::FIGURERAY));
	Actor::AddComponent(m_lightCmp);

	//���b���ʎ��Ԃ����邩
	m_maxTime = Game::gameInstance->GetStatus()->FIGURE_MAXTIME;

	//�t�H���g�̕`��
	m_fontHandle = CreateFontToHandle("MS �S�V�b�N", 20, 1);

	m_figureSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::FIGURE], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_figureSound);

	m_figuaMove = E_FIGUA_MOVE::NONE;
}

void LuminousFigure::Update()
{
	Actor::Update();

	switch (m_figuaMove)
	{
	case E_FIGUA_MOVE::NONE:
		
		//�������ꂽ��
		if (m_shareNow) {
			m_time = 0;
			m_isChargeStop = false;
			m_figuaMove = E_FIGUA_MOVE::CHARGE;
		}
		break;
	case E_FIGUA_MOVE::CHARGE:
		
		if (m_shareNow) {

			//�^�C���𑝂₷
			++m_time;
			m_lightCmp->m_nowLightSize += ((float)m_lightCmp->m_lightSize / 30.0f);

			//1�b�o������
			if (m_time >= 30) {

				//���C�g������
				m_lightCmp->ChangeLightONOFF();
				m_lightOn = true;

				m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::FIGUA], 1);

				//���X�g�Ɋ܂�
				SceneManeger::gameScene->m_figureList.push_back(this);
				m_figureSound->SoundPlay();

				m_time = 0;
				m_figuaMove = E_FIGUA_MOVE::LIGHTNING;

			}
		}
		else {
			m_time = 30 - m_time-1;
			m_figuaMove=E_FIGUA_MOVE::SLOWLY_DOWN;
			m_isChargeStop = true;
		}

		break;
	case E_FIGUA_MOVE::LIGHTNING:

		//�^�C���𑝂₷
		++m_time;

		//�^�C�����}�b�N�X�^�C���܂œ��B������
		if (m_time >= m_maxTime) {
			m_time = 0;
			m_figuaMove = E_FIGUA_MOVE::SLOWLY_DOWN;
		}

		break;
	case E_FIGUA_MOVE::SLOWLY_DOWN:

		//�^�C���𑝂₷
		++m_time;
		m_lightCmp->m_nowLightSize -= ((float)m_lightCmp->m_lightSize / 30.0f);
		

		//���C�g������
		if (m_time >= 30) {
			m_lightOn = false;
			m_lightCmp->m_nowLightSize = 0;

			if (!m_isChargeStop) {
				m_lightCmp->ChangeLightONOFF();
			}
		
			m_time = 0;
			m_figuaMove = E_FIGUA_MOVE::NONE;
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::FIGUA], 0);
		}
		break;

	}

	m_shareNow = false;
}

void LuminousFigure::Draw()
{
	Actor::Draw();

	if(GAME_INFO::DEBUG)
		DrawFormatStringFToHandle(m_pos.x-70, m_pos.y-50, GetColor(255, 255, 255), m_fontHandle, "%d", m_time);
}

void LuminousFigure::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::PLAYER_RAY && SceneManeger::gameScene->GetPlayer()->GetLightOn()) {
		m_shareNow = true;
	}
}

void LuminousFigure::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{

}
