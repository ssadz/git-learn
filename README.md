# Git 学习项目

这是一个用于学习Git的C++项目。

## 功能
- 打印欢迎信息
- 高级计算器，支持以下功能：
  - 基本四则运算（加减乘除）
  - 百分比计算
  - 幂运算
  - 内存功能（存储、调用、清除）
  - 计算历史记录

## 项目结构
- `main.cpp` - 主程序入口
- `Welcome.h/cpp` - 欢迎功能模块
- `Calculator.h/cpp` - 计算器功能模块
- `CMakeLists.txt` - CMake构建配置文件

## 编译方法
使用CMake:
```bash
mkdir build
cd build
cmake ..
make
```

或直接使用g++:
```bash
g++ -o calculator main.cpp Welcome.cpp Calculator.cpp
```

## 运行方法
```bash
./calculator
```

## 计算器使用说明
1. 启动程序后，按提示输入表达式或命令
2. 支持的操作符: 
   - `+` 加法
   - `-` 减法
   - `*` 乘法
   - `/` 除法
   - `%` 百分比
   - `^` 幂运算
3. 特殊命令:
   - `M` 查看内存值
   - `MS` 将最近的结果存入内存
   - `MC` 清除内存
   - `MR` 调用内存值作为运算数
   - `H` 查看历史记录
   - `C` 清除历史记录
   - `Q` 退出计算器 