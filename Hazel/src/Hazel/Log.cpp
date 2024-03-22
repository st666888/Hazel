#include "hzpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Hazel {
	//类内非const静态成员只能在类外定义。
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init() {
		//设置日志显示格式，包括时间戳，颜色等
		spdlog::set_pattern("%^[%T] %n: %v%$");
		//初始化日志静态变量,包括客户端和核心部分。
		s_CoreLogger = spdlog::stdout_color_mt("Hazel");
		s_CoreLogger->set_level(spdlog::level::trace); //设置日志显示级别为追踪，基本都会显示。

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace); //设置日志显示级别为追踪，基本都会显示。
	}
}

//定义相关的宏，以简化日志调用函数。