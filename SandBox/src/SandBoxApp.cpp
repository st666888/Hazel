#include <iostream>
#include <Hazel.h>
class SandBox : public Hazel::Application {
public:
	SandBox() {

	};
	~SandBox() {

	};
};
//ֻ��Ҫ�ڵ�ǰ�ͻ��˳�����ʵ���������
//�������ʵ�ֺ���Ϊ#include <Hazel.h>�൱�������EntryPoint.h�������������˽����������������
//auto app = hazel::CreateApplication();
//app->Run(); �����г���
//������ɺ�ʵ������������ʵ����Hazel����֮�У��ͻ���ֻ����ʵ��CreateApplication()�������ɡ�
Hazel::Application* Hazel::CreateApplication(){return new SandBox();}
