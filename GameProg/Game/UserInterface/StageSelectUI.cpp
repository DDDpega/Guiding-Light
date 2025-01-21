#include "Framework.h"

StageSelectUI::StageSelectUI()
	:UserInterface(true, true)
	, m_isStageClear()
	, m_stageArray()
	, m_stageMarkers()
	, m_colSelectNum(0)
	, m_isMenu(false)
	, m_isNowMenuCursor(0)
	
{
	
}

StageSelectUI::~StageSelectUI()
{
}

void StageSelectUI::Initialize()
{
	auto cursror = m_nowcursor;
	UserInterface::Initialize();
	m_nowcursor = cursror;
	LordFile();
	m_isRight = false;
	m_isLeft = false;

	m_isStageImplement[21] = {false};

	auto stageSize = SceneManeger::gameScene->GetStageSize();
	

	for (int i = 0; i <= stageSize; i++) {
		m_isStageImplement[i] = true;
	}
	m_isStageImplement[0] = false;

	//��ʂ̕����擾
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;
	
	//�X�e�[�W��
	m_stageArray[0] = std::shared_ptr<Picture>(new Picture(Point{250,scrY / 2 + 200}, 0.4, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI,true,false));
	m_stageMarkers[0] = m_stageArray[0]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[0]);
	m_stageLampArray[0] = std::shared_ptr<Picture>(new Picture(Point{ 250 ,scrY / 2 + 100 }, 5, &ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_stageLampArray[0]);


	//�X�e�[�W�^��
	m_stageArray[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 + 200 }, 0.4, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	m_stageMarkers[1] = m_stageArray[1]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[1]);
	m_stageLampArray[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 + 100 }, 5, &ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_stageLampArray[1]);


	//�X�e�[�W�E
	
	m_stageMarkers[2] = Point{ scrX - 250 ,scrY / 2 + 200 };

	//���E�̍�
	m_stageDifference = m_stageMarkers[2].x - m_stageMarkers[1].x;

	

	/*auto x = (scrX - 250) + m_stageDifference * (3 - 2);
	m_stageArray[3] = std::shared_ptr<Picture>(new Picture(Point{ x  ,scrY / 2 + 200 }, 0.4, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));

	UserInterface::AddPictureInUI(m_stageArray[3]);*/

	for (int i = 2; i < size(m_stageArray); i++) {
		m_stageArray[i]= std::shared_ptr<Picture>(new Picture(Point{ (scrX - 250)+m_stageDifference*(i-1) ,scrY / 2 + 200 }, 0.4, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
		
		UserInterface::AddPictureInUI(m_stageArray[i]);
	}

	for (int i = 2; i < size(m_stageLampArray); i++) {
		m_stageLampArray[i] = std::shared_ptr<Picture>(new Picture(Point{ (scrX - 250) + m_stageDifference * (i - 1) ,scrY / 2 + 100 }, 5, &ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));

		UserInterface::AddPictureInUI(m_stageLampArray[i]);
	}


	
	//�ʒu�̒���
	for (int i = 0; i < 3; i++) {
		m_stageMarkers[i].y -= 100;
	}

	//�X�e�[�W�ԍ�
	m_stageNum = std::shared_ptr<Picture>(new Picture(Point{100,  100 }, 0.5, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_stageNum);

	//�X�e�[�W�^�C�g��
	m_stageTitle = std::shared_ptr<Picture>(new Picture(Point{ 600,  100 }, 0.5, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_stageTitle);

	//���j���[�Z���N�g�A�C�R��
	m_menuIcon = std::shared_ptr<Picture>(new Picture(Point{ scrX - 50,  50 }, 2, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENU_N_LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_menuIcon);

	//�L����
	m_arrow = std::shared_ptr<Picture>(new Picture(Point{-100, m_stageMarkers[1].y }, 6, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_PLAYER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//���w�i
	m_backGround = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 }, 1, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(225);

	//���j���[�Z���N�g
	m_menuSelect= std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2-200 }, 0.8, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENUSELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menuSelect);

	//�N���W�b�g
	m_menu[0] = std::shared_ptr<Picture>(new Picture(Point{300 ,scrY / 2 + 150}, 0.25, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::CREDIT_N_LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[0]);

	//�I�v�V����
	m_menu[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX-300 ,scrY / 2 + 150 }, 0.25, &UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::OPTION_LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[1]);

	//�t�F�[�h
	m_fadeUI = shared_ptr<FadeUI>(new FadeUI());
	m_fadeUI->Initialize();

	m_isRightFade = Game::gameInstance->GetSceneMNG()->GetNowScene()->m_isRightFade;
	m_frame = 0;
	m_animCnt = 0;
	m_animMax = false;

	if (m_nowcursor != 0) {
		for (int i = m_nowcursor; i>=0; i--) {
			MovePosStage(true,1,true);
		}
	}


}

void StageSelectUI::Update()
{
	
	auto frameNum = 30;
	if ((m_nowcursor == 0 && m_isLeft)|| (m_nowcursor == 1 && m_isRight))
		frameNum = 60;
	UserInterface::Update();
	if (m_isRight) {
		if (m_frame < frameNum) {
			MovePosStage(false,frameNum, m_isRight);
			if (m_frame % 3 == 0)PlayerAnim();
			m_frame++;
			
			return;
			
		}
		else {

			m_isRight = false;
			m_frame = 0;
			return;
		}
	}
	else if (m_isLeft) {
		if (m_frame < frameNum) {
			MovePosStage(false, frameNum, false);
			if (m_frame % 3 == 0)PlayerAnim();
			m_frame++;
			return;
		}
		else {

			m_isLeft = false;
			m_frame = 0;
			return;
		}
	}
	
	
	//�t�F�[�h
	if (m_isChangeScene) {
		m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);
		if (m_csframe-- < 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(m_scene,m_isRightFade);
		}
		return;
	}
	if (!m_firstFade&&m_csframe-- >= 0) {
		m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);
	}
	else if(!m_firstFade){
		m_firstFade = true;
		m_csframe = FADEFRAME;
	}
	
	//�v���C���[�ړ�
	if (m_arrow->GetPos().x < m_stageMarkers[1].x) {
		if (m_frame % 3 == 0)PlayerAnim();
		m_frame++;
		auto pos = m_arrow->GetPos();
		pos.x += 10;
		m_arrow->SetPos(pos);
		return;
	}
	else {
		m_frame = 0;
		m_arrow->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::IDOL], 0);
	}

	//���j���[�Z���N�g��ʂŃL�����Z�����������Ƃ�
	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
		if (m_isMenu) {
			m_isMenu = false;

			m_backGround->SetisVisible(false);
			m_menuSelect->SetisVisible(false);
			for (auto& menu : m_menu) {
				menu->SetisVisible(false);
			}
		}
		else {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			m_isChangeScene = true;
			m_isFeedIn = false;
			m_isRightFade = false;
			m_fadeUI->Reset();
			
			m_scene = E_SCENE::TITLE;
			//���ɖ߂�
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//����
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (!m_isMenu) {
			switch (m_colSelectNum)
			{
			case 0:
				Game::gameInstance->GetSceneMNG()->ssScene->SetStageNum(m_nowcursor);
				//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
				m_isRightFade = true;
				m_isFeedIn = false;
				m_fadeUI->Reset();
				m_isChangeScene = true;
				m_scene = E_SCENE::GAME;
				SceneManeger::gameScene->SetNumStage(m_nowcursor);
				//���ɖ߂�
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				break;
			case 1:
				m_isMenu = true;
				m_backGround->SetisVisible(true);
				m_menuSelect->SetisVisible(true);
				for (auto& menu : m_menu) {
					menu->SetisVisible(true);
				}
				break;
			}
		}
		//���j���[�Z���N�g��
		else {
			switch (m_isNowMenuCursor)
			{
				//�I�v�V����
			case 0:
				//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
				m_isChangeScene = true;
				m_isRightFade = false;
				m_isFeedIn = false;
				m_fadeUI->Reset();
				m_scene = E_SCENE::CREDIT;
				break;
				//�N���W�b�g
			case 1:
				//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
				m_isChangeScene = true;
				m_isRightFade = false;
				m_isFeedIn = false;
				m_fadeUI->Reset();
				m_scene = E_SCENE::OPTION;
				break;
			}
		}
		
	}

	//���j���[�Z���N�g�ł͂Ȃ���
	if (!m_isMenu) {
		//���J�[�\���̕ύX
		if (m_colSelectNum == 0 ) {
			if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT") && m_isStageClear[m_nowcursor]) {
				if (m_nowcursor != 7) {
					m_isSoundPlay[2] = true;
					//�J�[�\�������ɂ��炷
					m_nowcursor++;
					m_isRight = true;
					m_arrow->m_reverse = false;
				}
			}
			if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
				if (m_nowcursor != 0) {
					m_isSoundPlay[2] = true;
					//�J�[�\������ɂ��炷
					m_nowcursor--;
					m_isLeft = true;
					m_arrow->m_reverse = true;
				}
			}
		}
		//�c�J�[�\���̕ύX
		if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
			if (m_colSelectNum != 1) {
				m_isSoundPlay[2] = true;
				//�J�[�\������ɂ��炷
				m_colSelectNum++;
				m_menuIcon->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENU_LIGHT]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
			if (m_colSelectNum != 0) {
				m_isSoundPlay[2] = true;
				//�J�[�\�������ɂ��炷
				m_colSelectNum--;
				m_menuIcon->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::MENU_N_LIGHT]);
			}
		}
	}
	else {
		//���J�[�\���̕ύX
		if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")) {
			if (m_isNowMenuCursor != 1) {
				//�J�[�\�����E�ɂ��炷
				m_isNowMenuCursor++;
				m_menu[0]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::CREDIT_LIGHT]);
				m_menu[1]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::OPTION_N_LIGHT]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
			if (m_isNowMenuCursor != 0) {
				//�J�[�\�������ɂ��炷
				m_isNowMenuCursor--;
				m_menu[0]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::CREDIT_N_LIGHT]);
				m_menu[1]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::OPTION_LIGHT]);
			}
		}
	}
}

void StageSelectUI::Draw()
{
	UserInterface::Draw();

	//���j���[�Z���N�g���J���ĂȂ���Ԃ̎��A�X�e�[�W�ԍ��ƃX�e�[�W�^�C�g����ύX����
	if (!m_isMenu)
	{
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1], m_nowcursor);
		m_stageTitle->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::T_STAGE_1], m_nowcursor);
	}

	bool isfirst = false;

	//DrawFormatStringFToHandle(m_stageTitlePos.x, m_stageTitlePos.y, GetColor(255, 255, 255), m_fontHandle,"�X�e�[�W%d�@%s", m_nowcursor,m_stageTitle[m_nowcursor].c_str());
	//+1���Ă��闝�R�͉E�ɓ�X�e�[�W�I���摜��p�ӂ��邽��
	for (int i = m_nowcursor ; i < m_nowcursor + 3; i++) {
		if (i>0&&isfirst == false) {
			isfirst = true;
			i--;
		}
		//�J�[�\���̈ʒu�����炷
		if (m_isStageClear[i] == true) {
			m_stageArray[i+1]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_CLEAR]);
			m_stageLampArray[i+1]->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 1);
		}
		else {
			m_stageArray[i + 1]->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::SELECT_N_CLEAR]);
			m_stageLampArray[i + 1]->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT]);
		}
	}

	if (!m_isStageClear[m_nowcursor]) {
		m_stageArray[m_nowcursor+2]->SetisVisible(false);
		m_stageLampArray[m_nowcursor+2]->SetisVisible(false);
	}

	//�����ς݂̂�ȊO������
	if (!m_isStageImplement[m_nowcursor]) {
		m_stageArray[m_nowcursor]->SetisVisible(false);
		m_stageLampArray[m_nowcursor]->SetisVisible(false);
	}

	for (int i = m_nowcursor; i < size(m_stageArray); i++) {
		if (!m_isStageImplement[i] && m_nowcursor != 21) {
			m_stageArray[i]->SetisVisible(false);
			m_stageLampArray[i]->SetisVisible(false);
		}
	}

}

void StageSelectUI::MovePosStage(bool isFrast,int framenum, bool isRight)
{
	auto num = 1;
	if (!isRight)num *= -1;

	for (int j = 0; j < size(m_stageArray); j++) {
		auto pos = m_stageArray[j]->GetPos();
		auto pos2 = m_stageLampArray[j]->GetPos();
		if ((m_nowcursor == 1 && isRight&& isFrast==false) || (m_nowcursor == 0 && !isRight)) {
			pos.x -= ((m_stageDifference * 2) / framenum) * num;
			//�����v

			pos2.x -= ((m_stageDifference * 2) / framenum) * num;
		}
		else {
			pos.x -= (m_stageDifference / framenum) * num;
			//�����v

			pos2.x -= (m_stageDifference / framenum) * num;
		}
		m_stageArray[j]->SetPos(pos);

		m_stageLampArray[j]->SetPos(pos2);
	}
}

void StageSelectUI::LordFile()
{
	//0=false,1=true�̈Ӗ�
	const wstring chipSet = L"01";
	//�X�e�[�W�̃N���A��Ԃ̃f�[�^�e�L�X�g�擾
	const wstring filePath = L"Data/StageData.txt";

	wifstream ifs;

	//�t�@�C�����J��
	ifs.open(filePath.c_str());

	//���s�����牽�����Ȃ�
	if (ifs.fail()) {
		return;
	}

	//�t�@�C������擾����������
	wstring col;
	//�`�F�b�N�ԍ�
	int checkNo;
	//�N���A�ς݂��ǂ���
	bool stageClear;

	//�t�@�C������1�s�ǂݍ���
	getline(ifs, col);

	

	for (int r = 0; r < 21; r++) {
		//�񂪕������𒴂��Ă�����-1
		if (r >= col.length()) {
			checkNo = 0;
		}
		else {
			//�����񂩂�col��r�Ԗڂ̕����Ō������ĉ��Ԗڂ����擾����
			checkNo = chipSet.find(col[r]);
			//���������Ȃ��Ȃ�N���A���ĂȂ�
			if (checkNo == string::npos) {
				stageClear = false;
			}
			//0�Ȃ�N���A���Ă��Ȃ�
			else if (checkNo == 0) {
				stageClear = false;
			}
			//1�Ȃ�N���A���Ă���
			else if (checkNo == 1) {
				stageClear = true;
			}
		}
		//�������
		m_isStageClear[r] = stageClear;
	}
	//�������ǂݍ��߂�s���Ȃ��Ȃ�ΏI��
	if (ifs.eof()) {
		ifs.close();
	}
}


void StageSelectUI::ChangeStageTitle(int num)
{
	switch (num)
	{
	case 0:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 1:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 2:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 3:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 4:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 5:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 6:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 7:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 8:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 9:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 10:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 11:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 12:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 13:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 14:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 15:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 16:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 17:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 18:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 19:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;
	case 20:
		m_stageNum->ChangePicture(&UI::STAGESELECT_LIST[UI::STAGESELECT_TYPE::S_STAGE_1]);
		break;

	default:
		break;
	}
}

void StageSelectUI::PlayerAnim()
{
	m_arrow->ChangePicture(&ILLUST::PLAYER_LIST[ILLUST::PLAYER_TYPE::MOVE], m_animCnt);
	
	if (m_animCnt + 2 > 5) {
		m_animMax = true;
	}
	else if (m_animCnt - 2 < 0) {
		m_animMax = false;
	}
	if (m_animMax) {
		m_animCnt -= 2;
	}
	else {
		m_animCnt += 2;
	}
}
