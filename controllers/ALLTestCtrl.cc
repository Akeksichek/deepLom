#include "ALLTestCtrl.h"
#include "assets/filework/filework.h"

void ALLTestCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    //для тестов



    // history_list
    

    Filework data;
    std::string tmp = data.getTmpData();
    std::cout << "tmp: " << tmp << std::endl;
    const int SIZE = 3;
    std::string user_data[SIZE];
    int iterator = 0;

    for( int i = 0; i < SIZE; )
    {
        for( auto &a : tmp )
        {
            if( a == '|' )
            {
                i++;
                continue;
            }
            user_data[i] += a;
        }
    }

    Json::Value json;
    Json::Value history_row;
    Json::Value history_list(Json::arrayValue);
    auto clientPtr = drogon::app().getDbClient();
    auto f = clientPtr->execSqlAsyncFuture("select * from orders where user_email=?", user_data[1]);
    auto result = f.get();
    std::cout << result.size() << " rows selected\n";
    for( auto row: result )
    {
        history_row["category"] = row["category_title"].as<std::string>();
        history_row["time"] = row["order_time"].as<std::string>();
        history_list.append(history_row);
    }
    json["history_list"] = history_list;

    auto resp = HttpResponse::newHttpJsonResponse(json);
    // history_list


    if( req->getPath() == "/history" )
        callback(resp);
}
