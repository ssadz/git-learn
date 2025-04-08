#include "Calculator.h"
#include <iostream>
#include <cmath>

// 构造函数
Calculator::Calculator() : memory(0.0) {
}

// 计算函数
double Calculator::calculate(double a, double b, char op) {
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
        case '%':
            return a * (b / 100.0); // 计算百分比: a的b%
        case '^':
            return std::pow(a, b); // 计算幂
        default:
            std::cout << "不支持的操作符!" << std::endl;
            return 0;
    }
}

// 运行计算器
void Calculator::run() {
    double num1, num2;
    char operation;
    bool running = true;
    std::string input;

    std::cout << "\n==== 高级计算器 ====\n";
    std::cout << "支持的操作: +, -, *, /, %, ^\n";
    std::cout << "特殊命令:\n";
    std::cout << "  M 查看内存值\n";
    std::cout << "  MS 将结果存入内存\n";
    std::cout << "  MC 清除内存\n";
    std::cout << "  H 查看历史记录\n";
    std::cout << "  C 清除历史记录\n";
    std::cout << "  Q 退出计算器\n";

    while(running) {
        std::cout << "\n请输入计算表达式或命令: ";
        std::cin >> input;
        
        // 处理特殊命令
        if(input == "Q" || input == "q") {
            running = false;
            break;
        } else if(input == "M") {
            std::cout << "内存值: " << memory << std::endl;
            continue;
        } else if(input == "MS" && !history.empty()) {
            memory = history.back();
            std::cout << "已将 " << memory << " 存入内存" << std::endl;
            continue;
        } else if(input == "MC") {
            clearMemory();
            std::cout << "内存已清除" << std::endl;
            continue;
        } else if(input == "H") {
            showHistory();
            continue;
        } else if(input == "C") {
            clearHistory();
            std::cout << "历史记录已清除" << std::endl;
            continue;
        }
        
        // 正常计算
        try {
            // 如果输入"MR"，使用内存值作为第一个操作数
            if(input == "MR") {
                num1 = memory;
                std::cout << "使用内存值: " << num1 << std::endl;
            } else {
                num1 = std::stod(input);
            }
            
            std::cin >> operation;
            std::cin >> num2;
            
            double result = calculate(num1, num2, operation);
            std::cout << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
            
            // 保存到历史记录
            addToHistory(result);
            
        } catch(const std::exception& e) {
            std::cout << "输入格式错误！" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    
    std::cout << "计算器已退出。" << std::endl;
}

// 内存相关函数
double Calculator::getMemory() const {
    return memory;
}

void Calculator::setMemory(double value) {
    memory = value;
}

void Calculator::clearMemory() {
    memory = 0.0;
}

// 历史记录相关函数
void Calculator::addToHistory(double result) {
    history.push_back(result);
}

void Calculator::showHistory() const {
    std::cout << "计算历史:" << std::endl;
    for(size_t i = 0; i < history.size(); i++) {
        std::cout << i+1 << ": " << history[i] << std::endl;
    }
}

void Calculator::clearHistory() {
    history.clear();
} 