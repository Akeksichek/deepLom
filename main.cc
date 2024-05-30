#include <drogon/drogon.h>

int main()
{
    drogon::app().addListener("127.0.0.1", 9090);
    drogon::HttpAppFramework::instance().setStaticFileHeaders({{"Access-Control-Allow-Origin", "*"}});
    drogon::app().loadConfigFile("../config.json");
    drogon::app().run();
    return 0;
}
