#include <iostream>
#include <vector>
using namespace std;

class Unit
{
public:
	Unit(); // 생성자 선언
	int x;
	int y;
	
	virtual void Attack(Unit* unit) = 0 // 순수가상함수(pure virtual function) 
	{
		cout << typeid(*this).name() << "Attack" << endl;
	}

	virtual void ShowInfo()
	{
		cout << "이름 : " << typeid(*this).name() << "  ";
		cout << "메모리 주소 : " << this << "  ";
		cout << "좌표 : " << x << ", " << y << endl;
	}
};

int main()
{


	return 0;
}