#pragma once
#include "Core.h"
#include "spdlog/spdlog.h" 
#include "spdlog/fmt/ostr.h" //添加spdlog的输出流操作符
#include <memory>
namespace Hazel {
class HZ_API Log
{
public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

}
//定义部分可用宏，本例中__VA_ARGS__是将传递给宏的参数依次展开，可以接收多个参数。
//在命名空间前面加上::表示全局的命名空间，防止使用到局部的命名空间中的变量或函数。
#define HZ_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)	::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)	::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)	::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define HZ_TRACE(...)		::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)		::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)		::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)		::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)		::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)