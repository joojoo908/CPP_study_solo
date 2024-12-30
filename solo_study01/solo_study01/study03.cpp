#include<iostream>
#include<string>

template <typename T>
T Plus(T Num1, T Num2)
{
	return Num1 + Num2;
}



//struct Point {
//    int x, y;
//
//    // ���� ������ �����ε�
//    Point operator+(const Point& other) const {
//        Point result;
//        result.x = this->x + other.x;  // x��ǥ ���ϱ�
//        result.y = this->y + other.y;  // y��ǥ ���ϱ�
//        return result;
//    }
//
//};

class Point {
public:
    int x, y;

    // ������
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // ���� ������ �����ε� (Point + Point)
    Point operator+(const Point& other) const {
        Point result;
        result.x = this->x + other.x;  // x��ǥ ���ϱ�
        result.y = this->y + other.y;  // y��ǥ ���ϱ�
        return result;
    }

    //<< ������ �����ε�
    /*friend �Լ� ��� ����
        << �����ڴ� �Ϲ������� **ģ�� �Լ�(friend function)**�� �����˴ϴ�.
        �� ������, std::ostream ��ü�� �����ؾ� �ϱ� ������ ��� ��Ʈ���� ���� �׼��� ������ �ʿ��ϰ�, �̴� Point Ŭ������ private ����� ������ �� �ֵ��� �ϱ� ���� ģ�� �Լ��� �����ϴ� ���Դϴ�.
        friend �Լ��� Ŭ���� �ܺο� ���ǵ�����, Ŭ���� ������ private ����� ������ �� �ֽ��ϴ�.*/

    /*friend �Լ��� ��� �Լ��� �ƴϱ� ������ ��ü ������ ����� ������ �� this �����͸� ����� �� �����ϴ�. ��� �� ��ü�� �Ű������� �޽��ϴ�.
        �ڵ尡 ��� �Լ����� �ټ� ������ �� �ֽ��ϴ�.*/
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "Point(" << point.x << ", " << point.y << ")";
        return os;
    }
};


int main() {

	//Plus<std::string> plus;

	std::cout << Plus<int>(1, 10) << std::endl;
	std::cout << Plus<float>(1.2, 10.2) << std::endl;
	std::cout << Plus('A', '1') << std::endl;
	std::cout << Plus<std::string>("abcd", "1234") << std::endl;
    Point a;
    a = Plus<Point>( Point(1, 2), Point(2, 3) );
	std::cout << a.x << " , " << a.y << std::endl;
	std::cout << Plus<Point>(Point(1, 2), Point(2, 3)) << std::endl;
	
}