#pragma once
/*
����ļ�����˼�ǣ����������HZ_PLATFORM_WINDOWS���Ҷ�����HZ_BUILD_DLL����ôHZ_API�ǽ����еĺ������ർ��
���û�ж���HZ_BUILD_DLL����ô�ǽ����еĺ������ർ�룬�������ǿ�����Hazel��Sandbox���Զ�ʹ�õ��뵼�����ܡ�
��Hazel�ж���HZ_PLATFORM_WINDOWS��HZ_BUILD_DLL����SandBox�н�������HZ_PLATFORM_WINDOWS���ɡ�
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

