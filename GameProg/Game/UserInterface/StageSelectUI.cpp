#include "Framework.h"

StageSelectUI::StageSelectUI()
	:UserInterface(true, true)
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

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture(m_stageMarkers[1], 3, "Picture/jiki.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

}

void StageSelectUI::Update()
{
	UserInterface::Update();


	//����
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {
		//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
		m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
		//���ɖ߂�
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//�J�[�\���̕ύX
	if (KeyClick(KEY_INPUT_RIGHT) >= 1) {
		if (m_nowcursor != 20) {
			//�J�[�\�������ɂ��炷
			m_nowcursor++;
		}
	}
	if (KeyClick(KEY_INPUT_LEFT) >= 1) {
		if (m_nowcursor != 0) {
			//�J�[�\������ɂ��炷
			m_nowcursor--;
		}
	}
}

void StageSelectUI::Draw()
{
	UserInterface::Draw();
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
