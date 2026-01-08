#pragma once
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>
#include <iostream>
#include "http_connection.h"

namespace net = boost::asio;
namespace beast = boost::beast;
using tcp = net::ip::tcp;

// 前置声明
class http_connection;

class httpserver {
public:
    // 构造函数
    httpserver(net::io_context& ioc, unsigned short port)
        : acceptor_(ioc, tcp::endpoint(tcp::v4(), port))
        , socket_(ioc) {
    }

    // 开始服务器
    void start() {
        do_accept();
    }

    // 停止服务器
    void stop() {
        boost::system::error_code ec;
        acceptor_.close(ec);
        socket_.close(ec);
    }

    // 获取端口号
    unsigned short port() const {
        return acceptor_.local_endpoint().port();
    }

    // 检查服务器是否运行
    bool is_running() const {
        return acceptor_.is_open();
    }

private:
    void do_accept() {
        acceptor_.async_accept(socket_, [this](boost::system::error_code ec) {
            if (!ec) {
                // 创建连接并开始处理
                std::make_shared<http_connection>(std::move(socket_))->start();
            }

            // 继续接受下一个连接（无论是否出错）
            do_accept();
            });
    }

    tcp::acceptor acceptor_;
    tcp::socket socket_;
};