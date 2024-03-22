/*
定义主入口头文件。将主函数放在该头文件中，在客户端包含该头文件后，
在本文件中引入了一个hazel::CreateAppliaction()函数，这个函数需要在客户端被创建。

这个文件中的报错不用去理会，这个文件最终会被包含在客户端中，而客户端一定会包含该函数的声明头文件。这里找不到hazel命名空间不要紧。
*/
#pragma once
#ifdef  HZ_PLATFORM_WINDOWS
#include "Log.h"
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc,char** argv) {
	//测试
	Hazel::Log::Init();
	auto app = Hazel::CreateApplication();
	app->Run();

}
#endif //HZ_PLATFORM_WINDOWS
