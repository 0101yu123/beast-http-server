// beast-http.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "http_connection.h"
#include "http_server.h"
int main()
{
    try {
        net::io_context ioc;

        // 创建HTTP服务器实例，监听8080端口
        httpserver server(ioc, 8080);

        // 开始服务器
        server.start();

        std::cout << "HTTP服务器运行在端口: " << server.port() << std::endl;

        // 运行IO上下文
        ioc.run();
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
    }
}


