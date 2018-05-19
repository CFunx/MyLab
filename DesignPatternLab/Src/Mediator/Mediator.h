#pragma once
#include <iostream>
#include <string>

/**
	中介者模式主要是将各个部分之间的交互进行封装，让各个部分只和中介者来尽享交互。终结者来进行处理
	各部分的交互关系。
*/



namespace nsMediator
{
	class CMediator;


	//! 在广义中介者中组件的抽象类可以没有
	class IComponent
	{
	public:
		virtual	void SetMediator(CMediator* mediator) = 0;
		virtual std::string GetName() = 0;
		virtual void Excute(std::string strData) = 0;
		virtual void ShowData(std::string strData) = 0;
	
	};


	class ComponentA : public IComponent
	{
	public:
		ComponentA(std::string strName);
		~ComponentA();

		void SetMediator(CMediator* mediator) override;
		std::string GetName() override;
		void Excute(std::string strData) override;
		virtual void ShowData(std::string strData) override;


	private:
		CMediator* m_mediator;
		std::string  m_strName;
	};


	class ComponentB : public IComponent
	{
	public:
		ComponentB(std::string strName);
		~ComponentB();

		void SetMediator(CMediator* mediator) override;
		std::string GetName() override;
		void Excute(std::string strData) override;
		virtual void ShowData(std::string strData) override;

	private:
		CMediator* m_mediator;
		std::string  m_strName;
	};



	//! 终结者可以写成单利模式
	class CMediator
	{
	public:
		CMediator();
		~CMediator();
		void SetComponent(IComponent* comA, IComponent* comB);
		void Communicate(IComponent* com, std::string strData);
	
	private:
		CMediator(const CMediator&);
		CMediator& operator=(const CMediator&);

	private:
		IComponent* m_comA;
		IComponent* m_comB;

	};


	void TestMediator();
}