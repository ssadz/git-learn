#include <iostream>
#include "Welcome.h"
#include "Calculator.h"

int main() {
    std::cout << "Hello, Git!" << std::endl;
    printWelcome();
    
    std::cout << "开始使用高级计算器..." << std::endl;
    
    // 创建计算器对象并运行
    Calculator calc;
    calc.run();
    
    return 0;
} 