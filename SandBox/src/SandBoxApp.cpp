#include <iostream>
#include <Hazel.h>
class SandBox : public Hazel::Application {
public:
	SandBox() {

	};
	~SandBox() {

	};
};
//只需要在当前客户端程序中实现这个函数
//这个函数实现后，因为#include <Hazel.h>相当与包含了EntryPoint.h将主函数包含了进来，主函数会调用
//auto app = hazel::CreateApplication();
//app->Run(); 来运行程序。
//工作完成后，实现了主函数的实际在Hazel引擎之中，客户端只负责实现CreateApplication()函数即可。
Hazel::Application* Hazel::CreateApplication(){return new SandBox();}
