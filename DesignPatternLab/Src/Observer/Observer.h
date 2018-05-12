#pragma once
#include <iostream>
#include <string>
#include <map>


/**
	�۲���ģʽ������һ�������״̬�����ı�֮�������������ڴ���Ķ����ܹ��������仯
	�����ܹ����ݱ仯������Ӧ�Ķ���
*/

namespace nsObserver
{
	//! �۲���
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


	//! �۲������۲�Ķ���
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