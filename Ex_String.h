#pragma once 

class MyString 
{
public:
	MyString(); // �⺻ ������
	MyString(const char* pszParam);     // ��ȯ ������
	MyString(const MyString& pszParam); // ���� ������ 

	~MyString();
	// ������ �����ε�
	// left = right �̷� ������ ǥ���� �Լ��� �ٲٸ� 13�� ó�� �ȴ�.
	// left operator=(right);
	MyString& operator=(const MyString& right);

	// ������� ����(=Ŭ������ �������)
	static int m_nCount;    // ������� ������ �ν��Ͻ��� ���� ������

private:
	char* m_pszData; // �����޸�(4B) --> mallac/free
	int m_nLength;   // ���ڿ��� ����

public:
	int SetString(const char* pszParam);
	const char* GetString() const;
private:
	void Release();  // ���� �޸� �����Լ�
};

///////////////

class FunnyString : public MyString
{
public:
	int SetString(const char* pszParam);
};


#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>

/////////////////////////////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
//#define DATA_FILE_NAME "c:\\temp\\AddrBook.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
class UserData
{
public:
    string strName = "";         // �̸�
    int nAge = 0;            // ����
    int nGender = 0;         // ����

    void PrintData()
    {
        cout << strName << ", ";
        cout << nAge << "��, ";
        cout << (nGender ? "����" : "����");
        cout << endl;
    }
};

//�迭�� ó��
#define      MAX_BOOKCOUNT   5
int         g_nCount = 0;

UserData   g_AddrBook[MAX_BOOKCOUNT];
int         kor[5];
///////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �迭�� �߰��ϴ� �Լ�
void Add()
{
    cout << "Add()" << endl << endl;
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
    cout << "Search()" << endl << endl;
}

/////////////////////////////////////////////////////////////////////////
// �迭�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
    cout << "PrintAll()" << endl << endl;
}


/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
    cout << "Remove()" << endl << endl;
}
/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int PrintUI()
{
    int nInput = 0;

    cout << "===================================================\n";
    cout << "��ȭ��ȣ��(Array)\n";
    cout << "---------------------------------------------------\n";
    //cout << "[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n";
    cout << "[1] �߰�\t [2] �˻�\t [3] ��ü����\t [0] ����\n";
    cout << "===================================================\n";

    // ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
    cin >> nInput;
    return nInput;
}

/////////////////////////////////////////////////////////////////////////
// ������ ���Ͽ��� ������ �о�� �迭�� �ϼ��ϴ� �Լ�
int LoadList(char* pszFileName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////
// �迭 ���·� �����ϴ� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(char* pszFileName)
{
    return 0;
}

int main()
{
    int nMenu = 0;
    //LoadList(DATA_FILE_NAME);

    // ���� �̺�Ʈ �ݺ���
    while ((nMenu = PrintUI()) != 0) {
        switch (nMenu) {
        case 1:        // Add
            Add();
            break;

        case 2:        // Search
            Search();
            break;

        case 3:       // Print all
            PrintAll();
            break;

            //case 4:        // Remove
            //   Remove();
            //   break;

        default:
            cout << "�������� �ʴ� �޴��Դϴ�\n\n";
        }
    }

    // ���� ���� ���Ϸ� �����ϰ� �޸𸮸� �����Ѵ�.
    //SaveList(DATA_FILE_NAME);

    return 0;
}
#endif