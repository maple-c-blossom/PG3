#pragma once
class Enemy
{
	int hp = 3;
public:
	static bool live;
	void Update(int actionSelect);
	void Draw();
};

