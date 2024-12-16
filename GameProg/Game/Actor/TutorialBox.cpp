#include "Framework.h"

constexpr int VISIBLE_TIME = 120;

TutorialBox::TutorialBox(Point pos)
	:Actor(pos)
	,m_isPlayerHit(false)
	,m_frameCnt(0)
	,m_numText(0)
	,m_isTextStop(false)
{
}

TutorialBox::~TutorialBox()
{
}

void TutorialBox::Initialize()
{
	Actor::Initialize();

	//�����蔻��
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, Point{40,40}, E_TAG::TUTORIAL_BOX));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//�C���^���N�g�L�[�`��
	m_interactKey = shared_ptr<Picture>(new Picture(Point{m_pos.x,m_pos.y-40.0f}, 0.1f, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_B], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
	m_interactKey->SetisVisible(false);
	Game::gameInstance->GetPictureMNG()->AddPicture(m_interactKey);


	m_functionArray.push_back(bind(&TutorialBox::Function1,this));
	m_functionArray.push_back(bind(&TutorialBox::Function2,this));
	m_functionArray.push_back(bind(&TutorialBox::Function3,this));
	m_functionArray.push_back(bind(&TutorialBox::Function4,this));
	m_functionArray.push_back(bind(&TutorialBox::Function5,this));
	m_functionArray.push_back(bind(&TutorialBox::Function6,this));
	m_functionArray.push_back(bind(&TutorialBox::Function7,this));
	m_functionArray.push_back(bind(&TutorialBox::Function8,this));
	m_functionArray.push_back(bind(&TutorialBox::Function9,this));
}

void TutorialBox::Update()
{
	Actor::Update();

	if (m_isPlayerHit) {

		//���ꂼ��̊֐��𗬂�
		if(!m_functionArray[m_number]()) return;

		if (m_isTextStop) return;

		if (++m_frameCnt == VISIBLE_TIME) {
			++m_numText;
			if (m_numText + m_sentenceFirstNum >m_sentenceMaxNum) {

				m_picture->m_isActive = false;
				m_interactKey->m_isActive = false;
			}
			else {
				m_picture->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::SENTENCE], m_numText+m_sentenceFirstNum);
			}

			m_interactKey->SetisVisible(false);
			m_frameCnt = 0;
		}
	}
}

void TutorialBox::Draw()
{
	Actor::Draw();
}

void TutorialBox::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::PLAYER && !m_isPlayerHit) {


		auto isTrigger = false;
		for (auto s : SceneManeger::gameScene->m_solarpanel) {
			if (s->GetParam() == E_SOLARPANEL_KIND::BLOCK) {
				isTrigger = s->GetIsTrigger();
				if (isTrigger) {
					break;
				}
			}
		}

		if (m_number != 5 || !isTrigger) {
			m_isPlayerHit = true;
			m_numText = 0;
			//�`��
			m_picture = shared_ptr<Picture>(new Picture(TUTORIAL_INFO::POS, TUTORIAL_INFO::SIZE, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::SENTENCE], m_sentenceFirstNum, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
			Game::gameInstance->GetPictureMNG()->AddPicture(m_picture);
		}
	}
}

void TutorialBox::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}

bool TutorialBox::Function1()
{

	//�v���C���[�̓����Ƃ��~�߂�
	if (m_numText < 4) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
	}
	//�����Ƃ��~�߂Ȃ�
	else {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;

	}

	//���C�g�̑�����~�߂�
	if (m_numText < 3) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
	}
	//�~�߂Ȃ�
	else {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
	}

	//3�̏ꍇ�e�L�X�g���~�߂�
	if (m_numText == 3) {
		m_isTextStop = true;

		if (Game::gameInstance->GetInputMNG()->Click(L"LIGHT_CHANGE")) {
			m_isTextStop = false;
			m_frameCnt = VISIBLE_TIME-1;
		}
	}

	//���C�g�̃C���^���N�g�L�[��\��
	if (m_numText == 3) {
		m_interactKey->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_B], 0);
		m_interactKey->SetisVisible(true);
	}
	//�ړ��L�[��\��
	else if (m_numText == 4) {
		m_interactKey->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_MOVE], 0);
		m_interactKey->SetisVisible(true);
	}
	return true;

}

bool TutorialBox::Function2()
{
	//�W�����v�L�[���펞�\��
	m_interactKey->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_JUMP], 0);
	m_interactKey->SetisVisible(true);
	return true;

}

bool TutorialBox::Function3()
{
	//�v���C���[�̓����Ɠ_�����~�߂�
	if (m_numText < 3) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
	}
	//�������~�߂Ȃ�
	else {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
	}
	
	//�����v���_�������܂Ńe�L�X�g���~�߂�
	if (m_numText == 1) {
		m_isTextStop = true;

		if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
			m_isTextStop = false;
			m_frameCnt = VISIBLE_TIME - 1;
		}
	}

	//�����v�_���L�[��\��
	if (m_numText == 1) {
		m_interactKey->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::INTERACT_KEY_ON_LIGHT], 0);
		m_interactKey->SetisVisible(true);
	}

	return true;

}

bool TutorialBox::Function4()
{
	//�v���C���[�̏㉺�ړ��ȊO�����Ȃ�
	SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
	SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
	SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;

	return true;

}

bool TutorialBox::Function5()
{
	//�v���C���[�̂��ׂĂ̓�����������
	if (m_numText >= 1) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialAllStop = false;
	}
	else {
		SceneManeger::gameScene->GetPlayer()->m_tutorialAllStop = true;
	}

	return true;

}
bool TutorialBox::Function6()
{
	if (m_numText == 1 && m_frameCnt == VISIBLE_TIME - 1) {
		m_isPlayerHit = false;
	}
	return true;
}
bool TutorialBox::Function7()
{
	return true;

}
bool TutorialBox::Function8()
{

	return true;

}
bool TutorialBox::Function9()
{
	if (m_numText == 1 && m_frameCnt==VISIBLE_TIME - 1) {
		m_isTextStop = true;
		//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
		Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);

	}

	return true;
}

void TutorialBox::SpawnTutorialBox()
{
	float *tutorialInfo=Status::ReadTutorial();

	int pictureNum = 0;
	int number = 0;
	for (int i = 0; i <= GAME_INFO::TUTORIAL_BOX_NUM * 3 - 1; i += 3) {
		auto tutorialBox = shared_ptr<TutorialBox>(new TutorialBox(Point{ tutorialInfo[i],tutorialInfo[i + 1] }));
		tutorialBox->SpawnMove(1, 1);
		tutorialBox->m_sentenceMaxNum = (pictureNum + tutorialInfo[i + 2] - 1);
		tutorialBox->m_sentenceFirstNum = pictureNum;
		tutorialBox->m_number = number;

		if (number == 8) {
			SceneManeger::gameScene->m_tutorialBoxClear = tutorialBox;
		}

		++number;
		pictureNum += tutorialInfo[i + 2];


		Game::gameInstance->GetActorMNG()->AddActor(tutorialBox);
	}

}
