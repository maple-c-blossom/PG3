#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>
#include <cstdlib>
#include "SceneManager.h"
using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//���������[�N�Ď��p(new�Ő������Ă�̂�)
	{
		SceneManager::GetInstance()->Run();
	}
	_CrtDumpMemoryLeaks();
	system("pause");//while(true)�ŉ���ē��邯�ǔO�̂���
	return 0;
}