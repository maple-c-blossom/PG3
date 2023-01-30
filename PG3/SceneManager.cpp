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
	cout << "敵全滅で終了" << endl;
	cout << "１を押して攻撃,2を押して即殺,3をおして見逃し" << endl;
	cin >> select;
	if (select == 1 || select == 2)
	{
		cout << "0 〜 9の範囲で攻撃対象を指定" << endl;
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
	cout << "敵の残り:" << enemys.size()<<"体" << endl;
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
