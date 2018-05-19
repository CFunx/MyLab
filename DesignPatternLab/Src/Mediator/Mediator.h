#pragma once
#include <iostream>
#include <string>

/**
	�н���ģʽ��Ҫ�ǽ���������֮��Ľ������з�װ���ø�������ֻ���н��������������ս��������д���
	�����ֵĽ�����ϵ��
*/



namespace nsMediator
{
	class CMediator;


	//! �ڹ����н���������ĳ��������û��
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



	//! �ս��߿���д�ɵ���ģʽ
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