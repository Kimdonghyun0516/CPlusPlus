//#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h> 
#include <iostream> 

using namespace std;


int main()
{
	// 클래스 정의(데이터타입)
	class CTest
	{
	public:
		CTest()
		{
			cout << "CTest::CTest()" << endl;
		}

		~CTest()
		{
			cout << "~CTest::CTest()" << endl;
		}
	};

	// 생성자와 소멸자
	if (0)
	{
		//1. 객체생성
		//cout << "-- 시작" << endl;
		//CTest a;// 생성자
		//cout << "-- 끝" << endl;

		//2. 객체의 동적생성
		cout << "-- 동적 시작" << endl;
		CTest* p = new CTest;
		//...
		delete p;
		cout << "-- 동적 끝" << endl;
	}
	//디폴트 생성자
	if (0)
	{
		class CTest
		{
		public:
			CTest(void) { m_nData = 20; }
			//int m_nData = 10;//C++11컴파일러 이후 가능
			int m_nData;
		};
		CTest a;
		cout << a.m_nData << endl;
	}

	// 생성자와 초기화 목록
	if (0)
	{
		class CTest 
		{
			int m_nData; //기본 접근 지시자는 private임

		public :
			CTest(void) : m_nData(20)//초기화 목록
			{
				//m_nData = 20;
				cout << "CTest()" << endl;
			}
			CTest(int nParam) : m_nData(nParam) // 초기화 목록
			{
				//m_nData = nParam;
				cout << "CTest(int nParam)" << endl;
			}
			~CTest()
			{
				cout << "~CTest()" << endl;
			}
		};

		cout << "main 시작" << endl;
		CTest a;
		CTest b(100);
		cout << "main 끝" << endl;
	}

	// 생성자 오버로딩
	// Getter/Setter 함수
	if (1)
	{
		class CTest
		{
		public:
			CTest(void)			: m_nData(-1)   { cout << "0" << endl; };
			CTest(int a)		: m_nData(a)    { cout << "0" << endl; };
			CTest(int a, int b) : m_nData(a*b)  { cout << "0" << endl; };;
			
			//Getter 함수
			int GetData(void) const //const = read only
			{ 
				return m_nData; 
			};
			//Setter 함수
			void SetData(int a) 
			{
				if(a < 0)
					m_nData = 0;
				else
					m_nData = a;
			}; 

		private:
			int m_nData;
		};

		CTest x(10);
		CTest y(10, 20);
		//CTest z; //error - 해당 생성자가 없기 때문

		cout << x.GetData() << endl; //10
		cout << y.GetData() << endl; //30
	}
	return 0;

}

#endif