#include <iostream>

//(x^5 + 2*(x^2 - 4) + x) / x^3
int calculate_expression1(int x) {
    int result;
    __asm {
        mov eax, x
        mov ecx, eax
        imul ecx, eax
        imul ecx, eax
        mov ebx, ecx
        imul ecx, eax
        imul ecx, eax

        mov edx, eax
        imul edx, eax
        sub edx, 4
        shl edx, 1

        add ecx, edx
        add ecx, eax

        mov eax, ecx
        cdq
        idiv ebx

        mov result, eax
    }
    return result;
}

//((2*x - 1)*(2*x + 1)*(x + 3)) / (2*x)
int calculate_expression2(int x) {
    int result;
    __asm {
        mov eax, x

        mov ecx, eax
        shl ecx, 1
        mov edx, ecx
        sub edx, 1
        add ecx, 1
        imul edx, ecx

        mov ecx, eax
        add ecx, 3
        imul edx, ecx

        shl eax, 1
        mov ecx, eax
        mov eax, edx
        cdq
        idiv ecx

        mov result, eax
    }
    return result;
}

//((4*x - 1)*(4*x + 1)) / 4
int calculate_expression3(int x) {
    int result;
    __asm {
        mov eax, x

        shl eax, 2
        mov ecx, eax
        sub ecx, 1
        add eax, 1
        imul eax, ecx

        cdq
        mov ecx, 4
        idiv ecx

        mov result, eax
    }
    return result;
}

int main() {
    int x;
    std::cout << "Введите значение x: ";
    std::cin >> x;

    int result1 = calculate_expression1(x);
    int result2 = calculate_expression2(x);
    int result3 = calculate_expression3(x);

    std::cout << "Результат 1: " << result1 << std::endl;
    std::cout << "Результат 2: " << result2 << std::endl;
    std::cout << "Результат 3: " << result3 << std::endl;

    return 0;
}