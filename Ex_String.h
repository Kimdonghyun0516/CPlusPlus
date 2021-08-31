#pragma once 

class MyString 
{
public:
	MyString(); // 기본 생성자
	MyString(const char* pszParam);     // 변환 생성자
	MyString(const MyString& pszParam); // 복사 생성자 

	~MyString();
	// 연산자 오버로딩
	// left = right 이런 연산자 표현을 함수로 바꾸면 13줄 처럼 된다.
	// left operator=(right);
	MyString& operator=(const MyString& right);

	// 정적멤버 변수(=클래스의 멤버변수)
	static int m_nCount;    // 현재까지 생성된 인스턴스의 갯수 관리용

private:
	char* m_pszData; // 동적메모리(4B) --> mallac/free
	int m_nLength;   // 문자열의 길이

public:
	int SetString(const char* pszParam);
	const char* GetString() const;
private:
	void Release();  // 동적 메모리 해제함수
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
// 주소록이 저장될 데이터 파일
//#define DATA_FILE_NAME "c:\\temp\\AddrBook.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
class UserData
{
public:
    string strName = "";         // 이름
    int nAge = 0;            // 나이
    int nGender = 0;         // 성별

    void PrintData()
    {
        cout << strName << ", ";
        cout << nAge << "세, ";
        cout << (nGender ? "여성" : "남성");
        cout << endl;
    }
};

//배열로 처리
#define      MAX_BOOKCOUNT   5
int         g_nCount = 0;

UserData   g_AddrBook[MAX_BOOKCOUNT];
int         kor[5];
///////////////////////////////////////////////////////////////////////
// 이름을 입력받아 배열에 추가하는 함수
void Add()
{
    cout << "Add()" << endl << endl;
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search()
{
    cout << "Search()" << endl << endl;
}

/////////////////////////////////////////////////////////////////////////
// 배열에 들어있는 모든 데이터를 화면에 출력하는 함수
void PrintAll()
{
    cout << "PrintAll()" << endl << endl;
}


/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
    cout << "Remove()" << endl << endl;
}
/////////////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 UI 함수
int PrintUI()
{
    int nInput = 0;

    cout << "===================================================\n";
    cout << "전화번호부(Array)\n";
    cout << "---------------------------------------------------\n";
    //cout << "[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제\t [0] 종료\n";
    cout << "[1] 추가\t [2] 검색\t [3] 전체보기\t [0] 종료\n";
    cout << "===================================================\n";

    // 사용자가 선택한 메뉴의 값을 반환한다.
    cin >> nInput;
    return nInput;
}

/////////////////////////////////////////////////////////////////////////
// 데이터 파일에서 노드들을 읽어와 배열을 완성하는 함수
int LoadList(char* pszFileName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////
// 배열 형태로 존재하는 정보를 파일에 저장하는 함수
int SaveList(char* pszFileName)
{
    return 0;
}

int main()
{
    int nMenu = 0;
    //LoadList(DATA_FILE_NAME);

    // 메인 이벤트 반복문
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
            cout << "지원하지 않는 메뉴입니다\n\n";
        }
    }

    // 종료 전에 파일로 저장하고 메모리를 해제한다.
    //SaveList(DATA_FILE_NAME);

    return 0;
}
#endif