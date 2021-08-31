#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <fstream>

/////////////////////////////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME "c:\\temp\\AddrBookSTL.dat"

/////////////////////////////////////////////////////////////////////////
class UserData
{
public:
	string strName = "";		// �̸�
	int nAge = 0;				// ����
	int nGender = 0;			// ����

	//for ��ũ�� ����Ʈ
	//UserData* pNext = NULL;	//���� ��Ҹ� ����Ű�� ��ũ
	//UserData* pPrev = NULL;	//���� ��Ҹ� ����Ű�� ��ũ
	UserData() {}
	UserData(string strName, int nAge, int nGender) 
	{
		this->strName = strName;
		this->nAge = nAge;
		this->nGender = nGender;
	}
	void PrintData()
	{
		cout << strName << ", ";
		cout << nAge << "��, ";
		cout << (nGender ? "����" : "����");
		cout << endl;
	}

	// a == b
	// ��> a.operator==(b)
	// ���� ���ϱ� �ϰ� �ʹ�
	//    ��> a.operator+(b)
	int operator==(const UserData& param)
	{
		if (this->strName == param.strName)
		//&& this->strName == param.nAge
		//&& this->strName == param.nGender)
			return 1;
		else
			return 0;
	}
};

//�迭�� ó��
//#define		MAX_BOOKCOUNT	50
//int			g_nCount = 0;
//UserData	g_AddrBook[MAX_BOOKCOUNT];//�����޸�

//��ũ�� ����Ʈ�� ó��
//UserData* g_HeapAddrBook;//�����޸�
#include <vector>
#include <algorithm>
std::vector<UserData> myFriend;

///////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �迭�� �߰��ϴ� �Լ�
void Add()
{
	string strName = "";
	int nAge = 0;
	int nGender = 0;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> strName;

	cout << "���̸� �Է��ϼ��� : ";
	cin >> nAge;

	cout << "������ �Է��ϼ���(����:0, ����:1) : ";
	cin >> nGender;

	// ������ �����̳ʿ� ������ �߰��Ѵ�.
	myFriend.push_back(UserData(strName, nAge, nGender));
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
	string strName;
	cout << "�˻��� �̸��� �Է��ϼ��� : ";
	cin >> strName;

	/// ////////////////////////////////
	auto p = std::find(begin(myFriend), end(myFriend), UserData(strName, 0, 0));
	if (p == end(myFriend))
		cout << "�����͸� ã�� �� �����ϴ�" << endl;
	else
		p->PrintData();

	/*
	//////////////////////////////////////
	// �����̳� + �ݺ���
	auto p = begin(myFriend);
	auto p2 = end(myFriend);

	int nHit = 0;
	while (p != p2)
	{
		if (p->strName == strName)
		{
			p->PrintData();
			nHit = 1;
			break;
		}
		p++;
	}
	if (nHit == 0)
	{
		cout << "�����͸� ã�� �� �����ϴ�" << endl;
	}
	*/
}

/////////////////////////////////////////////////////////////////////////
// �迭�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
	if (myFriend.size() == 0)
	{
		cout << "�����Ͱ� �����ϴ�" << endl;
		return;
	}
	/* 1.[] �����ڸ� �̿�  // []����Ʈ������ ����ȣ�� ���Ұ� ** ����Բ����� ������� for���� ����ϴ� ���� ��õ!!!!!
	for (int i = 0; i < myFriend.size(); i++)
	{
		myFriend[i].PrintData();
	}
	*/
	/*2. ���� ��� for���� �̿� 
	for (auto& item : myFriend)
	{
		item.PrintData();
	}
	*/

	//3. �ݺ��� ���
	//vector<UserData>::iterator p; // -> ����ǥ��
	auto p = begin(myFriend);
	auto p2 = end(myFriend);
	while (p != p2)
	{
		p->PrintData();
		p++;
	}

}
/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
	string strName;
	cout << "������ �̸��� �Է��ϼ��� : ";
	cin >> strName;

	/////////////////////////////////////
	auto p = std::find(begin(myFriend), end(myFriend), UserData(strName, 0, 0));
	if (p == end(myFriend))
		cout << "�����͸� ã�� �� �����ϴ�" << endl;
	else
		myFriend.erase(p);

	//int nHit = 0;
	//for (int i = 0; i < g_nCount; i++)
	//{
	//	if (g_AddrBook[i].strName == strName)
	//	{
	//		//����!!!
	//		//���� �����͸� �ϳ��� ���� �ø���
	//		for (int j = i; j < g_nCount; j++)
	//		{
	//			g_AddrBook[j].strName = g_AddrBook[j + 1].strName;
	//			g_AddrBook[j].nAge = g_AddrBook[j + 1].nAge;
	//			g_AddrBook[j].nGender = g_AddrBook[j + 1].nGender;
	//		}
	//		nHit++;
	//		g_nCount--;
	//	}
	//}
	//if (nHit == 0)
	//{
	//	cout << "������ �����͸� ã�� �� �����ϴ�" << endl;
	//}
}

/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int PrintUI()
{
	int nInput = 0;

	cout << "===================================================\n";
	cout << "��ȭ��ȣ��(Array)\n";
	cout << "---------------------------------------------------\n";
	cout << "[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n";
	//cout << "[1] �߰�\t [2] �˻�\t [3] ��ü����\t [0] ����\n";
	cout << "===================================================\n";

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	cin >> nInput;
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
// ������ ���Ͽ��� ������ �о�� �迭�� �ϼ��ϴ� �Լ�
int LoadList(string strFileName)
{
	ifstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//��� ����
		int count = 0;
		f >> count;
		//������ ����
		for(int i=0; i < count; i++)
		{
			// ���Ͽ��� �о�� ����(=����)�� ���� --> �����޸� ������ �Ѵ�!!!!!!!!!!!!!!!!!
			UserData* buff = new UserData;
			// �� ���۷� ������ ������ �о�´�
			f.read((char*)buff, sizeof(UserData));
			// �����̳ʿ� �ִ´�.
			myFriend.push_back(*buff);
		}
		f.close();
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// �迭 ���·� �����ϴ� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(string strFileName)
{
	ofstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//��� ����
		f << myFriend.size();
		//������ ����
		for (auto& item : myFriend)
		{
			f.write((const char*)&item, sizeof(UserData));
		}
		f.close();
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add
			Add();
			break;

		case 2:		  // Search
			Search();
			break;

		case 3:		 // Print all
			PrintAll();
			break;

		case 4:		  // Remove
			Remove();
			break;

		default:
			cout << "�������� �ʴ� �޴��Դϴ�\n\n";
		}
	}
	// ���� ���� ���Ϸ� �����ϰ� �޸𸮸� �����Ѵ�.
	SaveList(DATA_FILE_NAME);
	return 0;
}
#endif