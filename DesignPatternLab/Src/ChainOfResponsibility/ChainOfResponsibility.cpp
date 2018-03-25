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
		std::cout << "HandlerA can not handle��" << m_strTaskType.c_str() <<"\n";
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
		std::cout << "HandlerB can not handle��" << m_strTaskType.c_str() << "\n";
		std::cout << "Reach the end of chain\n";
	}

	//! �����������һ��û�б�����ֱ�ӷ���
	//m_handler.HandleTask(tasks);
}


void HandlerB::SetTaskType(std::string strTaskType)
{
	m_strTaskType = strTaskType;
}


void TestChainOfResponsibility()
{
	//! ��������
	ITasks tasks;
	tasks.SetTaskType("Ta");


	//! ����������
	IHandler* handlerA = new HandlerA;
	IHandler* handlerB = new HandlerB;

	//! ������������
	handlerA->SetTaskType("Ta");
	handlerB->SetTaskType("Tb");


	//! ����������
	handlerA->SetHandler(handlerB);

	//! ����
	handlerA->HandleTask(tasks);


	//�� ��Դ������
	delete handlerA;
	delete handlerB;
}