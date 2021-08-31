#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <vector>

int foo()
{
	if (1) // ����
		//1. C������ ���� ó��
		//return -1;//������ ���, ��ӵ� ��(-1)�� ��ȯ��
					//1) �� ���� ��������, ������ ������� ȥ�������� �� ����
					//2) �Լ��� ������ ��ȯ�� ��, ȣ���ڰ� �ݵ�� ������ ó���ϵ��� ������ �� ����
					
		//2. C++�� ����ó�� (��ȯ���� ������ �и���)
		throw 1.1 ;   //������ ���, ��ȯ�� �ƴ� ���ܸ� throw��
				     // : ���ϰ��� ������ ������ �и���

	// ���...
	int count = -1;
	return count;
}
//�������� Ŭ����
class MyMemoryExeption : public std::exception
{
	int errCode;
	int errNumber;
public:
	virtual char const* what() const noexcept // noexcept
	{
		return "�޸� ���� �߻�";
	}
};
int foo2()
{
	if (1) // ���м�
		throw MyMemoryExeption();
	//...
	return 0;
}

int main()
{
	// ����ó��
	if (0)
	{
		try 
		{ 
			foo(); 
		}
		catch (int a) // int���� ���ܸ� ó���ϰڴ�
		{
			cout << "���ܹ߻�(int)" << a << endl;
		}
		catch (double a) // double���� ���ܸ� ó���ϰڴ�
		{
			cout << "���ܹ߻�(double)" << a << endl;
		}
		catch (...) // -> anytype ���ܸ� ó����
		{
			cout << "���ܹ߻�(anytype)" << endl;
		}

		cout << "bye" << endl;
	}

	// �������� Ŭ���� ���(exception)
	if (0)
	{
		try
		{
			foo2();
		}
		catch (MyMemoryExeption& m)
		{
			cout << m.what() << endl;
		}
		cout << "bye bye" << endl;
	}

	// C++ ǥ�� ���� Ŭ����
	if (0)
	{
		////////////////////////////////////////////////
		//1. (std::bad_alloc)
		int* p = NULL;
		try
		{
			p = new int[10000]; // �׻� �����Ѵٴ� ������ ����
		}
		catch (std::bad_alloc& e)
		{
			cout << "std::bad_alloc �߻� : ";
			cout << e.what() << endl;
		}

		////////////////////////////////////////////////
		//2. (std::out_of_range)
		vector<int> v = { 1,2,3 };
		//try
		{
			v.at(5) = 5; // �߸��� �ε���
		}
		//catch (std::out_of_range& e)
		{
			//cout << "std::bad_alloc �߻� : ";
			//cout << e.what() << endl;
		}

		cout << "bye bye" << endl;
		
	}

	// noexcept
	if (1)
	{
		void xxx();				// �� �Լ��� ���ܰ� ���� ���� �ְ�, ���� ���� �ִ�
		void yyy() throw(int);  // �� �Լ��� int���� ���ܰ��ɼ� ~ 
		void zzz() throw();		// �� �Լ��� ���ܰ� ����

		//C++98
		void aaa() noexcept(false); // �� �Լ��� ���ܰ� �ִ�
		void bbb() noexcept(false); // �� �Լ��� ���ܰ� ����
		////////////////////////////
		void ccc() noexcept; // �� �Լ��� ���ܰ� �ִ�
		void ddd();			 // �� �Լ��� ���ܰ� ����

		bool b = noexcept(ccc());
		cout << b << endl;
	}
	return 0;
}

#endif