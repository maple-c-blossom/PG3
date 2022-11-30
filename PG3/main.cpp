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
	cout << "[�v�f�̑���]" << endl;
	cout << "1.�v�f�̕\��" << endl;
	cout << "2.�v�f�̑}��" << endl;
	if (!list.Empty())
	{
		cout << "3.�v�f�̕ҏW" << endl;
		cout << "4.�v�f�̍폜" << endl;
	}
	cout << "-----------------------------------------" << endl;
	cout << "�����I�����Ă��������B" << endl;
	cin >> status;
};
template <class T>
void DrawRun(MCB::List<T>& list, int& status)
{
	int selectStatus;
	int drawStatus = Menu;
	int select = 2;
	cout << "[�v�f�̕\��]" << endl;
	cout << "1.�v�f�̈ꗗ�\��" << endl;
	cout << "2.�v�f�̏��Ԃ��w�肵�ėv�f��\��" << endl;
	//cout << "��L�ȊO.�v�f�̑���֖߂�" << endl;
	cin >> drawStatus;
	switch (drawStatus)
	{
	case AllDraw:
		cout << "[�v�f�̈ꗗ�\��]" << endl;
		cout << "�v�f�ꗗ:{" << endl;
		list.AllPrint();
		cout << "}\n" << endl;

		cout << "�v�f��:" << list.Size() << endl;
		cout << "\n\n-----------------------------------" << endl;
		cout << "1.�v�f�̕\���ɖ߂�" << endl;
		cout << "2.�v�f�̑���ɖ߂�" << endl;
		//cout << "��L�ȊO.�v�f�̑���֖߂�" << endl;

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
		cout << "[���Ԃ��w�肵�ėv�f��\��]" << endl;

		cin >> selectStatus;
		cout << selectStatus << ":" << list.GetNodeAddress(selectStatus)->value << endl;
		cout << "-----------------------------------" << endl;
		cout << "1.�v�f�̕\���ɖ߂�" << endl;
		cout << "2.�v�f�̑���ɖ߂�" << endl;
		cout << "��L�ȊO.�v�f�̑���֖߂�" << endl;
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
//selectPositoin - 1��Add�֐��͑I�����ꂽ�v�f�̌��ɗv�f��}�����邽�߁A���̂܂܈����ɗ^�����1�\���Ƃ��ꂪ�������邽�߁A
//���̕␳�Ƃ��đ}��
void InsertRun(MCB::List<T>& list, int& status)
{
	cout << "[List�̗v�f�̑}��]" << endl;
	int selectPosition = -114514;
	cout << "�v�f��ǉ�����ꏊ���w�肵�Ă�������" << endl;
	cin >> selectPosition;
	cout << "�ǉ�����v�f�̒l����͂��Ă�������" << endl;
	T value;
	cin >> value;
	if (selectPosition - 1 < 0 || selectPosition - 1 >= list.Size())
	{
		if (selectPosition - 1 < 0)
		{
			list.PushFront(value);
			cout << "�v�f\"" << value << "\"��" << 0 << "�Ԗڂɑ}������܂���";
		}
		else
		{
			list.PushBack(value);
			cout << "�v�f\"" << value << "\"��" << list.Size() - 1 << "�Ԗڂɑ}������܂���\n";
		}
	}
	else
	{
		list.Add(value, list.GetNodeAddress(selectPosition - 1));
		cout << "�v�f" << value << "��" << selectPosition << "�Ԗڂɑ}������܂���\n";
	}
	status = Menu;
}

template <class T>
void ChangeRun(MCB::List<T>& list, int& status)
{
	cout << "[�v�f�̕ҏW]" << "\n" << "�ҏW�������v�f�̔ԍ����w�肵�Ă�������" << endl;
	int selectPosition = -114514;
	T value;
	cin >> selectPosition;
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "�Ԗڂ̗v�f��������܂���ł���\n" << endl;

	}
	else
	{
		cout << selectPosition << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������" << endl;
		cin >> value;
		list.GetNodeAddress(selectPosition)->value = value;
		cout << selectPosition << "�Ԗڂ̗v�f�̒l��\"" << value << "\"�ɕύX����܂���" << endl;
	}
	status = Menu;
}
template <class T>
void DeleteRun(MCB::List<T>& list, int& status)
{
	cout << "[�v�f�̍폜]" << "\n" << "�폜�������v�f�̔ԍ����w�肵�Ă�������" << endl;
	int selectPosition = -114514;
	T value;
	cin >> selectPosition;
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "�Ԗڂ̗v�f��������܂���ł���\n" << endl;

	}
	else
	{
		value = list.GetNodeAddress(selectPosition)->value;
		list.Delete(list.GetNodeAddress(selectPosition));
		cout << selectPosition << "�Ԗڂ̗v�f\"" << value << "\"���폜���܂���\n" << endl;
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