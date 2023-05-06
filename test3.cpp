#include <napi.h>
using Napi::Env;
using Napi::Function;
using Napi::String;
using Napi::Object;
using Napi::CallbackInfo;

String Method(const CallbackInfo& info) {
  Env env = info.Env();
  return String::New(env, "Hello World!");
}

Object Init(Env env, Object exports) {
  exports.Set(String::New(env, "hello"),
              Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(module_name, Init)