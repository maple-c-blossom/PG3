#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <list>
#include <vector>

using namespace std;
vector<char> SetVectorString(const char* str)
{
	vector<char> string;
	for (int i = 0; str[i] != '\0'; i++)
	{
		string.push_back(str[i]);
	}
	return string;
}

void PrintListString(list<vector<char>> stringList)
{
	for (const auto itr : stringList)
	{
		for (const auto itr2 : itr)
		{
			printf_s("%c", itr2);
		}
		printf_s("\n");
	}
	printf("\n");
}


int main()
{
	list<vector<char>> station
	{
		SetVectorString("Tokyo"),
		SetVectorString("Kanda"),
		SetVectorString("Akihabara"),
		SetVectorString("Okachimachi"),
		SetVectorString("Ueno"),
		SetVectorString("Uguisudani"),
		SetVectorString("Nippori"),
		SetVectorString("Tabata"),
		SetVectorString("Komagome"),
		SetVectorString("Sugamo"),
		SetVectorString("Otsuka"),
		SetVectorString("Ikebukuro"),
		SetVectorString("Mejiro"),
		SetVectorString("Takadanobaba"),
		SetVectorString("shin-Okubo"),
		SetVectorString("shinjuku"),
		SetVectorString("Yoyogi"),
		SetVectorString("Harajuku"),
		SetVectorString("Shibuya"),
		SetVectorString("Ebisu"),
		SetVectorString("Meguro"),
		SetVectorString("Gotanda"),
		SetVectorString("Osaki"),
		SetVectorString("Shinagawa"),
		SetVectorString("Tamachi"),
		SetVectorString("Hamamatsucho"),
		SetVectorString("Shimbashi"),
		SetVectorString("Yurakucho"),
	};

	PrintListString(station);

	auto i = station.begin();
	while (true)
	{
		if (*i == SetVectorString("Tabata"))
		{
			i = station.insert(i, SetVectorString("Nishi-Nippori"));
			break;
		}
		i++;
	}
	PrintListString(station);

	while (true)
	{
		if (*i == SetVectorString("Tamachi"))
		{
			i = station.insert(i, SetVectorString("Takanawa-Gateway"));
			break;
		}
		i++;
	}
	PrintListString(station);

	return 0;
}