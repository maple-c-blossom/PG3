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
	cout << "�G�̋ߐځI" << endl;
}

void Enemy::Shot()
{
	cout << "�G�̎ˌ�!" << endl;
}

void Enemy::Ecession()
{
	cout << "�G�̗��E!" << endl;
}

void Enemy::Update()
{
	if (live)
	{
		(this->*funcTable[num])();
	}
	int select = 0;
	cout << "1�������Ă�������" << endl;
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
