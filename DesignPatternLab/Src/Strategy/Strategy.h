#pragma once
#include <iostream>


/**
  ����ģʽ���ǽ���ͬ�ķ����ֱ��װ�ɲ�ͬ���࣬��Щ��֮������໥��̬���滻��Ҳ����˵
  ��Щ��֮�����໥ƽ�ȵ�.
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

	//! ��ͬ�Ĳ���ʵ�ֽӿ�
	void ShowName() override;

private:

	std::string m_strName;
};


class ConcreteStrategyB : public IStrategy
{
public:
	ConcreteStrategyB(std::string strName);
	~ConcreteStrategyB() = default;

	//! ��ͬ�Ĳ���ʵ�ֽӿ�
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

	//! �����л����Ը����û��������Զ�ѡ����Ӧ�Ĳ���

};


void TestStrategy();