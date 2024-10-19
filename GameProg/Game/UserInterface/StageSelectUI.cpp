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

void StageSelectUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);
	LordFile();

	m_nowcursor = 0;

	//��ʂ̕����擾
	LONG scrX = scene->screenX;
	LONG scrY = scene->screenY;

	
	//�X�e�[�W��
	m_stageArray[0] = std::shared_ptr<Picture>(new Picture(POINT{250,scrY / 2 + 200}, 0.4, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI,true,true));
	m_stageMarkers[0] = m_stageArray[0]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[0]);

	//�X�e�[�W�^��
	m_stageArray[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 200 }, 0.4, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI));
	m_stageMarkers[1] = m_stageArray[1]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[1]);

	//�X�e�[�W�E
	m_stageArray[2] = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 250 ,scrY / 2 + 200 }, 0.4, "Picture/stageSelectPoint2.png", PIVOT::CENTER, SORT::SORT_UI));
	m_stageMarkers[2] = m_stageArray[2]->GetPos();
	UserInterface::AddPictureInUI(m_stageArray[2]);

	//�ʒu�̒���
	for (int i = 0; i <= 2; i++) {
		m_stageMarkers[i].y -= 100;
	}

	//���j���[�Z���N�g�A�C�R��
	m_menuIcon = std::shared_ptr<Picture>(new Picture(POINT{ scrX - 50,  50 }, 0.2, "Picture/MenuIcon_Off.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_menuIcon);

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture(m_stageMarkers[1], 3, "Picture/jiki.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//���w�i
	m_backGround = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 }, 5, "Picture/stageSelectPoint2.png", PIVOT::CENTER, SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//���j���[�Z���N�g
	m_menuSelect= std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2-200 }, 0.2, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menuSelect);

	//�N���W�b�g
	m_menu[0] = std::shared_ptr<Picture>(new Picture(POINT{300 ,scrY / 2 + 150}, 0.2, "Picture/MS_Credit_on.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[0]);

	//�I�v�V����
	m_menu[1] = std::shared_ptr<Picture>(new Picture(POINT{ scrX-300 ,scrY / 2 + 150 }, 0.2, "Picture/MS_Option_off.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_menu[1]);

	//�t�H���g�̕`��
	m_fontHandle = CreateFontToHandle("MS �S�V�b�N", 80, 1);
	m_stageTitlePos = POINT{ 100,100 };
	LordFileText();

}

void StageSelectUI::Update()
{
	UserInterface::Update();

	//���j���[�Z���N�g��ʂŃL�����Z�����������Ƃ�
	if (KeyClick(KEY_INPUT_BACK) >= 1) {
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
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::TITLE);
			//���ɖ߂�
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//����
	if (KeyClick(KEY_INPUT_SPACE) >= 1 ) {
		if (!m_isMenu) {
			switch (m_colSelectNum)
			{
			case 0:
				//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
				m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
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
			case 0:
				break;
			case 1:
				break;
			}
		}
		
	}

	//���j���[�Z���N�g�ł͂Ȃ���
	if (!m_isMenu) {
		//���J�[�\���̕ύX
		if (m_colSelectNum == 0) {
			if (KeyClick(KEY_INPUT_D) >= 1) {
				if (m_nowcursor != 20) {
					//�J�[�\�������ɂ��炷
					m_nowcursor++;
				}
			}
			if (KeyClick(KEY_INPUT_A) >= 1) {
				if (m_nowcursor != 0) {
					//�J�[�\������ɂ��炷
					m_nowcursor--;
				}
			}
		}
		//�c�J�[�\���̕ύX
		if (KeyClick(KEY_INPUT_W) >= 1) {
			if (m_colSelectNum != 1) {
				//�J�[�\�������ɂ��炷
				m_colSelectNum++;
				m_menuIcon->ChangePicture("Picture/MenuIcon_On.png");
			}
		}
		if (KeyClick(KEY_INPUT_S) >= 1) {
			if (m_colSelectNum != 0) {
				//�J�[�\������ɂ��炷
				m_colSelectNum--;
				m_menuIcon->ChangePicture("Picture/MenuIcon_Off.png");
			}
		}
	}
	else {
		//���J�[�\���̕ύX
		if (KeyClick(KEY_INPUT_D) >= 1) {
			if (m_isNowMenuCursor != 1) {
				//�J�[�\�������ɂ��炷
				m_isNowMenuCursor++;
				m_menu[0]->ChangePicture("Picture/MS_Credit_off.png");
				m_menu[1]->ChangePicture("Picture/MS_Option_on.png");
			}
		}
		if (KeyClick(KEY_INPUT_A) >= 1) {
			if (m_isNowMenuCursor != 0) {
				//�J�[�\������ɂ��炷
				m_isNowMenuCursor--;
				m_menu[0]->ChangePicture("Picture/MS_Credit_on.png");
				m_menu[1]->ChangePicture("Picture/MS_Option_off.png");
			}
		}
	}
}

void StageSelectUI::Draw()
{
	UserInterface::Draw();

	if(!m_isMenu)
		DrawFormatStringFToHandle(m_stageTitlePos.x, m_stageTitlePos.y, GetColor(255, 255, 255), m_fontHandle,"�X�e�[�W%d�@%s", m_nowcursor,m_stageTitle[m_nowcursor].c_str());

	auto j = 0;
	for (int i = m_nowcursor; i < m_nowcursor + 3; i++) {
		if (m_stage[i] == true) {
			m_stageArray[j]->ChangePicture("Picture/stageSelectPoint1.png");
		}
		else {
			m_stageArray[j]->ChangePicture("Picture/stageSelectPoint2.png");
		}
		j++;
	}

	if (m_nowcursor == 0) {
		m_stageArray[0]->SetIsAlpha(true);
		m_stageArray[0]->SetAlpha(0);
	}
	else if(m_nowcursor == 20){
		m_stageArray[2]->SetIsAlpha(true);
		m_stageArray[2]->SetAlpha(0);
	}
	else {
		for (auto& array : m_stageArray) {
			array->SetIsAlpha(false);
			array->SetAlpha(255);
		}
	}

}

void StageSelectUI::LordFile()
{
	const wstring chipSet = L"01";

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
			if (checkNo == string::npos) {
				stageClear = false;
			}
			else if (checkNo == 0) {
				stageClear = false;
			}
			else if (checkNo == 1) {
				stageClear = true;
			}
		}
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
