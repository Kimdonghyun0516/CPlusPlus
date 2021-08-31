#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <fstream>  // ifstream, ofstream

/////////////////////////////////////////////////////////////////////////
// 주소록이 저장될 데이터 파일
#define DATA_FILE_NAME "c:\\temp\\AddrBook.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
class UserData
{
public:
    string strName = "";     // 이름
    int nAge = 0;            // 나이
    int nGender = 0;         // 성별

    //for 링크드 리스트()
    UserData* pNext = NULL;  // 다음 요소를 가르키는 링크 포인터
    UserData* pPrev = NULL;  // 다음 요소를 가르키는 링크 포인터 

    void PrintData()
    {
        cout << strName << ", ";
        cout << nAge << "세, ";
        cout << (nGender ? "여성" : "남성");
        cout << endl;
    }
};

//배열로 처리
#define     MAX_BOOKCOUNT   5
int         g_nCount = 0;
UserData    g_AddrBook[MAX_BOOKCOUNT]; // 배열은 정적메모리

//링크드 리스트로 처리를 하려면 
UserData* g_HeadAddrBook;


///////////////////////////////////////////////////////////////////////
// 이름을 입력받아 배열에 추가하는 함수
void Add()
{
    if (g_nCount + 1 > MAX_BOOKCOUNT)
    {
        cout << " 입력불가로 인한 용량 초과" << endl;
        return;
    }

    cout << "다음을 입력하세요" << endl << endl;
    cout << "이름 : ";
    cin >> g_AddrBook[g_nCount].strName;
    cout << "나이 : ";
    cin >> g_AddrBook[g_nCount].nAge;
    cout << "성별 (0 남자 /1 여자) : ";
    cin >> g_AddrBook[g_nCount].nGender;
    g_nCount++;
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search()
{
    
}

/////////////////////////////////////////////////////////////////////////
// 배열에 들어있는 모든 데이터를 화면에 출력하는 함수
void PrintAll()
{
    if (g_nCount == 0)
    {
        cout << "출력할 데이터가 없습니다" << endl;
        return;
    }

    for (int i = 0; i < g_nCount; i++)
    {
        g_AddrBook[i].PrintData();
    }
}

/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
    //string strName;

    //cout << "삭제할 이름을 입력하세요 : ";
    //cin >> strName;

    //int nHit = 0;
    //for (int i = 0; i < g_nCount; i++) // 0번 부터 크기만큼 검사한당
    //{
    //    if (g_AddrBook[i].strName == strName)
    //    {
    //        // 삭제
    //        // 이후 데이터를 하나씩 위로 올린다.
    //        for (int j=i; j < g_nCount; j++)
    //        {
    //            g_AddrBook[j].strName = g_AddrBook[j + 1].strName;
    //            g_AddrBook[j].nAge    = g_AddrBook[j + 1].nAge;
    //            g_AddrBook[j].nGender = g_AddrBook[j + 1].nGender;
    //        }
    //        nHit++;
    //        g_nCount--;
    //    }
    //}
    //if (nHit == 0)
    //{
    //    cout << "삭제할 데이터를 찾을 수 없습니다." << endl;
    //}
    
}
/////////////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 UI 함수
int PrintUI()
{
    int nInput = 0;

    cout << "===================================================\n";
    cout << "전화번호부(Array)\n";
    cout << "---------------------------------------------------\n";
    cout << "[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제\t [0] 종료\n";
    //cout << "[1] 추가\t [2] 검색\t [3] 전체보기\t [0] 종료\n";
    cout << "===================================================\n";

    // 사용자가 선택한 메뉴의 값을 반환한다.
    cin >> nInput;
    return nInput;
}

/////////////////////////////////////////////////////////////////////////
// 데이터 파일에서 노드들을 읽어와 배열을 완성하는 함수
int LoadList(string strFileName)
{
    ifstream f;
    f.open(strFileName, std::ios::binary);

    if (f.is_open())
    {
        // 헤더정보
        f >> g_nCount;
        // 데이터 정보
        for (int i = 0; i < g_nCount; i++)
        {
            f.read((char*)(g_AddrBook + i), sizeof(UserData));
        }
        f.close();
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////
// 배열 형태로 존재하는 정보를 파일에 저장하는 함수
int SaveList(string strFileName)
{
    ofstream f;
    f.open(strFileName, std::ios::binary);

    if (f.is_open())
    {
        // 헤더정보
        f << g_nCount;
        // 데이터 정보
        for (int i=0; i<g_nCount; i++)
        {
            f.write((const char*)(g_AddrBook+i), sizeof(UserData));
        }
        f.close();
    }
    return 0;
}

int main()
{
    int nMenu = 0;
    LoadList(DATA_FILE_NAME);

    // 메인 이벤트 반복문
    while ((nMenu = PrintUI()) != 0) {
        switch (nMenu) {
        case 1:        
            Add();
            break;

        case 2:       
            Search();
            break;

        case 3:       
            PrintAll();
            break;

        case 4:       
            Remove();
            break;

        default:
            cout << "지원하지 않는 메뉴입니다\n\n";
        }
    }

    // 종료 전에 파일로 저장하고 메모리를 해제한다.
    SaveList(DATA_FILE_NAME);

    return 0;
}
#endif