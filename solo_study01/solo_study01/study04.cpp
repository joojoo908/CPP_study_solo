#include <iostream>

class Base {
public:
	int num;
	virtual void show() { std::cout << "Base class" << std::endl; } // 가상 함수
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

	//--기본적인 형변환----------------------------
	//c 에서의 형변환
	i_num = (int)d_num2;
	std::cout << i_num << std::endl;
	//c++ 의 형변환
	i_num = static_cast<int>(d_num);
	std::cout << i_num << std::endl;

	//--const 값의 const성질 제거------------------
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



	// 업캐스팅의 경우 자연스럽게 실행된다.
	std::cout << std::endl;
	Derived* derivedPtr2 = new Derived();
	Base* basePtr2 = derivedPtr2;  // 부모 클래스 포인터에 자식 클래스 객체 할당
	derivedPtr2->show();
	basePtr2->show();

	//--다운캐스팅---------------------------------
	//업캐스팅과는 다르게 부모 클래스가 자식 클래스 캑체를 가르킬 때에만 가능하기 때문에 
	// 문제가 발생할 가능성이 존재한다
	std::cout << std::endl;
	//c
	Base* basePtr_c = new Derived();  // 부모 클래스 포인터에 자식 클래스 객체 할당
	//Base* basePtr_c = new Base();  // 문제 발생!
	Derived* derivedPtr_c = (Derived*)basePtr_c;
	derivedPtr_c->show();
	//c++
	Base* basePtr = new Derived();  // 부모 클래스 포인터에 자식 클래스 객체 할당
	Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
	derivedPtr->show();

	//메모리 비트를 통한 형변환
	//주소를 강제로 형변환 시키기 때문에 기본적으로 안전하지 못하다
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