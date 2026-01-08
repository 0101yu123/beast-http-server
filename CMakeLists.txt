cmake_minimum_required(VERSION 3.12)
project(BeastHttpServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Boost库
find_package(Boost 1.70 REQUIRED COMPONENTS system)

# 可执行文件
add_executable(beast-http-server
    src/main.cpp
    src/http_connection.cpp
    src/http_server.cpp
)

# 包含目录
target_include_directories(beast-http-server PRIVATE include)
target_include_directories(beast-http-server SYSTEM PRIVATE 
    # 这里需要根据实际情况设置Boost路径
    # 例如: /usr/include/boost 或 C:/boost/include/boost-1_78
)

# 链接库
target_link_libraries(beast-http-server PRIVATE Boost::system)