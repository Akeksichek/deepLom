#include "RegisterCtrl.h"
#include "../models/Users.h"
#include <fstream>

void RegisterCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    std::string userData[] = {
        req->getParameter("login"),
        req->getParameter("email"),
        req->getParameter("password"),
        "user"
    };
    Password hashPass;

    std::string hash = hashPass.__hashPassword(userData[2]);
    auto clientPtr = drogon::app().getDbClient();
    clientPtr->execSqlAsync(
        "insert into users(login, email, password, role) values(?, ?, ?, ?)",
        [](const drogon::orm::Result &result) {
                                std::cout << result.size() << " rows selected!" << std::endl;
                                int i = 0;
                                for (auto row : result)
                                {
                                    std::cout << i++ << ": user name is " << row["user_name"].as<std::string>() << std::endl;
                                }
                            },
                            [](const drogon::orm::DrogonDbException &e) {
                                std::cerr << "error:" << e.base().what() << std::endl;
                            },
        userData[0], userData[1], hash, userData[3]
    );


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


    if(req->getPath() == "/signup")
        callback(resp);
    
}
