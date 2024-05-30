#include "LogoutCtrl.h"
#include "assets/filework/filework.h"

void LogoutCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Filework file;
    std::string clearData = " ";
    file.setTmpData(clearData);
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
    if( req->getPath() == "/logout" )
        callback(resp);
}
