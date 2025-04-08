#include "Calculator.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// 构造函数
Calculator::Calculator() : memory(0.0), scientificMode(false) {
}

// 基本计算函数
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

// 科学计算函数
double Calculator::scientificCalculate(const std::string& func, double value) {
    if (func == "sin") {
        return sin(value);
    } else if (func == "cos") {
        return cos(value);
    } else if (func == "tan") {
        return tan(value);
    } else if (func == "asin") {
        if (value >= -1 && value <= 1) {
            return asin(value);
        } else {
            std::cout << "错误：asin的参数必须在[-1,1]范围内!" << std::endl;
            return 0;
        }
    } else if (func == "acos") {
        if (value >= -1 && value <= 1) {
            return acos(value);
        } else {
            std::cout << "错误：acos的参数必须在[-1,1]范围内!" << std::endl;
            return 0;
        }
    } else if (func == "atan") {
        return atan(value);
    } else if (func == "log") {
        if (value > 0) {
            return log10(value);
        } else {
            std::cout << "错误：log的参数必须大于0!" << std::endl;
            return 0;
        }
    } else if (func == "ln") {
        if (value > 0) {
            return log(value);
        } else {
            std::cout << "错误：ln的参数必须大于0!" << std::endl;
            return 0;
        }
    } else if (func == "sqrt") {
        if (value >= 0) {
            return sqrt(value);
        } else {
            std::cout << "错误：sqrt的参数必须大于等于0!" << std::endl;
            return 0;
        }
    } else if (func == "exp") {
        return exp(value);
    } else if (func == "abs") {
        return fabs(value);
    } else if (func == "rad") {
        // 将角度转换为弧度
        return value * M_PI / 180.0;
    } else if (func == "deg") {
        // 将弧度转换为角度
        return value * 180.0 / M_PI;
    } else {
        std::cout << "不支持的函数: " << func << std::endl;
        return 0;
    }
}

// 切换科学计算器模式
void Calculator::toggleScientificMode() {
    scientificMode = !scientificMode;
    if (scientificMode) {
        std::cout << "已切换到科学计算器模式" << std::endl;
    } else {
        std::cout << "已切换到基本计算器模式" << std::endl;
    }
}

// 获取当前模式
bool Calculator::isScientificMode() const {
    return scientificMode;
}

// 显示基本帮助信息
void Calculator::showHelp() const {
    std::cout << "\n==== 高级计算器 ====\n";
    std::cout << "支持的操作: +, -, *, /, %, ^\n";
    std::cout << "特殊命令:\n";
    std::cout << "  M 查看内存值\n";
    std::cout << "  MS 将结果存入内存\n";
    std::cout << "  MC 清除内存\n";
    std::cout << "  MR 调用内存值作为运算数\n";
    std::cout << "  H 查看历史记录\n";
    std::cout << "  C 清除历史记录\n";
    std::cout << "  HELP 显示帮助信息\n";
    std::cout << "  SCI 切换到科学计算器模式\n";
    std::cout << "  Q 退出计算器\n";
}

// 显示科学计算器帮助信息
void Calculator::showScientificHelp() const {
    std::cout << "\n==== 科学计算器模式 ====\n";
    std::cout << "支持的函数:\n";
    std::cout << "  sin(x) - 正弦函数\n";
    std::cout << "  cos(x) - 余弦函数\n";
    std::cout << "  tan(x) - 正切函数\n";
    std::cout << "  asin(x) - 反正弦函数\n";
    std::cout << "  acos(x) - 反余弦函数\n";
    std::cout << "  atan(x) - 反正切函数\n";
    std::cout << "  log(x) - 常用对数(底数10)\n";
    std::cout << "  ln(x) - 自然对数\n";
    std::cout << "  sqrt(x) - 平方根\n";
    std::cout << "  exp(x) - e的x次方\n";
    std::cout << "  abs(x) - 绝对值\n";
    std::cout << "  rad(x) - 角度转弧度\n";
    std::cout << "  deg(x) - 弧度转角度\n";
    std::cout << "输入格式: [函数名] [值]\n";
    std::cout << "示例: sin 30\n";
    std::cout << "输入 BASIC 返回基本计算器模式\n";
}

// 运行计算器
void Calculator::run() {
    double num1, num2;
    char operation;
    bool running = true;
    std::string input;

    // 显示帮助信息
    showHelp();

    while(running) {
        if (scientificMode) {
            std::cout << "\n[科学模式] 请输入函数和值(或命令): ";
        } else {
            std::cout << "\n请输入计算表达式或命令: ";
        }
        
        std::cin >> input;
        
        // 处理特殊命令
        if(input == "Q" || input == "q") {
            running = false;
            break;
        } else if(input == "HELP" || input == "help") {
            if (scientificMode) {
                showScientificHelp();
            } else {
                showHelp();
            }
            continue;
        } else if(input == "SCI" || input == "sci") {
            toggleScientificMode();
            if (scientificMode) {
                showScientificHelp();
            }
            continue;
        } else if(input == "BASIC" || input == "basic") {
            if (scientificMode) {
                toggleScientificMode();
            }
            continue;
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
        
        try {
            double result;
            
            if (scientificMode) {
                // 科学计算器模式
                double value;
                if (input == "MR") {
                    value = memory;
                    std::cout << "使用内存值: " << value << std::endl;
                    std::cin >> input;  // 获取函数名
                } else {
                    std::cin >> value;  // 获取参数值
                }
                
                result = scientificCalculate(input, value);
                std::cout << input << "(" << value << ") = " << std::setprecision(10) << result << std::endl;
            } else {
                // 基本计算器模式
                if (input == "MR") {
                    num1 = memory;
                    std::cout << "使用内存值: " << num1 << std::endl;
                } else {
                    num1 = std::stod(input);
                }
                
                std::cin >> operation;
                std::cin >> num2;
                
                result = calculate(num1, num2, operation);
                std::cout << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
            }
            
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