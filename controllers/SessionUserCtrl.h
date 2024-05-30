#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class SessionUserCtrl : public drogon::HttpSimpleController<SessionUserCtrl>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
    PATH_ADD("/save", Get);
    PATH_LIST_END
};
