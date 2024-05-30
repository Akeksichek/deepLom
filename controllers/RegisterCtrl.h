#pragma once

#include <drogon/HttpSimpleController.h>
#include "assets/hashing/hashingPass.h"

using namespace drogon;

class RegisterCtrl : public drogon::HttpSimpleController<RegisterCtrl>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
      PATH_ADD("/signup", Post);
    PATH_LIST_END
};

