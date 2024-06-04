#include "testAuthCtrl.h"
#include <fstream>
#include "assets/hashing/hashingPass.h"
#include "assets/filework/filework.h"
#include "assets/user_data/user_data_tmp.cpp"

void testAuthCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    if( req->getPath() != "/test_auth" )
        return;

    const std::string login = req->getParameter("login");
    const std::string password = req->getParameter("password");
    Password unhash;
    Filework tmp;

    Json::Value json;



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
                std::string data = row["login"].as<std::string>() + '\n' +
                row["email"].as<std::string>() + "\n" +
                row["role"].as<std::string>() + '\n';

                // tmp.setDefPath(row["id"].as<std::string>());
                std::cout << data << std::endl;
                tmp.setTmpData(data);
                std::cout << tmp.getTmpData();

                // user_data user_dataOBJ;
                // user_dataOBJ.login = row["login"].as<std::string>();
                // user_dataOBJ.email = row["email"].as<std::string>();
                // user_dataOBJ.role = row["role"].as<std::string>();

                
                // std::cout << "\n| user data |" << user_dataOBJ.get_userData() << "\n| user data |\n\n";

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
                break;
            }
            else
                json["msg"] = "Password not fit";
        }
    }
    catch (const drogon::orm::DrogonDbException &e)
    {
        std::cerr << "error:" << e.base().what() << std::endl;
        auto resp = HttpResponse::newHttpResponse(k404NotFound, CT_TEXT_HTML);
    }

}
