#include <iostream>
#include <fstream>

int main() {
    std::ifstream pipe("mypipe");   // 打开 FIFO 管道（读端）

    if (!pipe.is_open()) {
        std::cerr << "无法打开管道！" << std::endl;
        return -1;
    }

    int value;

    while (pipe >> value) {
        std::cout << "接收到：" << value << std::endl;
    }

    return 0;
}