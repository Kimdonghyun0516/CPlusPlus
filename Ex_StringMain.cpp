//#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h> 
#include <iostream> 

using namespace std;

#include "Ex_String.h"

int main()
{
	// C의 문자열  처리				- char[]
	if(0)
	{
		char a = 'a';    // 1글자          --> 문자
		// char b = "a"; // 2글자 ( a\n )  --> 문자열(문자의 배열)

		int kor[10];
		int math[] = { 100, 90 ,80 ,88, }; // '배열'은 동형의 자료를 한 변수이름으로 모아서 관리 'math라는 변수 하나로 30개를 관리하겠다.'
		// int eng[]; // error

		// 문자열 배열
		char name[30] = "손세정"; // 

		// 문자열 함수
		// name = "유재석"; // 새 값 할당 할때 이렇게 넣을수 없음
		strcpy_s(name, "유재석");

		// if (name == "유재석") // 비교
		// if (strcmp(name, "유재석") == 0);
	}

	// C++의 문자열 처리			    - string
	if (0)
	{
		// string -> 데이터 타입
		string a;     // 초기값 없음
		cout << a << endl;

		a = "유재석"; // 새 값 할당
		cout << a << endl;

		string b(a);  // 초기값 있음   -> b생성자에 a 를 넣어줌
		cout << b << endl; 

		string c("김수환무");  // 초기값 있음
		cout << c << endl;
	}

	// 내가 만든 MyString 객체 사용   - MyString
	if (0)
	{
		string x; // -----------------------------------------기본 생성자
		x.assign("홍길동");
		x.append("바보");
		//x.clear();
		cout << x << endl;

		string y("유재석"); //--------------------------------변환 생성자
		cout << y << endl;

		string z(y);
		cout << z << endl;

		z = x; // 대입연산자 오버로딩 완료
		cout << z << endl;

		z = x + y; // 산순연산자+ 오버로딩 완료
		cout << z << endl;

		//-----------------------------------------------------------------------------------------------------

		MyString a;  // --> (Ex_String.h 의) ------------------기본생성자가 불린다.
		a.SetString("손세정");
		// cout << a << endl; error
		cout << a.GetString() << endl;

		MyString b("박명수"); // ------------------------------변환 생성자
		b.SetString("하하");
		cout << b.GetString() << endl;
		
		MyString c(b); // -------------------------------------복사 생성자
		cout << c.GetString() << endl;

		c = a; // 대입연산자 오버로딩
		cout << c.GetString() << endl;

		//c = a+b; // 산술연산자 + 오버로딩
		//cout << c.GetString() << endl;
	}

	//정적멤버(변수, 함수)
	if (0)
	{
		cout << MyString::m_nCount << endl;

		MyString a;
		MyString b;
		cout << a.m_nCount << endl;
		{
			MyString c;
			cout << "안" << c.m_nCount << endl;
		}
		cout << b.m_nCount << endl;
	}

	//추가확인
	if (1)
	{
		//MyString a;
		//MyString b("홍길동");
		//MyString c(a);

		FunnyString x;
		x.SetString("바보");
		cout << x.GetString() << endl;
	}
	return 0;
}

#endif