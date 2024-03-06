#pragma once
/*
这个文件的意思是，如果定义了HZ_PLATFORM_WINDOWS，且定义了HZ_BUILD_DLL，那么HZ_API是将所有的函数或类导出
如果没有定义HZ_BUILD_DLL，那么是将所有的函数和类导入，这样我们可以在Hazel和Sandbox中自动使用导入导出功能。
在Hazel中定义HZ_PLATFORM_WINDOWS和HZ_BUILD_DLL，在SandBox中仅仅定义HZ_PLATFORM_WINDOWS即可。
*/
#ifdef HZ_PLATFORM_WINDOWS
	#ifdef  HZ_BUILD_DLL
		#define HZ_API __declspec(dllexport)
	#else 
		#define HZ_API __declspec(dllimport)
	#endif 
#else
#error HAZEL IS BUILD FOR WINDOWS!
#endif

