#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>
#include <cstdlib>
#include "SceneManager.h"
using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//メモリリーク監視用(newで生成してるので)
	{
		SceneManager::GetInstance()->Run();
	}
	_CrtDumpMemoryLeaks();
	system("pause");//while(true)で回って入るけど念のため
	return 0;
}