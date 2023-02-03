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
	cout << "“G‚Ì‹ßÚI" << endl;
}

void Enemy::Shot()
{
	cout << "“G‚ÌŽËŒ‚!" << endl;
}

void Enemy::Ecession()
{
	cout << "“G‚Ì—£’E!" << endl;
}

void Enemy::Update()
{
	if (live)
	{
		(this->*funcTable[num])();
	}
	int select = 0;
	cout << "1‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
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
