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
	shapeC = make_unique<Circle>();
	shapeR = make_unique<Rectangle>();

}

void SceneManager::Update()
{
	shapeC->size();
	shapeR->size();
}

void SceneManager::Draw()
{

	shapeC->draw();
	shapeR->draw();
}

void SceneManager::ChengeScene(int sceneNo)
{
	this->sceneNo = sceneNo;
}
