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
	cout << "[要素の操作]" << endl;
	cout << "1.要素の表示" << endl;
	cout << "2.要素の挿入" << endl;
	if (!list.Empty())
	{
		cout << "3.要素の編集" << endl;
		cout << "4.要素の削除" << endl;
	}
	cout << "-----------------------------------------" << endl;
	cout << "操作を選択してください。対象外の値の場合終了します。" << endl;
	cin >> status;
};
template <class T>
void DrawRun(MCB::List<T>& list, int& status)
{
	int selectStatus;
	int drawStatus = Menu;
	int select = 2;
	cout << "[要素の表示]" << endl;
	cout << "1.要素の一覧表示" << endl;
	cout << "2.要素の順番を指定して要素を表示" << endl;
	cout << "上記以外.要素の操作へ戻る" << endl;
	cin >> drawStatus;
	switch (drawStatus)
	{
	case AllDraw:
		cout << "[要素の一覧表示]" << endl;
		cout << "要素一覧:{" << endl;
		list.AllPrint();
		cout << "}" << endl;

		cout << "要素数:" << list.Size() << endl;
		cout << "-----------------------------------" << endl;
		cout << "1.要素の表示に戻る" << endl;
		cout << "2.要素の操作に戻る" << endl;
		cout << "上記以外.要素の操作へ戻る" << endl;

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
		cout << "[順番を指定して要素を表示]" << endl;

		cin >> selectStatus;
		cout << selectStatus << ":" << list.GetNodeAddress(selectStatus)->value << endl;
		cout << "-----------------------------------" << endl;
		cout << "1.要素の表示に戻る" << endl;
		cout << "2.要素の操作に戻る" << endl;
		cout << "上記以外.要素の操作へ戻る" << endl;
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
//selectPositoin - 1はAdd関数は選択された要素の後ろに要素を挿入するため、そのまま引数に与えると1つ表示とずれが発生するため、
//その補正として挿入
void InsertRun(MCB::List<T>& list, int& status)
{
	cout << "[Listの要素の挿入]" << endl;
	int selectPosition = -114514;
	cout << "要素を追加する場所を指定してください" << endl;
	cin >> selectPosition;
	cout << "追加する要素の値を入力してください" << endl;
	int value = 0;
	cin >> value;
	if (selectPosition - 1 < 0 || selectPosition - 1 >= list.Size())
	{
		if (selectPosition - 1 < 0)
		{
			list.PushFront(value);
			cout << "要素" << value << "が" << 0 << "番目に挿入されました";
		}
		else
		{
			list.PushBack(value);
			cout << "要素" << value << "が" << list.Size() - 1 << "番目に挿入されました";
		}
	}
	else
	{
		list.Add(value, list.GetNodeAddress(selectPosition - 1));
		cout << "要素" << value << "が" << selectPosition << "番目に挿入されました";
	}
	status = Menu;
}

template <class T>
void ChangeRun(MCB::List<T>& list, int& status)
{
	cout << "[要素の編集]" << "\n" << "編集したい要素の番号を指定してください" << endl;
	int selectPosition = -114514;
	int value = 0;
	cin >> selectPosition;
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "番目の要素が見つかりませんでした" << endl;

	}
	else
	{
		cout << selectPosition << "番目の要素の変更する値を入力してください" << endl;
		cin >> value;
		list.GetNodeAddress(selectPosition)->value = value;
		cout << selectPosition << "番目の要素の値が" << value << "に変更されました" << endl;
	}
	status = Menu;
}
template <class T>
void DeleteRun(MCB::List<T>& list, int& status)
{
	cout << "[要素の削除]" << "\n" << "削除したい要素の番号を指定してください" << endl;
	int selectPosition = -114514;
	int value = 0;
	cin >> selectPosition;
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "番目の要素が見つかりませんでした" << endl;

	}
	else
	{
		value = list.GetNodeAddress(selectPosition)->value;
		list.Delete(list.GetNodeAddress(selectPosition));
		cout << selectPosition << "番目の要素の値が" << value << "を削除しました" << endl;
	}
	status = Menu;
}
int main()
{


	MCB::List<int> list;
	int status = Menu;
	bool breakFlag = false;
	int selectPosition = -114514;
	int value;
	int select = 2;
	int selectStatus;
	int drawStatus = Menu;
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