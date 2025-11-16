#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
    std::ofstream pipe("mypipe");   // 打开 FIFO 管道（写端）
    if (!pipe.is_open()) {
        std::cerr << "无法打开管道！" << std::endl;
        return -1;
    }

    int value = 0;

    while (true) {
        pipe << value << std::endl;    // 把数据写入管道
        pipe.flush();                   // 立刻发送
        std::cout << "发送：" << value << std::endl;

        value++;                        // 自增模拟实时数据
        usleep(500000);                 // 0.5秒发送一次
    }
}