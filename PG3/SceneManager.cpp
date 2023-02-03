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
	Initialize();
	while (true)
	{
		Update();
		Draw();
		if (!enemy.GetLive())
		{
			break;
		}

	}
}

void SceneManager::Initialize()
{

}

void SceneManager::Update()
{
	enemy.Update();
}

void SceneManager::Draw()
{
	enemy.Draw();

}

void SceneManager::ChengeScene(int sceneNo)
{
	this->sceneNo = sceneNo;
}
