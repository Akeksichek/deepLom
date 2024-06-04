#pragma once

#include <drogon/HttpSimpleController.h>
#include <fstream>

using namespace drogon;

class ALLTestCtrl : public drogon::HttpSimpleController<ALLTestCtrl>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
      PATH_ADD("/history", Get);
    PATH_LIST_END
};
