#include <iostream>

long long fibArray[100];
int count = 0;
int a;
int result = 0;
int num1, num2;
const char fmt[] = "2*%d + 3*%d = 50\n";

int gcd(int a, int b) {
    int result;

    __asm {
        mov eax, a
        mov ebx, b
        jmp check
        loop_start :
        xor edx, edx
            idiv ebx
            mov eax, ebx
            mov ebx, edx
            check :
        test ebx, ebx
            jnz loop_start
            mov result, eax
    }

    return result;
}

int main() {

    std::cout << "Введите целое положительное число a: ";
    std::cin >> a;

    __asm {
        mov eax, a
        imul eax, eax
        imul eax, eax
        imul eax, eax
        mov ebx, eax
        imul eax, eax
        cdq
        idiv ebx
        mov ecx, eax

        mov eax, a
        imul eax, eax
        imul eax, eax
        imul eax, eax
        add ecx, eax
        add ecx, a
        mov result, ecx
    }

    std::cout << "Результат: " << result << std::endl;


    __asm {
        mov ecx, 1        
        outer_loop:
        cmp ecx, 26     
            jge end_outer    

            mov edx, 1          
            inner_loop :
            cmp edx, 17         
            jge next_x         

            mov eax, ecx        
            imul eax, 2         
            mov ebx, edx      
            imul ebx, 3       
            add eax, ebx       

            cmp eax, 50        
            jne skip_print      

            push edx
            push ecx

            push edx
            push ecx
            push offset fmt
            call printf
            add esp, 12        

            pop ecx
            pop edx

            mov eax, count
            inc eax
            mov count, eax

            skip_print :
        inc edx             
            jmp inner_loop    

            next_x :
        inc ecx          
            jmp outer_loop     

            end_outer :
    }

    std::cout << "Количество решений: " << count << std::endl;

    count = 0;

    __asm {
        mov eax, 0         
        mov ebx, 1         
        lea edi, fibArray  
        mov ecx, 0        

        fibonacci_loop:
        cmp eax, 2147483647 
            ja end_fibonacci

            mov[edi + ecx * 8], eax 
            inc ecx

            mov edx, eax       
            add eax, ebx     
            mov ebx, edx     

            jmp fibonacci_loop

            end_fibonacci :
        mov count, ecx    
    }

    std::cout << "Числа Фибоначчи: " << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << fibArray[i] << " ";
    }
    std::cout << std::endl;



    std::cout << "Введите числитель: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель: ";
    std::cin >> num2;

    int cmnDiv = gcd(num1, num2);

    num1 /= cmnDiv;
    num2 /= cmnDiv;

    std::cout << "Сокращенная дробь: " << num1 << "/" << num2 << std::endl;

    return 0;
}