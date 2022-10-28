#pragma once

#ifdef BUILD_DLL
#define RENDERKING_API __declspec(dllexport)
#else
#define RENDERKING_API __declspec(dllimport)
#endif // BUILD_DLL

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)