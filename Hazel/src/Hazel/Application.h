#pragma once
#include "Core.h"
namespace hazel {
	class HZ_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//���������Ҫ�ڿͻ��˱����á�
	//��Ϊ�Ǻ������������Ҳ���Hazel�ж��庯�����������ﲻ��Ҫ����HZ_API��ǿ�����롣
	Application* CreateApplication();
}