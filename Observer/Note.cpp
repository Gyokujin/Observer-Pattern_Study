//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Unit // �߻� Ŭ���� : ���� ���� �Լ��� ������ �ִ� Ŭ����
//{
//private:
//	string name;
//	int atk;
//	int hp;
//
//	int posX = 0;
//	int posY = 0;
//
//public:
//	Unit(string _name, int _atk, int _hp) // �����ڷ� �⺻ ���� �Ҵ�
//	{
//		name = _name;
//		atk = _atk;
//		hp = _hp;
//	}
//
//	virtual void Move(int x, int y)
//	{
//		cout << GetName() << "�� " << x << ", " << y << " ��ǥ�� �̵��Ͽ���" << "  ";
//		cout << "��ǥ : " << GetPosX() << ", " << GetPosY() << " => ";
//
//		SetPosX(x);
//		SetPosY(y);
//		cout << GetPosX() << ", " << GetPosY() << endl;
//	}
//
//	// ���� ���� �Լ�(pure virtual function)
//	virtual void Attack(Unit* unit) = 0;
//	virtual void SkillA(Unit* unit) = 0; // ��� ������ �ּ� �ΰ��� ��ų�� �־�����.
//	virtual void SkillB(Unit* unit) = 0;
//
//	void Damage(int damage)
//	{
//		cout << GetName() << "�� " << damage << "�� �������� �Ծ���.  ";
//		cout << "ü�� : " << GetHp() << " => ";
//
//		SetHp(GetHp() - damage);
//		cout << GetHp() << endl;
//
//		if (GetHp() <= 0)
//		{
//			cout << GetName() << "�� ��������." << endl;
//			Die();
//		}
//	}
//
//	string GetName()
//	{
//		return name;
//	}
//
//	int GetAtk()
//	{
//		return atk;
//	}
//	void SetAtk(int atk)
//	{
//		this->atk = atk;
//	}
//
//	int GetHp()
//	{
//		return hp;
//	}
//	void SetHp(int hp)
//	{
//		this->hp = hp;
//	}
//
//	int GetPosX()
//	{
//		return posX;
//	}
//	void SetPosX(int posX)
//	{
//		this->posX = posX;
//	}
//
//	int GetPosY()
//	{
//		return posY;
//	}
//	void SetPosY(int posY)
//	{
//		this->posY = posY;
//	}
//
//	void Upgrade()
//	{
//		cout << GetName() << "�� ���ݷ��� ���׷��̵� �Ǿ���." << "  ";
//		cout << GetAtk() << " => ";
//
//		SetAtk(GetAtk() + 1);
//		cout << GetAtk() << endl;
//	}
//
//	virtual void ShowInfo()
//	{
//		cout << "�̸� : " << name << "  " << "���ݷ� : " << GetAtk() << "  " << "ü�� : " << GetHp() << "  ";
//		cout << "���� ��ǥ : " << posX << ", " << posY << endl;
//	}
//
//protected:
//	void Die()
//	{
//		delete this;
//	}
//};
//
//class Marin : public Unit // ��üȭ : ����Ŭ������ ��ӹ޾� �ڽ�Ŭ������ ����. �߻� Ŭ������ ������ ��� �޾Ƽ� ������ �����Ѵ�.
//{
//public:
//	Marin(string _name, int _atk, int _hp) : Unit(_name, _atk, _hp) {}
//
//	void Attack(Unit* unit) override // ���� ���� �Լ��� ���� �������̵� �ؾ��Ѵ�.
//	{
//		cout << GetName() << "�� " << unit->GetName() << "���� ������ �õ��Ͽ���." << endl;
//		unit->Damage(GetAtk());
//	}
//
//	void SkillA(Unit* unit) override
//	{
//		cout << "Active Stim Pack!!" << endl;
//		Upgrade();
//	}
//
//	void SkillB(Unit* unit) override
//	{
//		cout << "Active Granade!!" << endl;
//		cout << GetName() << "�� " << unit->GetName() << "���� ����ź�� ��ô�Ͽ���." << endl;
//		unit->Damage(GetAtk() + 5);
//	}
//};
//
//class Medic : public Unit
//{
//public:
//	Medic(string _name, int _atk, int _hp) : Unit(_name, _atk, _hp) {}
//
//	void Attack(Unit* unit) override
//	{
//		cout << "�̷�.. �޵��� ������ �Ұ����ϴ�!" << endl;
//	}
//
//	void SkillA(Unit* unit) override
//	{
//		cout << "Active Heal!" << endl;
//		cout << GetName() << "�� " << unit->GetName() << "�� ġ���Ͽ���." << "  ";
//
//		cout << unit->GetName() << "�� ü�� : " << unit->GetHp() << " => ";
//		unit->SetHp(unit->GetHp() + GetAtk()); // �ش� ������ ü���� �޵��� ���ݷ¸�ŭ ���Ѵ�.
//		cout << unit->GetHp() << endl;
//	}
//
//	void SkillB(Unit* unit) override
//	{
//		cout << "Active Cure" << endl;
//		cout << GetName() << "�� " << unit->GetName() << "�� ��ȭ�Ͽ���." << "  ";
//	}
//};
//
//class Commander
//{
//private:
//	vector<Unit*> unitGroup;
//
//public:
//	enum Command { GroupAttack, GroupMove };
//
//	void AddGroup(Unit* unit)
//	{
//		unitGroup.push_back(unit);
//	}
//
//	void RemoveGroup(Unit* unit) // unitGroup�� ������� ������ �ִ��� Ȯ���ϰ� �����.
//	{
//		vector<Unit*>::iterator it;
//
//		for (it = unitGroup.begin(); it != unitGroup.end(); it++)
//		{
//			if (&unit == &(*it)) // Ư�� ������ ������ �ּҸ� �����ϰ� unitGroup�� ��ȸ�ϸ� �� ������ �ּҸ� Ȯ���ϰ� ó�� ������ �ּҿ� ��ġ�ϸ� break�Ѵ�.(�ּҰ� ���ٴ°� ���� ã���� �ϴ� ������ �ǹ��Ѵ�)
//				break;
//		}
//
//		if (it != unitGroup.end()) // break�� ����Ǿ����� �ش� ������ ��(ã���� �ϴ� ������ vector�� �ִ�), ������� �ʾҴٸ� �ش� ������ ������ �ȴ�(ã���� �ϴ� ������ vector�� ����) 
//		{
//			unitGroup.erase(it);
//		}
//	}
//
//	void Command(Command command, Unit* unit, int moveX = 0, int moveY = 0)
//	{
//		switch (command)
//		{
//		case Command::GroupAttack:
//			for (Unit* selectUnit : unitGroup)
//			{
//				selectUnit->Attack(unit);
//			}
//			break;
//
//		case Command::GroupMove:
//			for (Unit* selectUnit : unitGroup)
//			{
//				selectUnit->Move(moveX, moveY);
//			}
//			break;
//		}
//	}
//};
//
//int main()
//{
//	Commander commander;
//	Marin* marinA = new Marin("������ ����", 3, 5);
//	Marin* marinB = new Marin("Ÿ�� ����", 2, 3);
//	Marin* marinC = new Marin("�Ǵٸ� ����", 4, 8);
//	Marin* marinD = new Marin("�ܴ��� ����", 2, 20);
//	Medic* medicA = new Medic("�߱��ϴ� �޵�", 3, 10);
//
//	marinA->ShowInfo();
//	marinA->Attack(marinB);
//
//	marinA->Move(3, 3);
//	marinA->SkillA(marinA);
//	marinA->SkillB(marinC);
//
//	medicA->Attack(marinD);
//	marinA->Attack(marinD);
//
//	medicA->SkillA(marinD);
//	medicA->SkillB(marinD);
//
//	Marin* marins[3];
//	Medic* medics[2];
//
//	for (int i = 0; i < size(marins); i++)
//	{
//		marins[i] = new Marin("���� " + to_string(i + 1), 5, 3);
//		commander.AddGroup(marins[i]);
//	}
//
//	for (int i = 0; i < size(medics); i++)
//	{
//		medics[i] = new Medic("�޵� " + to_string(i + 1), 0, 8);
//		commander.AddGroup(medics[i]);
//	}
//
//	commander.Command(Commander::GroupAttack, marinD);
//	commander.Command(Commander::GroupMove, NULL, 4, 2);
//
//	return 0;
//}