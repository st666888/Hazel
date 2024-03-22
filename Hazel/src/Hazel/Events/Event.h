#pragma once
#include "hzpch.h"
#include "Hazel/Core.h"


namespace Hazel {
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};
	//##type����˼����ȡ�������type���Ʊ������뵽����λ�á�
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type;}\
									virtual EventType GetEventType() const override {return GetStaticType();}\
									virtual const char* GetName() const override {return #type;}
	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}
	class HZ_API Event
	{
		friend class EventDispatcher;
		public:
			virtual EventType GetEventType() const = 0;
			virtual const char* GetName() const = 0;
			virtual int GetCategoryFlags() const = 0;
			virtual std::string ToString() const { return GetName();}

		inline bool IsInCategory(EventCategory category){

			return GetCategoryFlags() & category;
		
		}

		protected:
			bool m_Handled = false;

	};

	//�¼������ࡣ
	class EventDispatcher {
		//����using�������ǣ�������typedef,Ϊstd::function<bool(T&)>���ֺ������󴴽��������൱��Ϊ������󴴽���������
		//�˺󴴽����ֺ��������ʱ�򣬿���ʹ��EventFn<T> xxx�ķ�ʽ�����С�������Ҫstd::function<bool(T&)> xxx�ķ�ʽ��
		//std::function�������ǣ�������ֵ�����Լ������б���ͬ��һ�ຯ����Ϊһ����������ʾ�������԰�װ��ͨ����,����ָ�룬lambda���ʽ�ȡ�
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) :m_Event(event) {

		}
		template<typename T>
		bool Dispatch(EventFn<T> func) {  
			if (m_Event.GetEventType() == T::GetStaticType()) {
				//*(T*)&m_Event ��������ǣ������ǰ���¼�����ƥ�䣬�򽫵�ǰ�¼�ȡ��ַ,����ת���ɶ�Ӧʵ�����͵�ָ�룬Ȼ�������
				//ȡ�����¼�ʵ����������������ݸ�func������
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}