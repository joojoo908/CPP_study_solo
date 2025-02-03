
#include "stdafx.h"

// 몇 개의 간단한 함수 정의
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {

    // 함수 포인터 배열 선언
    int (*operation[3])(int, int) = { add, subtract, multiply };
    int (*operation2)(int, int);

    // 배열을 통해 함수 호출
    cout << "Add: " << operation[0](5, 3) << endl;     
    cout << "Subtract: " << operation[1](5, 3) << endl;  
    cout << "Multiply: " << operation[2](5, 3) << endl;   

    operation2 = &add;
    cout << "Add: " << operation2(5, 3) << endl;
    operation2 = &subtract;
    cout << "Subtract: " << operation2(5, 3) << endl;
    operation2 = &multiply;
    cout << "Multiply: " << operation2(5, 3) << endl;

}