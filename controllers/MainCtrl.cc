#include "MainCtrl.h"
#include <fstream>
#include "assets/user_data/user_data_tmp.cpp"

std::string MAIN_PATH = "../views/pages/";
void MainCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    if( req->getPath() == "/" )
    {
        std::string html_path = MAIN_PATH + "index.html";
        auto resp = HttpResponse::newHttpResponse(k200OK, CT_TEXT_HTML);
        std::ifstream html_file;
        html_file.open(html_path, std::ios::binary);
        if(!html_file.is_open())
        {
            resp->setStatusCode(k404NotFound);
            resp->setBody("Подключение не удалось");
            return;
        }

        html_file.seekg(0, std::ios::end);
        size_t fileSize = html_file.tellg();
        html_file.seekg(0, std::ios::beg);

        auto buffer = std::make_unique<char[]>(fileSize);
        html_file.read(buffer.get(), fileSize);
        html_file.close();
        resp->setBody(buffer.get());
        user_data user_dataOBJ;
        std::cout << "\n| user data |" << user_dataOBJ.get_userData() << "\n| user data |\n\n";
        callback(resp);
    }
    else if( req->getPath() == "/create_order" )
    {
        std::string html_path = MAIN_PATH + "createOrder.html";
        auto resp = HttpResponse::newHttpResponse(k200OK, CT_TEXT_HTML);
        std::ifstream html_file;
        html_file.open(html_path, std::ios::binary);
        if(!html_file.is_open())
        {
            resp->setStatusCode(k404NotFound);
            resp->setBody("Подключение не удалось");
            return;
        }

        html_file.seekg(0, std::ios::end);
        size_t fileSize = html_file.tellg();
        html_file.seekg(0, std::ios::beg);

        auto buffer = std::make_unique<char[]>(fileSize);
        html_file.read(buffer.get(), fileSize);
        html_file.close();
        resp->setBody(buffer.get());

        callback(resp);
    }
    else if( req->getPath() == "/equipment" )
    {
        std::string html_path = MAIN_PATH + "equipment.html";
        auto resp = HttpResponse::newHttpResponse(k200OK, CT_TEXT_HTML);
        std::ifstream html_file;
        html_file.open(html_path, std::ios::binary);
        if(!html_file.is_open())
        {
            resp->setStatusCode(k404NotFound);
            resp->setBody("Подключение не удалось");
            return;
        }

        html_file.seekg(0, std::ios::end);
        size_t fileSize = html_file.tellg();
        html_file.seekg(0, std::ios::beg);

        auto buffer = std::make_unique<char[]>(fileSize);
        html_file.read(buffer.get(), fileSize);
        html_file.close();
        resp->setBody(buffer.get());

        callback(resp);
    }
}