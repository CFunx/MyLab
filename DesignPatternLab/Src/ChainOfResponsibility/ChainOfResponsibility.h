#pragma once
#include <iostream>

/**
  \brief 责任链模式，主要是将一个任务在不同的处理人中传递下去
         在看每一种模式的时候，主要是看这种模式怎么应对相关的需求变换的
		 以及在应对变化时候的可扩展和相应的维护成本所带来的问题
*/


//! 定义Task的统一接口
class ITasks
{
public:
	void SetTaskType(std::string strTaskType);
	std::string GetTaskType();
private:

	std::string m_strTaskType;
};

class IHandler
{
public:
	virtual void SetHandler(IHandler* handler) = 0;
	virtual void HandleTask(ITasks& tasks) = 0;
	virtual void SetTaskType(std::string strTaskType) = 0;
};


class HandlerA : public IHandler
{
public:
	HandlerA();
	virtual ~HandlerA();
	virtual void SetHandler(IHandler* handler)override;
	virtual void HandleTask(ITasks& tasks) override;
	virtual void SetTaskType(std::string strTaskType)override;
private:

	IHandler* m_handler;
	std::string m_strTaskType;

};



class HandlerB : public IHandler
{
public:
	HandlerB();
	virtual ~HandlerB();
	virtual void SetHandler(IHandler* handler)override;
	virtual void HandleTask(ITasks& tasks)override;
	virtual void SetTaskType(std::string strTaskType) override;
private:
	IHandler* m_handler;
	std::string m_strTaskType;
};



void TestChainOfResponsibility();






