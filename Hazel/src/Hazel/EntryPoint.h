/*
���������ͷ�ļ��������������ڸ�ͷ�ļ��У��ڿͻ��˰�����ͷ�ļ���
�ڱ��ļ���������һ��hazel::CreateAppliaction()���������������Ҫ�ڿͻ��˱�������

����ļ��еı�����ȥ��ᣬ����ļ����ջᱻ�����ڿͻ����У����ͻ���һ��������ú���������ͷ�ļ��������Ҳ���hazel�����ռ䲻Ҫ����
*/
#pragma once
#ifdef  HZ_PLATFORM_WINDOWS
extern hazel::Application* hazel::CreateApplication();
int main(int argc,char** argv) {

	printf("Hello Hazel!\n");
	auto app = hazel::CreateApplication();
	app->Run();

}
#endif //HZ_PLATFORM_WINDOWS
