#include "Framework.h"

constexpr int VISIBLE_TIME = 60;

TutorialBox::TutorialBox(Point pos)
	:Actor(pos)
	,m_isPlayerHit(false)
	,m_frameCnt(0)
	,m_numText(0)
	,m_isTextStop(false)
	,m_next(false)
	,m_function3Up(false)
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


	m_trianglePicture= shared_ptr<PictureCmp>(new PictureCmp(this,TUTORIAL_INFO::TRIANGLE_SIZE, UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::TRIANGLE], 0, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
	AddComponent(m_trianglePicture);
	m_trianglePicture->m_picture->SetisVisible(false);
	m_trianglePicture->m_isPosCahnge = false;

	//�C���^���N�g�L�[�`��
	m_interactKey = shared_ptr<InteractKeyCmp>(new InteractKeyCmp(this,E_INTERACT_KIND::NONE));
	AddComponent(m_interactKey);

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

		if (++m_frameCnt >= VISIBLE_TIME) {


			if (Game::gameInstance->GetInputMNG()->Click(L"OK") || m_next) {
				++m_numText;
				if (m_numText + m_sentenceFirstNum > m_sentenceMaxNum) {
					m_trianglePicture->m_picture->SetisVisible(false);

					m_picture->m_isActive = false;
				}
				else {
					m_picture->ChangePicture(&UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::SENTENCE], m_numText + m_sentenceFirstNum);
					m_interactKey->SetParam(E_INTERACT_KIND::NONE);
					m_interactKey->DeletePicture();

					m_trianglePicture->m_picture->SetisVisible(false);
				}

				m_next = false;
				m_frameCnt = 0;
			}
			else if(m_picture->m_isActive){
				//�N���b�N�\�L
				auto pos = m_picture->GetPos();
				pos.x = ((m_picture->m_pictureSizeX * 0.5f) * m_picture->m_size * m_picture->m_scaleX) + WINDOW_INFO::GAME_WIDTH_HALF + 10;
				m_trianglePicture->m_picture->SetPos(Point{ pos.x + 15,pos.y + 15 });

				m_trianglePicture->m_picture->SetisVisible(true);
			}
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

			for (auto a : SceneManeger::gameScene->m_tutorialBox) {
				if (a->m_picture != nullptr) a->m_picture->m_isActive = false;
			}

			//�`��
			m_picture = shared_ptr<Picture>(new Picture(Point{ WINDOW_INFO::GAME_WIDTH_HALF,150 }, TUTORIAL_INFO::SIZE, &UI::TUTORIAL_LIST[UI::TUTORIAL_TYPE::SENTENCE], m_sentenceFirstNum, E_PIVOT::CENTER, E_SORT::SORT_TUTORIAL_SENTENCE));
			Game::gameInstance->GetPictureMNG()->AddPicture(m_picture);
		}
	}
}

void TutorialBox::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}

bool TutorialBox::Function1()
{
	if (m_numText == 0) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialGoalLight = false;
	}

	//�v���C���[�̓����Ƃ��~�߂�
	if (m_numText < 8) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
	}
	//�����Ƃ��~�߂Ȃ�
	else {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
	}


	//3�̏ꍇ�e�L�X�g���~�߂�
	if (m_numText == 3) {
		m_isTextStop = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;


		if (Game::gameInstance->GetInputMNG()->Click(L"LIGHT_CHANGE")) {
			m_isTextStop = false;
			m_frameCnt = VISIBLE_TIME;
			m_next = true;
			SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
		}
	}
	//3�̏ꍇ�e�L�X�g���~�߂�
	if (m_numText == 5) {
		m_isTextStop = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;

		if (Game::gameInstance->GetInputMNG()->Click(L"LIGHT_CHANGE")) {
			m_isTextStop = false;
			m_frameCnt = VISIBLE_TIME;
			m_next = true;
			SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;

		}
	}

	//�����ł���
	if (m_numText == 7 && m_frameCnt==0) {
		SceneManeger::gameScene->GetPlayer()->OnLight();
	}

	//���C�g�̃C���^���N�g�L�[��\��
	if (m_numText == 3) {
		m_interactKey->SetParam(E_INTERACT_KIND::LIGHT);
	}

	//���C�g�̃C���^���N�g�L�[��\��
	if (m_numText == 5) {
		m_interactKey->SetParam(E_INTERACT_KIND::LIGHT);
	}
	//�ړ��L�[��\��
	if (m_numText == 8) {
		m_interactKey->SetParam(E_INTERACT_KIND::MOVE);
		m_frameCnt = 0;
	}
	return true;
}

bool TutorialBox::Function2()
{
	if (m_numText == 0) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
	}

	if (m_numText == 1) {
		//�W�����v�L�[���펞�\��
		m_interactKey->SetParam(E_INTERACT_KIND::JUMP);
		m_frameCnt = 0;

		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
	}
	return true;

}

bool TutorialBox::Function3()
{
	//�v���C���[�̓����Ɠ_�����~�߂�
	if (m_numText < 3) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
	}
	//�������~�߂Ȃ�
	else {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
		m_frameCnt = 0;
		m_frameCnt = 0;
	}
	
	//�����v���_�������܂Ńe�L�X�g���~�߂�
	if (m_numText == 1) {
		m_isTextStop = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialGoalLight = true;

		if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
			m_function3Up = true;
		}

		if (m_function3Up) {
			if (++m_function3Frame==90) {
				m_next = true;
				m_isTextStop = false;
				m_frameCnt = VISIBLE_TIME;
			}
		}
	}

	//�����v�_���L�[��\��
	if (m_numText == 1) {
		m_interactKey->SetParam(E_INTERACT_KIND::INTERACT);
	}

	return true;
}

bool TutorialBox::Function4()
{
	if (m_numText == 0) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = false;

	}
	else {
		//�v���C���[�̏㉺�ړ��ȊO�����Ȃ�
		m_frameCnt = 0;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = true;
	}

	if (m_numText == 1) {
		m_interactKey->SetParam(E_INTERACT_KIND::INTERACT);
	}

	return true;

}

bool TutorialBox::Function5()
{
	//�v���C���[�̂��ׂĂ̓�����������
	if (m_numText >= 1) {
		m_frameCnt = 0;
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = true;
	}
	else {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = false;
	}

	return true;

}
bool TutorialBox::Function6()
{
	if (m_numText == 1 && m_frameCnt == VISIBLE_TIME - 1) {
		m_isPlayerHit = false;
	}

	if (m_numText == 0) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = false;
	}
	else {
		m_frameCnt = 0;
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = true;
	}
	return true;
}
bool TutorialBox::Function7()
{

	if (m_numText == 0) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = false;
	}
	else {
		m_frameCnt = 0;
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = true;
	}
	return true;

}
bool TutorialBox::Function8()
{
	if (m_numText == 0) {
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = false;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = false;
	}
	else {
		m_frameCnt = 0;
		SceneManeger::gameScene->GetPlayer()->m_tutorialLight = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialJump = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_X = true;
		SceneManeger::gameScene->GetPlayer()->m_tutorialMove_Y = true;
	}
	return true;

}
bool TutorialBox::Function9()
{
	SceneManeger::gameScene->GetPlayer()->m_tutorialAllStop = true;

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

		SceneManeger::gameScene->m_tutorialBox.push_back(tutorialBox);
		Game::gameInstance->GetActorMNG()->AddActor(tutorialBox);
	}

}
