#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class OrderCtrl : public drogon::HttpSimpleController<OrderCtrl>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
      PATH_ADD("/order_conf", Post);
    PATH_LIST_END
};
