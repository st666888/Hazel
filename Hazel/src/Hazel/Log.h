#pragma once
#include "Core.h"
#include "spdlog/spdlog.h" 
#include <memory>
namespace hazel {
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
#define HZ_CORE_TRACE(...)	::hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)	::hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)	::hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)	::hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)	::hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define HZ_TRACE(...)		::hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)		::hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)		::hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)		::hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)		::hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)