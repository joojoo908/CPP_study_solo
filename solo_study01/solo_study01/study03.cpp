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
//    // 덧셈 연산자 오버로딩
//    Point operator+(const Point& other) const {
//        Point result;
//        result.x = this->x + other.x;  // x좌표 더하기
//        result.y = this->y + other.y;  // y좌표 더하기
//        return result;
//    }
//
//};

class Point {
public:
    int x, y;

    // 생성자
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // 덧셈 연산자 오버로딩 (Point + Point)
    Point operator+(const Point& other) const {
        Point result;
        result.x = this->x + other.x;  // x좌표 더하기
        result.y = this->y + other.y;  // y좌표 더하기
        return result;
    }

    //<< 연산자 오버로딩
    /*friend 함수 사용 이유
        << 연산자는 일반적으로 **친구 함수(friend function)**로 구현됩니다.
        그 이유는, std::ostream 객체에 접근해야 하기 때문에 출력 스트림에 대한 액세스 권한이 필요하고, 이는 Point 클래스의 private 멤버에 접근할 수 있도록 하기 위해 친구 함수로 선언하는 것입니다.
        friend 함수는 클래스 외부에 정의되지만, 클래스 내부의 private 멤버에 접근할 수 있습니다.*/

    /*friend 함수는 멤버 함수가 아니기 때문에 객체 내부의 멤버에 접근할 때 this 포인터를 사용할 수 없습니다. 대신 두 객체를 매개변수로 받습니다.
        코드가 멤버 함수보다 다소 복잡할 수 있습니다.*/
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