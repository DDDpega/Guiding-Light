#include "Framework.h"

StageSelectUI::StageSelectUI()
	:UserInterface(true, true)
	, m_stage()
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
	UserInterface::Initialize();
	LordFile();

	m_nowcursor = 0;

	//��ʂ̕����擾
	LONG scrX = WINDOW_INFO::GAME_WIDTH;
	LONG scrY = WINDOW_INFO::GAME_HEIGHT;
	
	//�X�e�[�W��
	m_stageArray[0] = std::shared_ptr<Picture>(new Picture(POINT{250,scrY / 2 + 200}, 0.4, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI,true,false));
	m_stageMarkers[0] = m_stageArray[0]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[0]);

	//�X�e�[�W�^��
	m_stageArray[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 200 }, 0.4, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	m_stageMarkers[1] = m_stageArray[1]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[1]);

	//�X�e�[�W�E
	m_stageArray[2] = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 250 ,scrY / 2 + 200 }, 0.4, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	m_stageMarkers[2] = m_stageArray[2]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[2]);

	//�ʒu�̒���
	for (int i = 0; i <= 2; i++) {
		m_stageMarkers[i].y -= 100;
	}

	//���j���[�Z���N�g�A�C�R��
	m_menuIcon = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 50,  50 }, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_menuIcon);

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture(m_stageMarkers[1], 3, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//���w�i
	m_backGround = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 }, 5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//���j���[�Z���N�g
	m_menuSelect= std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2-200 }, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menuSelect);

	//�N���W�b�g
	m_menu[0] = std::shared_ptr<Picture>(new Picture(POINT{300 ,scrY / 2 + 150}, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[0]);

	//�I�v�V����
	m_menu[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX-300 ,scrY / 2 + 150 }, 0.2, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[1]);

	//�t�H���g�̕`��
	m_fontHandle = CreateFontToHandle("MS �S�V�b�N", 80, 1);
	m_stageTitlePos = POINT{ 50,100 };
	LordFileText();

}

void StageSelectUI::Update()
{
	UserInterface::Update();

	//���j���[�Z���N�g��ʂŃL�����Z�����������Ƃ�
	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
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
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::TITLE);
			//���ɖ߂�
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//����
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		if (!m_isMenu) {
			switch (m_colSelectNum)
			{
			case 0:
				//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
				Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::GAME);
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
			switch (m_colSelectNum)
			{
				//�I�v�V����
			case 0:
				break;
				//�N���W�b�g
			case 1:
				break;
			}
		}
		
	}

	//���j���[�Z���N�g�ł͂Ȃ���
	if (!m_isMenu) {
		//���J�[�\���̕ύX
		if (m_colSelectNum == 0) {
			if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")) {
				if (m_nowcursor != 20) {
					//�J�[�\�������ɂ��炷
					m_nowcursor++;
				}
			}
			if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
				if (m_nowcursor != 0) {
					//�J�[�\������ɂ��炷
					m_nowcursor--;
				}
			}
		}
		//�c�J�[�\���̕ύX
		if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
			if (m_colSelectNum != 1) {
				//�J�[�\�������ɂ��炷
				m_colSelectNum++;
				m_menuIcon->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
			if (m_colSelectNum != 0) {
				//�J�[�\������ɂ��炷
				m_colSelectNum--;
				m_menuIcon->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
	}
	else {
		//���J�[�\���̕ύX
		if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")) {
			if (m_isNowMenuCursor != 1) {
				//�J�[�\�������ɂ��炷
				m_isNowMenuCursor++;
				m_menu[0]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
				m_menu[1]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
		if (Game::gameInstance->GetInputMNG()->Click(L"LEFT")) {
			if (m_isNowMenuCursor != 0) {
				//�J�[�\������ɂ��炷
				m_isNowMenuCursor--;
				m_menu[0]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
				m_menu[1]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
			}
		}
	}
}

void StageSelectUI::Draw()
{
	UserInterface::Draw();

	//���j���[�Z���N�g���J���ĂȂ���Ԃ̎��A�X�e�[�W�ԍ��ƃX�e�[�W�^�C�g����ύX����
	if(!m_isMenu)
		DrawFormatStringFToHandle(m_stageTitlePos.x, m_stageTitlePos.y, GetColor(255, 255, 255), m_fontHandle,"�X�e�[�W%d�@%s", m_nowcursor,m_stageTitle[m_nowcursor].c_str());

	auto j = 0;
	for (int i = m_nowcursor; i < m_nowcursor + 3; i++) {
		//�J�[�\���̈ʒu�����炷
		if (m_stage[i] == true) {
			m_stageArray[j]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
		}
		else {
			m_stageArray[j]->ChangePicture(UI::TITLE_LIST[UI::TITLE_TYPE::TITLE]);
		}
		j++;
	}

	//�I������Ă���X�e�[�W��0�Ȃ�
	if (m_nowcursor == 0) {
		//��������
		m_stageArray[0]->SetisVisible(false);
		
	}
	//�I������Ă���X�e�[�W��20�Ȃ�
	else if(m_nowcursor == 20){
		//�E������
		m_stageArray[2]->SetisVisible(false);
		
	}
	//����ȊO�̎��͑S�Ă�\������
	else {
		for (auto& array : m_stageArray) {
			array->SetisVisible(true);
		
		}
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

	

	for (int r = 0; r < 20; r++) {
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
		m_stage[r] = stageClear;
	}
	//�������ǂݍ��߂�s���Ȃ��Ȃ�ΏI��
	if (ifs.eof()) {
		ifs.close();
	}
}


//�t�@�C������f�[�^��ǂݍ��ރ��\�b�h
void StageSelectUI::LordFileText()
{
	//�X�e�[�W�^�C�g���̃f�[�^�擾
	const wstring filePath = L"Data/StageText.txt";

	ifstream ifs;

	//�t�@�C�����J��
	ifs.open(filePath.c_str());

	//���s�����牽�����Ȃ�
	if (ifs.fail()) {
		return;
	}

	//�t�@�C������擾����������
	string col;



	for (int r = 0; r < 21; r++) {
		//�t�@�C������1�s�ǂݍ���
		getline(ifs, col);
		m_stageTitle[r] = col;
	}
	//�������ǂݍ��߂�s���Ȃ��Ȃ�ΏI��
	if (ifs.eof()) {
		ifs.close();
	}
}
