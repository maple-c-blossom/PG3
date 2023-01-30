#include "SceneManager.h"
#include <iostream>
#include <string>
using namespace std;

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}

void SceneManager::Run()
{
	string deleteSelect;
	while (true)
	{
		Update();
		Draw();
		cout << "�I��������ꍇAny�L�[��������Enter,���s����ꍇ�������͂�����Enter�������Ă�������" << endl;
		getline(cin, deleteSelect);
		cin.ignore(1024, '\n');
		if (deleteSelect != "\0")
		{
			break;
		}

	}
}

void SceneManager::Update()
{
	while (true)
	{
		string  sceneNum ;
		cout << "�������͂���Enter����͂Ŏ��̃V�[���ֈړ�" << endl;
		getline(cin, sceneNum);
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore(1024, '\n');
		if (sceneNum == "\0")
		{
			int selectSceneNo = sceneNo;
			selectSceneNo++;
			if (selectSceneNo > (int)SceneNum::GameClear)
			{
				selectSceneNo = (int)SceneNum::Title;
			}
			ChengeScene(selectSceneNo);
			break;
		}
		else
		{
			cout << "�������͂��Ȃ��ł�������" << endl;
			continue;
		}
	}
}

void SceneManager::Draw()
{
	switch (sceneNo)
	{
	case (int)SceneNum::Title:
		cout << "nowScene:Title" << endl;
		break;
	case (int)SceneNum::NewGame:
		cout << "nowScene:NewGame" << endl;
		break;
	case (int)SceneNum::GamePlay:
		cout << "nowScene:GamePlay" << endl;
		break;
	case (int)SceneNum::GameClear:
		cout << "nowScene:GameClear" << endl;
		break;
	default:
		sceneNo = (int)SceneNum::Title;
		break;
	}
}

void SceneManager::ChengeScene(int sceneNo)
{
	this->sceneNo = sceneNo;
}
