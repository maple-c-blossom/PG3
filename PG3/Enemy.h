#pragma once
class Enemy
{
	int num = 0; 
	bool live = true;
public:
	void Proximity();
	void Shot();
	void Ecession();
	static void(Enemy::* funcTable[])();
	void Update();
	void Draw();
	bool GetLive() { return live; }
};

