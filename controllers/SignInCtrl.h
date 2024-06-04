#pragma once

#include <drogon/HttpSimpleController.h>
#include "assets/hashing/hashingPass.h"
#include <fstream>
#include "assets/filework/filework.h"

using namespace drogon;

class SignInCtrl : public drogon::HttpSimpleController<SignInCtrl>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
    // PATH_ADD("/path", "filter1", "filter2", HttpMethod1, HttpMethod2...);
    PATH_ADD("/signin", Post);
    PATH_LIST_END
};
