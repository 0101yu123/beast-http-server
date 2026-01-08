# Beast HTTP Server

一个基于Boost.Beast的HTTP服务器示例。

## 编译运行

### 依赖
-Boost(1.70或更高版本)
-CMake(3.12或更高版本)

### 编译

mkdir build
cd build
cmake ..
make

### 运行

./beast-http-server
服务器将运行在8080端口。

### 功能

支持GET请求
支持POST请求处理JSON数据
请求计数功能
连接超时管理

### 文件结构

beast-http-server/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── http_connection.h
│   └── http_server.h
└── src/
    ├── main.cpp
    ├── http_connection.cpp
    └── http_server.cpp