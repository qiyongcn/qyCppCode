#include <iostream>
#include <ctime>    // 用于 clock() 函数

int main() {
    
    // 你的程序代码
    int number;
    std::cout << "请输入一个数字: ";
    std::cin >> number;
    
    clock_t start = clock();

    for(int i = 0; i < number; i++) {
        //std::cout << "Hello, World! " << (i+1) << std::endl;
        printf("Hello, World! %d\n", i+1);
    }
    
    clock_t end = clock();
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    //system("clear");    // 对于 Unix/Linux/Mac
    // system("cls");   // 对于 Windows


    clock_t startCout = clock();

    for(int i = 0; i < number; i++) {
        std::cout << "Hello, World! " << (i+1) << std::endl;
        //printf("Hello, World! %d\n", i+1);
    }
    
    clock_t endCout = clock();
    
    double time_spentCout = (double)(endCout - startCout) / CLOCKS_PER_SEC;
    system("clear");    // 对于 Unix/Linux/Mac
    // system("cls");   // 对于 Windows
    
    std::cout << "\nprint程序运行时间：" << time_spent << " 秒" << std::endl;

    std::cout << "\ncout程序运行时间：" << time_spentCout << " 秒" << std::endl;
    
    return 0;
}