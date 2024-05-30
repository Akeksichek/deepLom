#include "SessionUserCtrl.h"
#include <fstream>
#include "assets/filework/filework.h"

void SessionUserCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
    Json::Value json;
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
    std::cout << "\nuser_data[" << user_data[0] << ", " << user_data[1] << ", " << user_data[2] << "];\n" << std::endl;

    json["login"] = user_data[0];
    json["email"] = user_data[1];
    json["role"] = user_data[2];


    auto resp = HttpResponse::newHttpJsonResponse(json);
    if( req->getPath() == "/save" )
        callback(resp);
}
