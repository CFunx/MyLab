#include "Mediator.h"
#include <cassert>

namespace nsMediator
{
	ComponentA::ComponentA(std::string strName)
		: m_mediator(nullptr),
		m_strName(strName)
	{

	}

	ComponentA::~ComponentA() = default;


	void ComponentA::SetMediator(CMediator* mediator)
	{
		assert(mediator != nullptr);
		m_mediator = mediator;
	}

	std::string ComponentA::GetName()
	{
		return m_strName;
	}

	void ComponentA::Excute(std::string strData)
	{
		m_mediator->Communicate(this, strData);
	}

	void ComponentA::ShowData(std::string strData)
	{
		std::cout << "I am " << m_strName.c_str()
			<< " recive data" << strData.c_str() << std::endl;
	}


	ComponentB::ComponentB(std::string strName)
		: m_mediator(nullptr),
		m_strName(strName)
	{

	}

	ComponentB::~ComponentB() = default;


	void ComponentB::SetMediator(CMediator* mediator)
	{
		assert(mediator != nullptr);
		m_mediator = mediator;
	}

	std::string ComponentB::GetName()
	{
		return m_strName;
	}


	void ComponentB::Excute(std::string strData)
	{
		m_mediator->Communicate(this, strData);
	}


	void ComponentB::ShowData(std::string strData)
	{
		std::cout << "I am " << m_strName.c_str()
			<< " recive data" << strData.c_str() << std::endl;
	}


	CMediator::CMediator()
		: m_comA(nullptr),
		m_comB(nullptr)
	{

	}


	CMediator::~CMediator() = default;


	void CMediator::SetComponent(IComponent* comA, IComponent* comB)
	{ 
		assert(comA != nullptr);
		assert(comB != nullptr);

		m_comA = comA;
		m_comB = comB;
	}

	void CMediator::Communicate(IComponent* com, std::string strData)
	{
		if (&(*m_comA)== &(*com))
		{
			m_comB->ShowData(strData);
		}
		else if(&(*m_comB) == &(*com))
		{
			m_comA->ShowData(strData);
		}
	}


	void TestMediator()
	{
		//! 创建中介者
		CMediator* mediator = new CMediator();


		//! 创建组件
		IComponent* comA = new ComponentA("comA");
		IComponent* comB = new ComponentA("comB");
		comA->SetMediator(mediator);
		comB->SetMediator(mediator);

		//! 给中介者设置
		mediator->SetComponent(comA, comB);


		//! 组件的调用
		comA->Excute("Hi,I am ComA ======\n");
		comB->Excute("Hi,I am ComB ******\n");

		delete mediator;
		mediator = nullptr;

		delete comA;
		comA = nullptr;

		delete comB;
		comB = nullptr;
	}

}