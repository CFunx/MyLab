#pragma once
#include <iostream>


/**
  策略模式就是将不同的方法分别封装成不同的类，这些类之间可以相互动态的替换。也就是说
  这些类之间是相互平等的.
*/

class IStrategy
{
public:
	virtual void ShowName() = 0;
};


class ConcreteStrategyA : public IStrategy
{
public:
	ConcreteStrategyA(std::string strName);
	~ConcreteStrategyA() = default;

	//! 不同的策略实现接口
	void ShowName() override;

private:

	std::string m_strName;
};


class ConcreteStrategyB : public IStrategy
{
public:
	ConcreteStrategyB(std::string strName);
	~ConcreteStrategyB() = default;

	//! 不同的策略实现接口
	void ShowName() override;

private:

	std::string m_strName;
};


class StrategyContext
{
public:
	StrategyContext() = default;
	~StrategyContext() = default;

	void ShowStrategyName(IStrategy& strategy);

	//! 此类中还可以根据用户输入来自动选择相应的策略

};


void TestStrategy();