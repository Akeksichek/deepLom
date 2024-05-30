#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class MainCtrl : public drogon::HttpSimpleController<MainCtrl>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
      PATH_ADD("/", Get);
      PATH_ADD("/create_order", Get);
      PATH_ADD("/equipment", Get);
    PATH_LIST_END
};
