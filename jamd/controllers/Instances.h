#pragma once

#include <drogon/HttpAppFramework.h>
#include <spdlog/spdlog.h>

#include "../modules/manager/InstanceManager/InstanceManager.h"

#include "../structs/api.h"
#include "../ext/extFuns.h"
#include "../ext/marcos.h"

using namespace drogon;
using InstanceManager = jamd::managers::InstanceManager;
using jamd::structs::api::instances::LaunchResult;

class Instances final : public HttpController<Instances>
{
public:
    METHOD_LIST_BEGIN
        GET("/start?instance={1:id|name}", Instances::StartInstance)
    METHOD_LIST_END

    // 使用协程来处理请求
    static void StartInstance(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr&)>&& callback,
                              const String& target);
};
