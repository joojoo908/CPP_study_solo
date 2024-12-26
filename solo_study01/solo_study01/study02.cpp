#include<iostream>


class Counter {
private:
	int cnt;
	static int cnt_cnt;

public:

	Counter(){
		cnt = 0;
		cnt_cnt ++;
	}

	Counter(int n) {
		cnt = n;
		cnt_cnt ++;
	}

	void plus() {
		cnt ++;
	}

	int Getcnt() { return cnt; };

	static int Getcntcnt() { return cnt_cnt; };

	~Counter(){}
};

int Counter::cnt_cnt = 0;

int main() {
	
	Counter a;
	std::cout << " a_cnt: " << a.Getcntcnt() << std::endl;
	Counter b(10);
	std::cout << " b_cnt: " << b.Getcntcnt() << std::endl;
	Counter c;
	std::cout << " c_cnt: " << c.Getcntcnt() << std::endl;

	c.plus();
	c.plus();
	
	std::cout << "a: " << a.Getcnt() << " a_cnt: " << a.Getcntcnt() << std::endl;
	std::cout << "b: " << b.Getcnt() << " b_cnt: " << b.Getcntcnt() << std::endl;
	std::cout << "c: " << c.Getcnt() << " c_cnt: " << c.Getcntcnt() << std::endl;
}