#include "SignInCtrl.h"

void SignInCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    if( req->getPath() != "/signin" )
        return;
        
    const std::string email = req->getParameter("email");
    const std::string password = req->getParameter("password");
    Password unhash;
    auto clientPtr = drogon::app().getDbClient();
    auto f = clientPtr->execSqlAsyncFuture("select * from users where email=?",
                                    email);
    auto result = f.get();
        std::cout << result.size() << " rows selected!" << std::endl;
    if( (int)result.size() == 0 )
    {
        std::string html_path = "../views/pages/deci_making.html";
                std::ifstream html_file;
                auto resp = HttpResponse::newHttpResponse(k200OK, CT_TEXT_HTML);
                html_file.open(html_path, std::ios::binary);
                if(!html_file.is_open())
                {
                    resp->setStatusCode(k404NotFound);
                    resp->setBody("Что-то пошло не так");
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
        callback(resp);
        return;
    }
    else{
    try
    {
        for (auto row : result)
        {
            if( password == unhash.__unhashPassword(row["password"].as<std::string>()) )
            {   
                std::string html_path = "../views/pages/index.html";
                Filework tmp;
                std::string setTmp = row["login"].as<std::string>() + "\n" + row["email"].as<std::string>() + "\n" + row["role"].as<std::string>() + "\n";
                tmp.setTmpData(setTmp);
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
                break;
            }
            else
            {
                std::string html_path = "../views/pages/deci_making.html";

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
                break;
            }
        }
    }
    catch (const drogon::orm::DrogonDbException &e)
    {
        std::cerr << "error:" << e.base().what() << std::endl;
    }
    }
}

