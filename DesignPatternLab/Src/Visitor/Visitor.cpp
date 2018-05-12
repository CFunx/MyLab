#include "Visitor.h"


void ConcreteVistorA::HandleCustomerA(ConcreteCustomerA* ca)
{
	std::cout << "I am ConcreteVistorA::HandleCustomerA \n";
	ca->Show();
}


void ConcreteVistorA::HandleCustomerB(ConcreteCustomerB* cb)
{
	std::cout << "I am ConcreteVistorA::HandleCustomerB \n";
	cb->Show();
}


void ConcreteVistorB::HandleCustomerA(ConcreteCustomerA* ca)
{
	std::cout << "I am ConcreteVistorB::HandleCustomerA \n";
	ca->Show();
}


void ConcreteVistorB::HandleCustomerB(ConcreteCustomerB* cb)
{
	std::cout << "I am ConcreteVistorB::HandleCustomerB \n";
	cb->Show();
}


void ConcreteCustomerA::Accept(IVisitor* visitor) 
{
	std::cout << "I am ConcreteCustomerA::Accept \n";
	visitor->HandleCustomerA(this);
}


void ConcreteCustomerA::Show()
{
	std::cout << "I am ConcreteCustomerA::Show\n";
}


void ConcreteCustomerB::Accept(IVisitor* visitor)
{
	std::cout << "I am ConcreteCustomerB::Accept \n";
	visitor->HandleCustomerB(this);
}


void ConcreteCustomerB::Show()
{
	std::cout << "I am ConcreteCustomerB::Show\n";
}


CustomerContainers::~CustomerContainers()
{
	m_customers.clear();
	m_customers.shrink_to_fit();
}


void CustomerContainers::AddCustomer(ICustomer* customer)
{
	m_customers.push_back(customer);
}


void CustomerContainers::HandleRequest(IVisitor* vistor)
{
	auto it = m_customers.begin();
	for (; it != m_customers.end(); ++it)
	{
		(*it)->Accept(vistor);
	}
}



void TestVisitor()
{
	//! 创建客客户容器类
	CustomerContainers custcontainer;


	//! 创建客户
	ICustomer* customerA = new ConcreteCustomerA;
	ICustomer* customerB = new ConcreteCustomerB;


	//! 将客户添加到容器中去
	custcontainer.AddCustomer(customerA);
	custcontainer.AddCustomer(customerB);

	//! 创建访问者
	IVisitor* visitorA = new ConcreteVistorA;
	IVisitor* visitorB = new ConcreteVistorB;


	//! 调用
	custcontainer.HandleRequest(visitorA);
	//custcontainer.HandleRequest(visitorB);


	//！销毁
	delete customerA;
	customerA = nullptr;
	delete customerB;
	customerB = nullptr;

	delete visitorA;
	visitorA = nullptr;
	delete visitorB;
	visitorB = nullptr;
}