#include "Framework.h"

LuminousFigure::LuminousFigure(POINT pos)
	:Actor(pos)
	,m_keepTime(0)
	, m_lightOn(false)
{
}

LuminousFigure::~LuminousFigure()
{
}

void LuminousFigure::Initialize()
{
	Actor::Initialize();

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, LUMINOUSFIGURE_INFO::SIZE, "Picture/figua.png", E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//�����蔻��̍쐬
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, LUMINOUSFIGURE_INFO::COLLISION_SIZE, E_TAG::LUMINOUSFIGURE));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//���C�g�R���|�[�l���g�̍쐬
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, Game::gameInstance->GetStatus()->FIGURE_LIGHT));
	Actor::AddComponent(m_lightCmp);

	//���b���ʎ��Ԃ����邩
	m_maxTime = Game::gameInstance->GetStatus()->FIGURE_MAXTIME;

	//�t�H���g�̕`��
	m_fontHandle = CreateFontToHandle("MS �S�V�b�N", 20, 1);

}

void LuminousFigure::Update()
{
	Actor::Update();

	//����b���������
	if (m_keepTime > 0) {

		//�������Ȃ猸�炳�Ȃ�
		if (!m_shareNow) {
			m_keepTime--;
		}

		//���C�g������
		if (!m_lightOn) {
			m_lightOn = true;
			m_lightCmp->ChangeLightONOFF(m_lightOn);

			//墂̃^�[�Q�b�g���t�B�M���A�ɂ���
			for (auto& pisher : SceneManeger::gameScene->m_pisherList) {
				pisher->m_target = this;
				pisher->m_isFigure = true;
			}
		}
	}
	else{

		//���C�g������
		if (m_lightOn) {
			m_lightOn = false;
			m_lightCmp->ChangeLightONOFF(m_lightOn);

			//墂̃^�[�Q�b�g���t�B�M���A�����������
			for (auto& pisher : SceneManeger::gameScene->m_pisherList) {
				pisher->m_isFigure = false;
			}
		}
	}

}

void LuminousFigure::Draw()
{
	Actor::Draw();

	//DrawFormatStringFToHandle(m_pos.x-70, m_pos.y-50, GetColor(255, 255, 255), m_fontHandle, "%d", m_keepTime);
}

void LuminousFigure::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::PLAYER_LIGHT && SceneManeger::gameScene->GetPlayer()->GetLightOn() &&
		m_keepTime<m_maxTime) {
		m_keepTime = m_maxTime;
		m_shareNow = true;
	}
}

void LuminousFigure::NoHitCollision(Actor* other, E_TAG tag)
{
	if (tag == E_TAG::PLAYER_LIGHT) {
		m_shareNow = false;
	}
}
