#pragma once
#include "Core.h"
#include "Events/Event.h"
namespace Hazel {
	class HZ_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//这个函数需要在客户端被调用。
	//因为是函数声明，而且不在Hazel中定义函数，所以这里不需要调用HZ_API来强调导入。
	Application* CreateApplication();
}