
#include "stdafx.h"

// �� ���� ������ �Լ� ����
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

    // �Լ� ������ �迭 ����
    int (*operation[3])(int, int) = { add, subtract, multiply };
    int (*operation2)(int, int);

    // �迭�� ���� �Լ� ȣ��
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