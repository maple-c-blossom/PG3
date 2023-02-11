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
	Update();
	Draw();
}

void SceneManager::Initialize()
{


}

void SceneManager::Update()
{

}

void SceneManager::Draw()
{


}

void SceneManager::ChengeScene(int sceneNo)
{
	this->sceneNo = sceneNo;
}
