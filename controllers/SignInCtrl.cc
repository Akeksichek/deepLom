#include "SignInCtrl.h"
#include "models/Users.h"
#include <fstream>

void SignInCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    if( req->getPath() != "/test_auth" )
        return;
        
    const std::string login = req->getParameter("login");
    const std::string password = req->getParameter("password");
    Password unhash;

    Json::Value json;
    json["status"] = "Пользователь не найден";

    auto clientPtr = drogon::app().getDbClient();
    auto f = clientPtr->execSqlAsyncFuture("select * from users where login=?",
                                    login);
    try
    {
        auto result = f.get();
        std::cout << result.size() << " rows selected!" << std::endl;
        int i = 0;
        for (auto row : result)
        {
            if( password == unhash.__unhashPassword(row["password"].as<std::string>()) )
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
            else
                json["msg"] = "Password not fit";
        }
    }
    catch (const drogon::orm::DrogonDbException &e)
    {
        std::cerr << "error:" << e.base().what() << std::endl;
        json["auth_conf"] = "1";
        
    }

    // auto resp = HttpResponse::newHttpJsonResponse(json);
    // if( req->getPath() == "/test_auth" )
    // {
    //             callback(resp);
    // }
}

