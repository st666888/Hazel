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
	//##type的意思就是取到传入的type名称本身并插入到代码位置。
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

	//事件调度类。
	class EventDispatcher {
		//这里using的作用是，类似与typedef,为std::function<bool(T&)>这种函数对象创建别名，相当于为这类对象创建了类名。
		//此后创建这种函数对象的时候，可以使用EventFn<T> xxx的方式来进行。而不需要std::function<bool(T&)> xxx的方式。
		//std::function的作用是，将返回值类型以及参数列表相同的一类函数作为一种类型来表示。它可以包装普通函数,函数指针，lambda表达式等。
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) :m_Event(event) {

		}
		template<typename T>
		bool Dispatch(EventFn<T> func) {  
			if (m_Event.GetEventType() == T::GetStaticType()) {
				//*(T*)&m_Event 这个含义是，如果当前的事件类型匹配，则将当前事件取地址,将他转换成对应实际类型的指针，然后解引用
				//取到该事件实体对象本身当作参数传递给func方法。
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