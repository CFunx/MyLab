#include "Observer.h"
#include <cassert>

namespace nsObserver
{
	ObserverA::ObserverA(std::string strName)
		:m_strName(strName)
	{

	}

	ObserverA::~ObserverA() = default;


	std::string ObserverA::GetName()
	{
		return m_strName;
	}

	void ObserverA::Excute(std::string strMsg)
	{
		std::cout << "I am " << m_strName.c_str() << "; now reciving msg is "
			<< strMsg.c_str() << std::endl;
	}


	ObjectA::ObjectA(std::string strName)
		: m_strName(strName)
	{

	}

	ObjectA::~ObjectA()
	{
		m_observers.clear();
	}

	
	void ObjectA::Register(IObserver* observer)
	{
		assert(nullptr != observer);
		std::string strName = observer->GetName();
		m_observers.insert(std::pair<std::string, IObserver*>(strName, observer));
	}

	void ObjectA::Notify(std::string strMsg)
	{
		for (const auto& it : m_observers)
		{
			it.second->Excute(strMsg);
		}
	}

	void ObjectA::UnRegister(IObserver* observer)
	{
		assert(nullptr != observer);
		std::string strName = observer->GetName();

		auto it = m_observers.find(strName);

		if (it != m_observers.end())
		{
			m_observers.erase(it);
		}
	}

	void TestObserver()
	{
		//!  创建被观察的对象
		IObject* obj = new ObjectA("ObjA");

		//! 创建观察者
		IObserver* obsvrA = new ObserverA("obsvrA");
		IObserver* obsvrB = new ObserverA("obsvrB");


		//!注册观察者
		obj->Register(obsvrA);
		obj->Register(obsvrB);

		//! 通知信息
		obj->Notify("Hi,are you ok!");


		//! 注销注册
		obj->UnRegister(obsvrB);

		obj->Notify("Ok! ok!");

		delete obsvrA;
		obsvrA = nullptr;

		delete obsvrB;
		obsvrB = nullptr;

		delete obj;
		obj = nullptr;
	}
}
