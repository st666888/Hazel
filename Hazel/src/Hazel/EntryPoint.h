/*
���������ͷ�ļ��������������ڸ�ͷ�ļ��У��ڿͻ��˰�����ͷ�ļ���
�ڱ��ļ���������һ��hazel::CreateAppliaction()���������������Ҫ�ڿͻ��˱�������

����ļ��еı�����ȥ��ᣬ����ļ����ջᱻ�����ڿͻ����У����ͻ���һ��������ú���������ͷ�ļ��������Ҳ���hazel�����ռ䲻Ҫ����
*/
#pragma once
#ifdef  HZ_PLATFORM_WINDOWS
#include "Log.h"
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc,char** argv) {
	//����
	Hazel::Log::Init();
	auto app = Hazel::CreateApplication();
	app->Run();

}
#endif //HZ_PLATFORM_WINDOWS
