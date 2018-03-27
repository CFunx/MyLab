#include "Decorator.h"

void ComponentA::SomeOperation(std::string strContent)
{
	std::cout << __func__ <<"::ComponentA "<< strContent.c_str() << "\n";
}



void ComponentB::SomeOperation(std::string strContent)
{
	std::cout << __func__ << "::ComponentB" << strContent.c_str() << "\n";
}


///////////////////////////////////////////////////////////

IDecorator::IDecorator(IComponent* Component)
	:m_Component(Component)
{

}


IDecorator::~IDecorator()
{

}


void IDecorator::SomeOperation(std::string strContent)
{
	m_Component->SomeOperation(strContent);
}


void IDecorator::Show(std::string strContent)
{
	std::cout << __func__ << " : " << strContent.c_str() << "\n";
}


DecoratorA::DecoratorA(IComponent* Component)
	:IDecorator(Component)
{

}


DecoratorA::~DecoratorA()
{

}


void DecoratorA::SomeOperation(std::string strContent)
{
	std::cout << __func__ << "::DecoratorA " << strContent.c_str() << "\n";
	m_Component->SomeOperation(strContent);
	ShowA(strContent);
}


void DecoratorA::ShowA(std::string strContent)
{
	std::cout << __func__ << " : " << strContent.c_str() << "\n";
}


DecoratorB::DecoratorB(IComponent* Component)
	:IDecorator(Component)
{

}


DecoratorB::~DecoratorB()
{

}


void DecoratorB::SomeOperation(std::string strContent)
{
	std::cout << __func__ << "::DecoratorB" << strContent.c_str() << "\n";
	m_Component->SomeOperation(strContent);
	ShowB(strContent);
}



void DecoratorB::ShowB(std::string strContent)
{
	std::cout << __func__ << " : " << strContent.c_str() << "\n";
}



void TestDecorator()
{
	IComponent* cl = new ComponentA;


	//! 用下面两个装饰着来装饰 IComponent
	IDecorator* d1 = new DecoratorA(cl);
	IDecorator* d2 = new DecoratorB(d1);

	d2->SomeOperation("Hello, I am Decorator");

	delete cl;
	delete d1;
	delete d2;
}