#include <iostream>

//((2*x - 1)*(2*x + 1)*(x + 3)) / (2*x)
int calculate_expression(int x) {
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

//Сумма цифр натурального числа
int sum_of_digits(int x) {
    int result;
    __asm {
        mov eax, x
        xor ebx, ebx

        sum_loop :
        test eax, eax
            jz end_loop

            xor edx, edx
            mov ecx, 10
            div ecx
            add ebx, edx
            jmp sum_loop

            end_loop :
        mov result, ebx
    }
    return result;
}

int main() {
    int x;
    std::cout << "Введите значение x: ";
    std::cin >> x;

    int result = calculate_expression(x);

    std::cout << "Результат: " << result << std::endl;

    int sum = sum_of_digits(x);
    std::cout << "Сумма цифр числа: " << sum << std::endl;

    return 0;
}
