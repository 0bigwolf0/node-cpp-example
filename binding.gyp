{
  "targets": [
    {
      "target_name": "test1",
      "sources": [ "test1.cpp" ]
    },
    {
      "target_name": "test2",
      "sources": [ "test2.cpp" ],
    },
    {
      "target_name": "test3",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "test3.cpp" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
