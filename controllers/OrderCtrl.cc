#include "OrderCtrl.h"
#include <fstream>

void OrderCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    const std::string f_email = req->getParameter("email");
    const std::string f_category = req->getParameter("category");
    const std::string f_datetime = req->getParameter("datetime");
    std::cout << f_datetime << std::endl;

    auto resp = HttpResponse::newHttpResponse(k200OK, CT_TEXT_HTML);
    auto clientPtr = drogon::app().getDbClient();
    clientPtr->execSqlAsync(
        "insert into orders(category_title, user_email, order_time) values(?, ?, ?)", 
        []( const drogon::orm::Result &result )
        {
            std::cout << result.size() << " rows selected!" << std::endl;
                                int i = 0;
                                for (auto row : result)
                                {
                                    std::cout << i++ << ": user name is " << row["user_name"].as<std::string>() << std::endl;
                                }
        },
        []( const drogon::orm::DrogonDbException &e ){
            std::cout << e.base().what();
        },
        f_category, f_email, f_datetime
    );

    std::string view_path = "../views/pages/deci_making.html";
    std::ifstream view_open;
    view_open.open(view_path, std::ios::binary);
    if( !view_open.is_open() )
        std::cout << "Не удалось подключиться\n";
    view_open.seekg(0, std::ios::end);
    size_t file_size = view_open.tellg();
    view_open.seekg(0, std::ios::beg);
    auto buffer = std::make_unique<char[]>(file_size);
    view_open.read(buffer.get(), file_size);
    view_open.close();
    resp->setBody(buffer.get());

    if( req->getPath() == "/order_conf" )
        callback(resp);
}
