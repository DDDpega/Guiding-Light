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

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, LUMINOUSFIGURE_INFO::SIZE, "Picture/figua.png", E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, LUMINOUSFIGURE_INFO::COLLISION_SIZE, E_TAG::LUMINOUSFIGURE));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//ライトコンポーネントの作成
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, Game::gameInstance->GetStatus()->FIGURE_LIGHT));
	Actor::AddComponent(m_lightCmp);

	//何秒効果時間があるか
	m_maxTime = Game::gameInstance->GetStatus()->FIGURE_MAXTIME;

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
			for (auto& pisher : SceneManeger::gameScene->m_pisherList) {
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
