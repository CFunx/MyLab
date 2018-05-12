#pragma once
#include <iostream>
#include <string>
#include <map>


/**
	观察者模式就是在一个对象的状态发生改变之后，让其他依赖于此类的对象能够察觉到其变化
	并且能够根据变化做出相应的动作
*/

namespace nsObserver
{
	//! 观察者
	class IObserver
	{
	public:
		virtual std::string GetName() = 0;
		 virtual void Excute(std::string strMsg) = 0;
	};

	class ObserverA : public IObserver
	{
	public:
		ObserverA(std::string strName);
		~ObserverA();

		std::string GetName();
		void Excute(std::string strMsg);

	private:
		std::string m_strName;
	};


	//! 观察者所观察的对象
	class IObject
	{
	public:
		virtual void Register(IObserver* observer) = 0;
		virtual void Notify(std::string strMsg) = 0;
		virtual void UnRegister(IObserver* observer) = 0;
	};


	class ObjectA : public IObject
	{
	public:
		ObjectA(std::string strName);
		~ObjectA();

		void Register(IObserver* observer);
		void Notify(std::string strMsg);
		void UnRegister(IObserver* observer);

	private:
		std::string m_strName;
		std::map<std::string, IObserver*> m_observers;
	};


	void TestObserver();
}