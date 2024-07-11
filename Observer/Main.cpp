#include <iostream>
#include <vector>
using namespace std;

class Unit // 추상 클래스
{
public:
	// Unit(); // 생성자 선언
	string name;
	int x;
	int y;
	
	// 순수 가상 함수(pure virtual function) 
	virtual void Attack(Unit* unit) = 0; 
	virtual void Move(int x, int y) = 0;

	// 가상 함수
	virtual void SkillA(Unit* unit) {};
	virtual void SkillB(Unit* unit) {};
	virtual void SkillC(Unit* unit) {};

	virtual void ShowInfo()
	{
		cout << "이름 : " << typeid(*this).name() << "  ";
		cout << "메모리 주소 : " << this << "  ";
		cout << "현재 좌표 : " << x << ", " << y << endl;
	}
};

class Marin : public Unit // 실체화 : 가상클래스를 상속받아 자식클래스를 생성. 추상 클래스인 유닛을 상속 받아서 마린을 정의한다.
{
public:
	void Attack(Unit* unit) override // 순수 가상 함수는 전부 오버라이드 해야한다.
	{
		cout << "마린은 " << typeid(*unit).name()  << "에게 공격을 시도하였다." << endl;
	}

	void Move(int x, int y) override
	{
		cout << "마린은 " << x << ", " << y << "로 이동하였다." << endl;
	}

	void SkillA(Unit* unit) override
	{
		cout << "Active Stim Pack!!" << endl;
	}
};

int main()
{
	Marin marinA;
	marinA.Move(3, 2);
	marinA.Attack(&marinA);

	return 0;
}