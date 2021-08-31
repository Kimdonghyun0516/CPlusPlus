//#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h> 
#include <iostream> 

using namespace std;


int main()
{
	// Ŭ���� ����(������Ÿ��)
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

	// �����ڿ� �Ҹ���
	if (0)
	{
		//1. ��ü����
		//cout << "-- ����" << endl;
		//CTest a;// ������
		//cout << "-- ��" << endl;

		//2. ��ü�� ��������
		cout << "-- ���� ����" << endl;
		CTest* p = new CTest;
		//...
		delete p;
		cout << "-- ���� ��" << endl;
	}
	//����Ʈ ������
	if (0)
	{
		class CTest
		{
		public:
			CTest(void) { m_nData = 20; }
			//int m_nData = 10;//C++11�����Ϸ� ���� ����
			int m_nData;
		};
		CTest a;
		cout << a.m_nData << endl;
	}

	// �����ڿ� �ʱ�ȭ ���
	if (0)
	{
		class CTest 
		{
			int m_nData; //�⺻ ���� �����ڴ� private��

		public :
			CTest(void) : m_nData(20)//�ʱ�ȭ ���
			{
				//m_nData = 20;
				cout << "CTest()" << endl;
			}
			CTest(int nParam) : m_nData(nParam) // �ʱ�ȭ ���
			{
				//m_nData = nParam;
				cout << "CTest(int nParam)" << endl;
			}
			~CTest()
			{
				cout << "~CTest()" << endl;
			}
		};

		cout << "main ����" << endl;
		CTest a;
		CTest b(100);
		cout << "main ��" << endl;
	}

	// ������ �����ε�
	// Getter/Setter �Լ�
	if (1)
	{
		class CTest
		{
		public:
			CTest(void)			: m_nData(-1)   { cout << "0" << endl; };
			CTest(int a)		: m_nData(a)    { cout << "0" << endl; };
			CTest(int a, int b) : m_nData(a*b)  { cout << "0" << endl; };;
			
			//Getter �Լ�
			int GetData(void) const //const = read only
			{ 
				return m_nData; 
			};
			//Setter �Լ�
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
		//CTest z; //error - �ش� �����ڰ� ���� ����

		cout << x.GetData() << endl; //10
		cout << y.GetData() << endl; //30
	}
	return 0;

}

#endif