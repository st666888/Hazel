/*
���������ͷ�ļ��������������ڸ�ͷ�ļ��У��ڿͻ��˰�����ͷ�ļ���
�ڱ��ļ���������һ��hazel::CreateAppliaction()���������������Ҫ�ڿͻ��˱�������

����ļ��еı�����ȥ��ᣬ����ļ����ջᱻ�����ڿͻ����У����ͻ���һ��������ú���������ͷ�ļ��������Ҳ���hazel�����ռ䲻Ҫ����
*/
#pragma once
#ifdef  HZ_PLATFORM_WINDOWS
#include "Log.h"
extern hazel::Application* hazel::CreateApplication();
int main(int argc,char** argv) {
	//����
	hazel::Log::Init();
	HZ_CORE_WARN("Initialized log!");
	int a = 5;
	HZ_INFO("hello! Var={0}",a);

	auto app = hazel::CreateApplication();
	app->Run();

}
#endif //HZ_PLATFORM_WINDOWS
