#include "Enemy.h"
#include <iostream>
using namespace std;

void(Enemy::* Enemy::funcTable[])() =
{
	&Enemy::Proximity,
	&Enemy::Shot,
	&Enemy::Ecession
};
void Enemy::Proximity()
{
	cout << "敵の近接！" << endl;
}

void Enemy::Shot()
{
	cout << "敵の射撃!" << endl;
}

void Enemy::Ecession()
{
	cout << "敵の離脱!" << endl;
}

void Enemy::Update()
{
	if (live)
	{
		(this->*funcTable[num])();
	}
	int select = 0;
	cout << "1を押してください" << endl;
	cin >> select;
	num++;
	if (num >= 3)
	{
		num = 0;
		live = false;
	}
}



void Enemy::Draw()
{

}
