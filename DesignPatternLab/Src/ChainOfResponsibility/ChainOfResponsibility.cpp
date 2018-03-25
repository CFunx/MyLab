#include "ChainOfResponsibility.h"


void ITasks::SetTaskType(std::string strTaskType)
{
	m_strTaskType = strTaskType;
}


std::string ITasks::GetTaskType()
{
	return m_strTaskType;
}



HandlerA::HandlerA()
	:m_handler(nullptr)
{

}

HandlerA::~HandlerA()
{

}


void HandlerA::SetHandler(IHandler* handler)
{
	m_handler = handler;
}


void HandlerA::HandleTask(ITasks& tasks)
{
	if (tasks.GetTaskType()== m_strTaskType)
	{
		std::cout << m_strTaskType.c_str() << "was handled by HandlerA\n";
	}
	else
	{
		std::cout << "HandlerA can not handle：" << m_strTaskType.c_str() <<"\n";
	}
	m_handler->HandleTask(tasks);
}


void HandlerA::SetTaskType(std::string strTaskType)
{
	m_strTaskType = strTaskType;
}



HandlerB::HandlerB()
	:m_handler(nullptr)
{

}

HandlerB::~HandlerB() 
{

}


void HandlerB::SetHandler(IHandler* handler)
{
	m_handler = handler;
}


void HandlerB::HandleTask(ITasks& tasks)
{

	if (tasks.GetTaskType() == m_strTaskType)
	{
		std::cout << m_strTaskType.c_str() << "was handled by HandlerB\n";
	}
	else
	{
		std::cout << "HandlerB can not handle：" << m_strTaskType.c_str() << "\n";
		std::cout << "Reach the end of chain\n";
	}

	//! 责任链到最后一环没有被处理直接返会
	//m_handler.HandleTask(tasks);
}


void HandlerB::SetTaskType(std::string strTaskType)
{
	m_strTaskType = strTaskType;
}


void TestChainOfResponsibility()
{
	//! 创建任务
	ITasks tasks;
	tasks.SetTaskType("Ta");


	//! 创建处理者
	IHandler* handlerA = new HandlerA;
	IHandler* handlerB = new HandlerB;

	//! 设置任务类型
	handlerA->SetTaskType("Ta");
	handlerB->SetTaskType("Tb");


	//! 构建责任链
	handlerA->SetHandler(handlerB);

	//! 运行
	handlerA->HandleTask(tasks);


	//！ 资源的销毁
	delete handlerA;
	delete handlerB;
}