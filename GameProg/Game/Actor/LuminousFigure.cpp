#include "Framework.h"

LuminousFigure::LuminousFigure(POINT pos)
	:Actor(pos,1,"Picture/figua.png")
	,m_keepTime(0)
	, m_lightOn(false)
{
}

LuminousFigure::~LuminousFigure()
{
}

void LuminousFigure::Initialize(Game* gameInstance_, Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 40,80 }, TAG::LUMINOUSFIGURE));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

	//ライトコンポーネントの作成
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, gameInstance_->GetStatus()->FIGURE_LIGHT));
	Actor::AddComponent(m_lightCmp, scene);

	//何秒効果時間があるか
	m_maxTime = gameInstance_->GetStatus()->FIGURE_MAXTIME;

	//フォントの描画
	m_fontHandle = CreateFontToHandle("MS ゴシック", 20, 1);

}

void LuminousFigure::Update()
{
	Actor::Update();

	//光る秒数があれば
	if (m_keepTime > 0) {

		//供給中なら減らさない
		if (!m_shareNow) {
			m_keepTime--;
		}

		//ライトをつける
		if (!m_lightOn) {
			m_lightOn = true;
			m_lightCmp->ChangeLightONOFF(m_lightOn);

			//蠅のターゲットをフィギュアにする
			for (auto& pisher : static_cast<GameScene*>(m_sceneptr)->m_pisherList) {
				pisher->m_target = this;
				pisher->m_isFigure = true;
			}
		}
	}
	else{

		//ライトを消す
		if (m_lightOn) {
			m_lightOn = false;
			m_lightCmp->ChangeLightONOFF(m_lightOn);

			//蠅のターゲットをフィギュアから解除する
			for (auto& pisher : static_cast<GameScene*>(m_sceneptr)->m_pisherList) {
				pisher->m_isFigure = false;
			}
		}
	}

}

void LuminousFigure::Draw()
{
	Actor::Draw();

	DrawFormatStringFToHandle(m_pos.x-70, m_pos.y-50, GetColor(255, 255, 255), m_fontHandle, "%d", m_keepTime);
}

void LuminousFigure::HitCollision(Actor* other, TAG tag, TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == TAG::PLAYER_LIGHT && m_sceneptr->GetPlayer()->GetLightOn() &&
		m_keepTime<m_maxTime) {
		m_keepTime = m_maxTime;
		m_shareNow = true;
	}
}

void LuminousFigure::NoHitCollision(Actor* other, TAG tag)
{
	if (tag == TAG::PLAYER_LIGHT) {
		m_shareNow = false;
	}
}
