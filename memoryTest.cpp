#include <iostream>
#include <chrono>

int main() {
    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();
    
    // 测试栈内存分配
    int arr[5];
    int nums[5] = { 1, 3, 2, 5, 4 };
    
    // 记录栈分配后的时间
    auto stack_end = std::chrono::high_resolution_clock::now();
    
    // 测试堆内存分配
    int* arr1 = new int[5];
    int* nums1 = new int[5];
    for(int i = 0; i < 5; i++) {
        nums1[i] = i + 1;
    }
    
    // 记录堆分配后的时间
    auto heap_end = std::chrono::high_resolution_clock::now();
    
    // 计算并输出时间差
    auto stack_time = std::chrono::duration_cast<std::chrono::nanoseconds>(stack_end - start).count();
    auto heap_time = std::chrono::duration_cast<std::chrono::nanoseconds>(heap_end - stack_end).count();
    
    std::cout << "栈内存分配时间: " << stack_time << " 纳秒" << std::endl;
    std::cout << "堆内存分配时间: " << heap_time << " 纳秒" << std::endl;
    
    // 打印数组内容以验证
    std::cout << "\n栈数组 nums 内容: ";
    for(int i = 0; i < 5; i++) {
        std::cout << nums[i] << " ";
    }
    
    std::cout << "\n堆数组 nums1 内容: ";
    for(int i = 0; i < 5; i++) {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;
    
    // 释放堆内存
    delete[] arr1;
    delete[] nums1;
    
    return 0;
}