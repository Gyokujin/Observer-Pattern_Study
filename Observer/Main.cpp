#include <iostream>
#include <vector>
using namespace std;

class Unit // �߻� Ŭ����
{
public:
	// Unit(); // ������ ����
	string name;
	int x;
	int y;
	
	// ���� ���� �Լ�(pure virtual function) 
	virtual void Attack(Unit* unit) = 0; 
	virtual void Move(int x, int y) = 0;

	// ���� �Լ�
	virtual void SkillA(Unit* unit) {};
	virtual void SkillB(Unit* unit) {};
	virtual void SkillC(Unit* unit) {};

	virtual void ShowInfo()
	{
		cout << "�̸� : " << typeid(*this).name() << "  ";
		cout << "�޸� �ּ� : " << this << "  ";
		cout << "���� ��ǥ : " << x << ", " << y << endl;
	}
};

class Marin : public Unit // ��üȭ : ����Ŭ������ ��ӹ޾� �ڽ�Ŭ������ ����. �߻� Ŭ������ ������ ��� �޾Ƽ� ������ �����Ѵ�.
{
public:
	void Attack(Unit* unit) override // ���� ���� �Լ��� ���� �������̵� �ؾ��Ѵ�.
	{
		cout << "������ " << typeid(*unit).name()  << "���� ������ �õ��Ͽ���." << endl;
	}

	void Move(int x, int y) override
	{
		cout << "������ " << x << ", " << y << "�� �̵��Ͽ���." << endl;
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