#include <iostream>
#include <vector>
using namespace std;

class Unit
{
public:
	Unit(); // ������ ����
	int x;
	int y;
	
	virtual void Attack(Unit* unit) = 0 // ���������Լ�(pure virtual function) 
	{
		cout << typeid(*this).name() << "Attack" << endl;
	}

	virtual void ShowInfo()
	{
		cout << "�̸� : " << typeid(*this).name() << "  ";
		cout << "�޸� �ּ� : " << this << "  ";
		cout << "��ǥ : " << x << ", " << y << endl;
	}
};

int main()
{


	return 0;
}