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
		cout << "終了をする場合Anyキーを押してEnter,続行する場合何も入力せずにEnterを押してください" << endl;
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
		cout << "何も入力せずEnterを入力で次のシーンへ移動" << endl;
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
			cout << "何も入力しないでください" << endl;
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
