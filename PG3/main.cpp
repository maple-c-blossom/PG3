#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>
#include <cstdlib>
#include "List.h"
using namespace std;

enum Status {
	Menu = 0,
	Draw = 1,
	Insert = 2,
	Change = 3,
	Delete = 4,
};
enum DrawStatus {
	AllDraw = 1,
	SelectDraw = 2
};
template <class T>
void MenuRun(MCB::List<T>& list, int& status)
{
	cout << "[—v‘f‚Ì‘€ì]" << endl;
	cout << "1.—v‘f‚Ì•\¦" << endl;
	cout << "2.—v‘f‚Ì‘}“ü" << endl;
	if (!list.Empty())
	{
		cout << "3.—v‘f‚Ì•ÒW" << endl;
		cout << "4.—v‘f‚Ìíœ" << endl;
	}
	cout << "-----------------------------------------" << endl;
	cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢B" << endl;
	cin >> status;
};
template <class T>
void DrawRun(MCB::List<T>& list, int& status)
{
	int selectStatus;
	int drawStatus = Menu;
	int select = 2;
	cout << "[—v‘f‚Ì•\¦]" << endl;
	cout << "1.—v‘f‚Ìˆê——•\¦" << endl;
	cout << "2.—v‘f‚Ì‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦" << endl;
	//cout << "ã‹LˆÈŠO.—v‘f‚Ì‘€ì‚Ö–ß‚é" << endl;
	cin >> drawStatus;
	switch (drawStatus)
	{
	case AllDraw:
		cout << "[—v‘f‚Ìˆê——•\¦]" << endl;
		cout << "—v‘fˆê——:{" << endl;
		list.AllPrint();
		cout << "}\n" << endl;

		cout << "—v‘f”:" << list.Size() << endl;
		cout << "\n\n-----------------------------------" << endl;
		cout << "1.—v‘f‚Ì•\¦‚É–ß‚é" << endl;
		cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << endl;
		//cout << "ã‹LˆÈŠO.—v‘f‚Ì‘€ì‚Ö–ß‚é" << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			status = Draw;
			break;
		case 2:
			status = Menu;
			break;
		default:
			status = Menu;
			break;
		}
		break;
	case SelectDraw:
		cout << "[‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦]" << endl;

		cin >> selectStatus;
		cout << selectStatus << ":" << list.GetNodeAddress(selectStatus)->value << endl;
		cout << "-----------------------------------" << endl;
		cout << "1.—v‘f‚Ì•\¦‚É–ß‚é" << endl;
		cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << endl;
		cout << "ã‹LˆÈŠO.—v‘f‚Ì‘€ì‚Ö–ß‚é" << endl;
		select = 2;
		cin >> select;
		switch (select)
		{
		case 1:
			status = Draw;
			break;
		case 2:
			status = Menu;
			break;
		default:
			status = Menu;
			break;
		}
		break;
	default:
		break;
	}
}

template <class T>
//selectPositoin - 1‚ÍAddŠÖ”‚Í‘I‘ğ‚³‚ê‚½—v‘f‚ÌŒã‚ë‚É—v‘f‚ğ‘}“ü‚·‚é‚½‚ßA‚»‚Ì‚Ü‚Üˆø”‚É—^‚¦‚é‚Æ1‚Â•\¦‚Æ‚¸‚ê‚ª”­¶‚·‚é‚½‚ßA
//‚»‚Ì•â³‚Æ‚µ‚Ä‘}“ü
void InsertRun(MCB::List<T>& list, int& status)
{
	cout << "[List‚Ì—v‘f‚Ì‘}“ü]" << endl;
	int selectPosition = -114514;
	cout << "—v‘f‚ğ’Ç‰Á‚·‚éêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	cin >> selectPosition;
	cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	T value;
	cin >> value;
	if (selectPosition - 1 < 0 || selectPosition - 1 >= list.Size())
	{
		if (selectPosition - 1 < 0)
		{
			list.PushFront(value);
			cout << "—v‘f\"" << value << "\"‚ª" << 0 << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½";
		}
		else
		{
			list.PushBack(value);
			cout << "—v‘f\"" << value << "\"‚ª" << list.Size() - 1 << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½\n";
		}
	}
	else
	{
		list.Add(value, list.GetNodeAddress(selectPosition - 1));
		cout << "—v‘f" << value << "‚ª" << selectPosition << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½\n";
	}
	status = Menu;
}

template <class T>
void ChangeRun(MCB::List<T>& list, int& status)
{
	cout << "[—v‘f‚Ì•ÒW]" << "\n" << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	int selectPosition = -114514;
	T value;
	cin >> selectPosition;
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n" << endl;

	}
	else
	{
		cout << selectPosition << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cin >> value;
		list.GetNodeAddress(selectPosition)->value = value;
		cout << selectPosition << "”Ô–Ú‚Ì—v‘f‚Ì’l‚ª\"" << value << "\"‚É•ÏX‚³‚ê‚Ü‚µ‚½" << endl;
	}
	status = Menu;
}
template <class T>
void DeleteRun(MCB::List<T>& list, int& status)
{
	cout << "[—v‘f‚Ìíœ]" << "\n" << "íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	int selectPosition = -114514;
	T value;
	cin >> selectPosition;
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n" << endl;

	}
	else
	{
		value = list.GetNodeAddress(selectPosition)->value;
		list.Delete(list.GetNodeAddress(selectPosition));
		cout << selectPosition << "”Ô–Ú‚Ì—v‘f\"" << value << "\"‚ğíœ‚µ‚Ü‚µ‚½\n" << endl;
	}
	status = Menu;
}
int main()
{
	ios::sync_with_stdio(false);

	MCB::List<string> list;
	int status = Menu;
	bool breakFlag = false;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		while (true)
		{

			switch (status)
			{
			case Menu:
				MenuRun(list, status);
				break;
			case Draw:
				DrawRun(list, status);
				break;
			case Insert:
				InsertRun(list, status);
				break;
			case Change:
				ChangeRun(list, status);
				break;
			case Delete:
				DeleteRun(list, status);
				status = Menu;
				break;
			default:
				breakFlag = true;
				break;
			}
			if (breakFlag)
			{
				break;
			}
		}
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}