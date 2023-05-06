#include <node_api.h>

napi_value hello(napi_env env, napi_callback_info info)
{
    napi_value result;

    napi_create_string_utf8(env, "Hello World!", NAPI_AUTO_LENGTH, &result);

    return result;
}

napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc = {"hello", NULL, hello, NULL, NULL, NULL, napi_default, NULL};

    napi_define_properties(env, exports, 1, &desc);

    return exports;
}

NAPI_MODULE(module_name, Init)