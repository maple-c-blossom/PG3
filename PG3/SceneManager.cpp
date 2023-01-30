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
		if (enemys.size() <= 0)
		{
			break;
		}

	}
}

void SceneManager::Initialize()
{
	for (int i = 0; i < 10; i++)
	{
		unique_ptr<Enemy> temp = make_unique<Enemy>();
		enemys.push_back(move(temp));
	}
}

void SceneManager::Update()
{
	int select = 0;
	int attack = 0;
	cout << "“G‘S–Å‚ÅI—¹" << endl;
	cout << "‚P‚ð‰Ÿ‚µ‚ÄUŒ‚,2‚ð‰Ÿ‚µ‚Ä‘¦ŽE,3‚ð‚¨‚µ‚ÄŒ©“¦‚µ" << endl;
	cin >> select;
	if (select == 1 || select == 2)
	{
		cout << "0 ` 9‚Ì”ÍˆÍ‚ÅUŒ‚‘ÎÛ‚ðŽw’è" << endl;
		cin >> attack;
		if (attack > 9 || attack < 0)
		{
			attack = 0;
		}
	}

	decltype(enemys)::iterator itr = enemys.begin();
	for (int i = 0; i < attack; i++)
	{
		itr++;
	}
	itr->get()->Update(select);

	enemys.remove_if([](unique_ptr<Enemy>& itr) {return !itr->live; });
	cout << "“G‚ÌŽc‚è:" << enemys.size()<<"‘Ì" << endl;
}

void SceneManager::Draw()
{
	for (auto& itr : enemys)
	{
		itr->Draw();
	}
}

void SceneManager::ChengeScene(int sceneNo)
{
	this->sceneNo = sceneNo;
}
