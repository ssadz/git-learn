#include <iostream>
#include <string>

// 打印欢迎信息的函数
void printWelcome() {
    std::cout << "欢迎学习Git版本控制!" << std::endl;
}

// 简单计算器功能
double calculate(double a, double b, char op) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if(b != 0) {
                return a / b;
            } else {
                std::cout << "错误：除数不能为零!" << std::endl;
                return 0;
            }
        default:
            std::cout << "不支持的操作符!" << std::endl;
            return 0;
    }
}

// 运行计算器
void runCalculator() {
    double num1, num2;
    char operation;
    bool running = true;
    std::string input;

    std::cout << "\n==== 简易计算器 ====\n";
    std::cout << "支持的操作: +, -, *, /\n";
    std::cout << "输入'q'退出\n";

    while(running) {
        std::cout << "\n请输入计算表达式 (例如: 5 + 3): ";
        std::cin >> num1 >> operation;
        
        if(std::cin.fail() || operation == 'q') {
            running = false;
            break;
        }

        std::cin >> num2;
        
        if(std::cin.fail()) {
            std::cout << "输入格式错误！" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        double result = calculate(num1, num2, operation);
        std::cout << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
    }
    
    std::cout << "计算器已退出。" << std::endl;
}

int main() {
    std::cout << "Hello, Git!" << std::endl;
    printWelcome();
    
    std::cout << "开始使用简易计算器..." << std::endl;
    runCalculator();
    
    return 0;
}