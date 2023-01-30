#include "Enemy.h"
#include <iostream>
using namespace std;
bool Enemy::live = true;

void Enemy::Update(int actionSelect)
{
	switch (actionSelect)
	{
	case 1:
		hp--;
		break;
	case 2:
		hp = 0;
		break;
	default:
		break;
	}
	if (hp <= 0)
	{
		live = false;
	}
}



void Enemy::Draw()
{
	cout << "hp‚ÍŽc‚è" << hp << "‚¾" << endl;
}
