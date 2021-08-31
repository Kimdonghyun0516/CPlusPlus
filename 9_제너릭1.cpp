#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>

typedef struct USERDATA
{
    int age;
    string name;
} USERDATA;

class Human
{
public:
    int age = 0;
    string name = "";

    Human():age(-1), name("이름없음") {} // 기본생성자
    Human(int age, string name)
    {
        this->name = name;
        this->age = age;
    }
    void Print(void)
    {
        cout << name << ", " << age << endl;
    }
};

#include <vector>
#include <list>

int main()
{
    // vector + 구조체
    if (0)
    {
        std::vector<USERDATA> vec(3);

        vec[0] = USERDATA{ 10, "영희"};
        vec[1] = USERDATA{ 20, "철수"};
        vec[2] = USERDATA{ 33, "기영이"};
        //1. []연산자
        for (auto& n : vec)
        {
           cout << n.age <<", " << n.name << endl;
        }
        cout << endl;

        //2. 범위기반 for문
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i].age << ", " << vec[i].name << endl;
        }
        
        //3. 반복자 사용
        auto p1 = begin(vec); // p1 = vec.begin();
        while (p1 != end(vec))
        {
            cout << p1->age << ", " << p1->name << endl;
            p1++;
        }
        cout << endl;

        ///////////////
        // 2명 추가
        USERDATA a = { 40, "김연아" };
        vec.push_back(a);
        vec.push_back(USERDATA{ 50, "홍길동"});

        for (auto& n : vec)
        {
            cout << n.age << ", " << n.name << endl;
        }
        cout << endl;
    }

    // vector + 클래스
    if (1)
    {
        vector<Human> vec(3);

        vec[0] = Human(10, "기영이");
        vec[1] = Human(20, "연아");
        vec[2] = Human(30, "철수");

        for (auto& n : vec) n.Print();
        cout << endl;
        ///////////////////////////
        vec.push_back(Human(40, "엄마"));
        vec.push_back(Human(50, "아빠"));
        vec.push_back(Human(60, "할배"));

        for (auto& n : vec) n.print();
        cout << endl;
    }
	return 0;
}
#endif