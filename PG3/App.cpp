#include "App.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

App* App::GetInstance()
{
	static App instance;
	return &instance;
}

void App::Run()
{
	Initialize();
	while (true)
	{
		int returnFlag = true;
		Update();
		Draw();
		cout << "���s�Ȃ�1���I���Ȃ�0����͂��Ă�������" << endl;
		cin >> returnFlag;
		std::system("cls");
		if (!returnFlag)
		{
			End();
			break;
		}
	}
}

void App::Initialize()
{
	picManager->InPut();
	taskManager->InPut();
}

void App::Update()
{
	int select = -1;
	cout << "�����őI�����Ă�������" << "\n" << "1:�S���Ҍn����" << "\n" << "2:�^�X�N�n����" << endl;
	cin >> select;
	if (select == 1)
	{
		cout << "�����őI�����Ă�������" << "\n" << "1:�S���Ғǉ�" << "\n" << "2:���O�ύX" << "\n" << "3:�N���X�ύX" << "\n" << "4:�S���ҍ폜"  << "\n" << "5:�S���ҎQ��" << endl;
		cin >> select;
		if (select == 1)
		{
			std::string name;
			std::string className;
			cout << "�S���Җ�����͂��Ă�������" << endl;
			cin >> name;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S���N���X������͂��Ă�������" << endl;
			cin >> className;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			int addId = picManager->AddPIC(name, className);
			cout << "�ǉ����܂����BId��" << addId << "�ł�" << endl;
		}
		else if (select == 2)
		{
			int id = -1;
			std::string name;
			cout << "id��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S���Җ�����͂��Ă�������" << endl;
			cin >> name;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			picManager->SetName(id, name);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 3)
		{
			int id = -1;
			std::string className;
			cout << "id��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S���N���X������͂��Ă�������" << endl;
			cin >> className;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			picManager->SetClass(id, className);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 4)
		{
			int id = -1;
			cout << "id��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			picManager->DeletePic(id);
			cout << "�폜���܂����B" << endl;
		}
		else if (select == 5)
		{
			int id = -1;
			cout << "id��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			Person* ptr = picManager->GetPicPtr(id);
			if (ptr)
			{
				cout << "ID: " << ptr->GetId() << endl;
				cout << "�S���Җ�: " << ptr->GetName() << endl;
				cout << "�S���N���X��: " << ptr->GetClass() << endl;
			}
		}
		else
		{
			cout << "�s���Ȓl�ł�" << endl;
		}

	}
	else if (select == 2)
	{
		cout << "�����őI�����Ă�������" << "\n" << "1:�^�X�N�ǉ�" << "\n" << "2:�X�e�[�^�X�ύX" << "\n" << "3:���e�ύX" << "\n" << "4:�D��x�ύX" << "\n" << "5:�S���ҕύX" << "\n" << "6:�����ύX" << "\n" << "7:�^�X�N�폜" << "\n" << "8:�^�X�N�\��" << endl;
		cin >> select;
		if (select == 1)
		{
			std::string name;
			std::string content;
			std::string priority;
			Date deadline;
			bool status;
			int picid;
			cout << "�^�X�N������͂��Ă�������" << endl;
			cin >> name;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "���e����͂��Ă�������" << endl;
			cin >> content;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�D��x����͂��Ă�������" << endl;
			cin >> priority;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "��������͂��Ă�������" << endl;
			cout << "������͂��Ă�������" << endl;
			cin >> deadline.month;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "������͂��Ă�������" << endl;
			cin >> deadline.day;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�X�e�[�^�X�󋵂�I�����Ă��������B0:������,1:����" << endl;
			cin >> status;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S����ID��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> picid;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			int addId = taskManager->AddTask(picid, name, content, priority, deadline, status);
			cout << "�ǉ����܂����BId��" << addId << "�ł�" << endl;
		}
		else if (select == 2)
		{
			int id = -1;
			bool status;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�X�e�[�^�X�󋵂�I�����Ă��������B0:������,1:����" << endl;
			cin >> status;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetStatus(id, status);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 3)
		{
			int id = -1;
			std::string content;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "���e����͂��Ă�������" << endl;
			cin >> content;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetContent(id, content);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 4)
		{
			int id = -1;
			std::string priority;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�D��x����͂��Ă�������" << endl;
			cin >> priority;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetPriority(id, priority);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 5)
		{
			int id = -1;
			int picid;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S����ID��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> picid;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetPic(id, picManager->GetPicPtr(picid));
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 6)
		{
			int id = -1;
			Date deadline;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "��������͂��Ă�������" << endl;
			cout << "������͂��Ă�������" << endl;
			cin >> deadline.month;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "������͂��Ă�������" << endl;
			cin >> deadline.day;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetDate(id, deadline);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 7)
		{
			int id = -1;
			
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->DeleteTask(id);
			cout << "�폜���܂����B" << endl;
		}
		else if (select == 8)
		{
			int id = -1;

			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			Task* ptr = taskManager->GetTask(id);
			if (ptr)
			{
				cout << "ID:" << " " << ptr->GetId() << endl;
				cout << "�^�X�N��:" << " " << ptr->GetName() << endl;
				cout << "���e:" << " " << ptr->GetContent() << endl;
				cout << "�D��x:" << " " << ptr->GetPriority() << endl;
				string status = ptr->GetStatus() ? "����" : "������";
				cout << "�i��:" << " " << status << endl;
				if (ptr->GetPic())
				{
					cout << "�S����ID:" << " " << ptr->GetPic()->GetId() << endl;
				}
				cout << "����:" << " " << ptr->GetDeadLine().month << "�� " << ptr->GetDeadLine().day<< "��" << endl;
			}
		}
		else
		{
			cout << "�s���Ȓl�ł�" << endl;
		}
	}
	else
	{
		cout << "�s���Ȓl�ł�" << endl;
	}
}

void App::Draw()
{


}

void App::End()
{
	picManager->OutPut();
	taskManager->OutPut();
}

void App::ChengeScene(int sceneNo)
{
	this->sceneNo = sceneNo;
}
