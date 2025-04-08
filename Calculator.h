#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>

class Calculator {
private:
    double memory;               // 内存存储值
    std::vector<double> history; // 计算历史记录
    bool scientificMode;         // 科学计算器模式

public:
    // 构造函数
    Calculator();
    
    // 计算函数
    double calculate(double a, double b, char op);
    
    // 科学计算函数
    double scientificCalculate(const std::string& func, double value);
    
    // 运行计算器
    void run();
    
    // 模式切换
    void toggleScientificMode();
    bool isScientificMode() const;
    
    // 显示帮助信息
    void showHelp() const;
    void showScientificHelp() const;
    
    // 内存相关函数
    double getMemory() const;
    void setMemory(double value);
    void clearMemory();
    
    // 历史记录相关函数
    void addToHistory(double result);
    void showHistory() const;
    void clearHistory();
};

#endif // CALCULATOR_H 