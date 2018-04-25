#include "Strategy.h"

ConcreteStrategyA::ConcreteStrategyA(std::string strName)
	:m_strName(strName)
{

}

void ConcreteStrategyA::ShowName()
{
	std::cout << "My name is :" << m_strName.c_str() << std::endl;
}


ConcreteStrategyB::ConcreteStrategyB(std::string strName)
	:m_strName(strName)
{

}

void ConcreteStrategyB::ShowName()
{
	std::cout << "My name is :" << m_strName.c_str() << std::endl;
}


void StrategyContext::ShowStrategyName(IStrategy& strategy)
{
	strategy.ShowName();
}


void TestStrategy()
{
	ConcreteStrategyA strategyA("strgyA");
	ConcreteStrategyB strategyB("strgyB");

	StrategyContext strategyCntxt;

	strategyCntxt.ShowStrategyName(strategyA);
	strategyCntxt.ShowStrategyName(strategyB);
}