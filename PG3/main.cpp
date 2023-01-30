#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>
#include <cstdlib>
#include "SceneManager.h"
using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//ƒƒ‚ƒŠƒŠ[ƒNŠÄŽ‹—p(new‚Å¶¬‚µ‚Ä‚é‚Ì‚Å)
	{
		SceneManager::GetInstance()->Run();
	}
	_CrtDumpMemoryLeaks();
	system("pause");//while(true)‚Å‰ñ‚Á‚Ä“ü‚é‚¯‚Ç”O‚Ì‚½‚ß
	return 0;
}