#include <node.h>
using v8::Array;
using v8::Function;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::Value;
using v8::Context;
using v8::FunctionCallbackInfo;
using v8::String;
using v8::Exception;

void QuickSort(int *arr, int left, int right) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i <= j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }
  if (left < j) {
    QuickSort(arr, left, j);
  }
  if (i < right) {
    QuickSort(arr, i, right);
  }
}

void QuickSortWrapper(const  FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  // 转换成c++中的array
  Local<Array> jsArray = Local<Array>::Cast(args[0]);
  int len = jsArray->Length();
  int *arr = new int[len];
  for (int i = 0; i < len; i++) {
    // FromMaybe(0)若转换失败则返回0，从而确保返回的值类型为v8::Local<int>而不是v8::Maybe<int>
    arr[i] = jsArray->Get(context, i).ToLocalChecked()->Int32Value(context).FromMaybe(0);
  }
  QuickSort(arr, 0, len - 1);

  //把排序好的数组转成js里的array
  Local<Array> result = Array::New(isolate);
  for (int i = 0; i < len; i++) {
    result->Set(context,i, Number::New(isolate, arr[i]));
  }

  args.GetReturnValue().Set(result);

  delete[] arr;
}

void hello(const FunctionCallbackInfo<Value> &args) {
 Isolate *isolate = args.GetIsolate();
 auto message = String::NewFromUtf8(isolate, "Hello World!");
 args.GetReturnValue().Set(message.ToLocalChecked());
}

void sum(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();

 double sum = args[0]->ToNumber(context).ToLocalChecked()->Value() + args[1]->ToNumber(context).ToLocalChecked()->Value();
  args.GetReturnValue().Set(Number::New(isolate, sum));
}



void Initialize(Local<Object> exports) {
 NODE_SET_METHOD(exports, "hello", hello);
 NODE_SET_METHOD(exports, "sum", sum);
 NODE_SET_METHOD(exports, "quickSort", QuickSortWrapper);
}

NODE_MODULE(module_name, Initialize)