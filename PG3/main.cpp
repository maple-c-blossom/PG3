#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>
#include <cstdlib>
#include "List.h"
using namespace std;

enum Status {
	Menu = 0,//メニュー画面
	Draw = 1,//要素表示画面
	Insert = 2,//要素挿入画面
	Change = 3,//要素編集画面
	Delete = 4,//要素削除画面
};
enum DrawStatus {
	AllDraw = 1,//一覧表示
	SelectDraw = 2//選択表示
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
	cout << "操作を選択してください。" << endl;
	cin >> status;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
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
	cout << "9.要素の操作に戻る" << endl;
	//cout << "上記以外.要素の操作へ戻る" << endl;
	cin >> drawStatus;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	switch (drawStatus)
	{
	case AllDraw://一覧表示
		cout << "[要素の一覧表示]" << endl;
		cout << "要素一覧:{" << endl;
		list.AllPrint();
		cout << "}\n" << endl;

		cout << "要素数:" << list.Size() << endl;
		cout << "\n\n-----------------------------------" << endl;
		cout << "1.要素の表示に戻る" << endl;
		cout << "2.要素の操作に戻る" << endl;
		//cout << "上記以外.要素の操作へ戻る" << endl;

		cin >> select;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore(1024, '\n');
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
	case SelectDraw://要素選択表示
		cout << "[順番を指定して要素を表示]" << endl;

		cin >> selectStatus;
		if (cin.fail())
		{
			cin.clear();
		}
		cout << selectStatus << ":" << list.GetNodeAddress(selectStatus)->value << endl;
		cout << "-----------------------------------" << endl;
		cout << "1.要素の表示に戻る" << endl;
		cout << "2.要素の操作に戻る" << endl;
		//cout << "上記以外.要素の操作へ戻る" << endl;
		select = 2;
		cin >> select;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore(1024, '\n');
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
	string getSelect;
	cout << "要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください" << endl;
	getline(cin,getSelect);
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	if (getSelect == "\0")
	{
		cout << endl;
		selectPosition = list.Size() + 10;
	}
	else
	{

		selectPosition = std::stoi(getSelect);
	}
	cout << "追加する要素の値を入力してください" << endl;
	T value;
	cin >> value;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	if (selectPosition - 1 < 0 || selectPosition - 1 >= list.Size())
	{
		if (selectPosition - 1 < 0)
		{
			list.PushFront(value);
			cout << "要素\"" << value << "\"が" << 0 << "番目に挿入されました";
		}
		else
		{
			list.PushBack(value);
			cout << "要素\"" << value << "\"が" << list.Size() - 1 << "番目に挿入されました\n";
		}
	}
	else
	{
		list.Add(value, list.GetNodeAddress(selectPosition - 1));
		cout << "要素" << value << "が" << selectPosition << "番目に挿入されました\n";
	}
	status = Menu;
}

template <class T>
void ChangeRun(MCB::List<T>& list, int& status)
{
	cout << "[要素の編集]" << "\n" << "編集したい要素の番号を指定してください" << endl;
	int selectPosition = -114514;
	T value;
	cin >> selectPosition;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "番目の要素が見つかりませんでした\n" << endl;

	}
	else
	{
		cout << selectPosition << "番目の要素の変更する値を入力してください" << endl;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore(1024, '\n');
		list.GetNodeAddress(selectPosition)->value = value;
		cout << selectPosition << "番目の要素の値が\"" << value << "\"に変更されました" << endl;
	}
	status = Menu;
}
template <class T>
void DeleteRun(MCB::List<T>& list, int& status)
{
	cout << "[要素の削除]" << "\n" << "削除したい要素の番号を指定してください" << endl;
	int selectPosition = -114514;
	T value;
	cin >> selectPosition;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	if (selectPosition < 0 || selectPosition >= list.Size())
	{
		cout << selectPosition << "番目の要素が見つかりませんでした\n" << endl;

	}
	else
	{
		value = list.GetNodeAddress(selectPosition)->value;
		list.Delete(list.GetNodeAddress(selectPosition));
		cout << selectPosition << "番目の要素\"" << value << "\"を削除しました\n" << endl;
	}
	status = Menu;
}
int main()
{
	ios::sync_with_stdio(false);//cinは速度面に難があるらしいので、改善用関数らしい

	MCB::List<string> list;
	int status = Menu;
	bool breakFlag = false;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//メモリリーク監視用(newで生成してるので)
	{
		while (true)
		{

			switch (status)
			{
			case Menu:
				MenuRun(list, status);//初期画面(メニュー画面)
				break;
			case Draw:
				DrawRun(list, status);//要素表示画面
				break;
			case Insert:
				InsertRun(list, status);//挿入画面
				break;
			case Change:
				ChangeRun(list, status);//要素編集画面
				break;
			case Delete:
				DeleteRun(list, status);//要素削除画面
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
	system("pause");//while(true)で回って入るけど念のため
	return 0;
}