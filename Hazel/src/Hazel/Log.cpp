#include "hzpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Hazel {
	//���ڷ�const��̬��Աֻ�������ⶨ�塣
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init() {
		//������־��ʾ��ʽ������ʱ�������ɫ��
		spdlog::set_pattern("%^[%T] %n: %v%$");
		//��ʼ����־��̬����,�����ͻ��˺ͺ��Ĳ��֡�
		s_CoreLogger = spdlog::stdout_color_mt("Hazel");
		s_CoreLogger->set_level(spdlog::level::trace); //������־��ʾ����Ϊ׷�٣�����������ʾ��

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace); //������־��ʾ����Ϊ׷�٣�����������ʾ��
	}
}

//������صĺ꣬�Լ���־���ú�����