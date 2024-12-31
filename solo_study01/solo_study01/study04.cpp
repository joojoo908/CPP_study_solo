#include <iostream>

class Base {
public:
	int num;
	virtual void show() { std::cout << "Base class" << std::endl; } // ���� �Լ�
};

class Derived : public Base {
public:
	void show() override { std::cout << "Derived class" << std::endl; }
};

int main() {

	double d_num = 10.1234;
	double d_num2 = 1.4321;
	const int c_num = 5;
	int i_num;

	//--�⺻���� ����ȯ----------------------------
	//c ������ ����ȯ
	i_num = (int)d_num2;
	std::cout << i_num << std::endl;
	//c++ �� ����ȯ
	i_num = static_cast<int>(d_num);
	std::cout << i_num << std::endl;

	//--const ���� const���� ����------------------
	//c
	int* pc_num = (int *)&c_num;
	*pc_num=7;
	std::cout << c_num << std::endl;
	std::cout << *pc_num << std::endl;
	//c++
	int *pc_num2 = const_cast<int*>(&c_num);
	*pc_num2=7;
	std::cout << c_num << std::endl;
	std::cout << *pc_num2 << std::endl;



	// ��ĳ������ ��� �ڿ������� ����ȴ�.
	std::cout << std::endl;
	Derived* derivedPtr2 = new Derived();
	Base* basePtr2 = derivedPtr2;  // �θ� Ŭ���� �����Ϳ� �ڽ� Ŭ���� ��ü �Ҵ�
	derivedPtr2->show();
	basePtr2->show();

	//--�ٿ�ĳ����---------------------------------
	//��ĳ���ð��� �ٸ��� �θ� Ŭ������ �ڽ� Ŭ���� Ĵü�� ����ų ������ �����ϱ� ������ 
	// ������ �߻��� ���ɼ��� �����Ѵ�
	std::cout << std::endl;
	//c
	Base* basePtr_c = new Derived();  // �θ� Ŭ���� �����Ϳ� �ڽ� Ŭ���� ��ü �Ҵ�
	//Base* basePtr_c = new Base();  // ���� �߻�!
	Derived* derivedPtr_c = (Derived*)basePtr_c;
	derivedPtr_c->show();
	//c++
	Base* basePtr = new Derived();  // �θ� Ŭ���� �����Ϳ� �ڽ� Ŭ���� ��ü �Ҵ�
	Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
	derivedPtr->show();

	//�޸� ��Ʈ�� ���� ����ȯ
	//�ּҸ� ������ ����ȯ ��Ű�� ������ �⺻������ �������� ���ϴ�
	//c
	int i_c = 65;
	char* pc_c = (char*)&i_c;
	std::cout << i_c << std::endl;
	std::cout << pc_c << std::endl;
	//C++
	int i = 65;
	char* pc = reinterpret_cast<char*>(&i);
	std::cout << i << std::endl;
	std::cout << pc << std::endl;

}