#include "Command.h"


namespace nsCmd
{
	void ReciverA::Action()
	{
		std::cout << "This is ReciverA Action\n";
	}


	CommandA::CommandA(IReciver* reciver)
		: m_Reciver(reciver)
	{

	}

	CommandA::~CommandA() = default;

	void CommandA::Excute()
	{
		m_Reciver->Action();
	}


	void CInvoker::SetCommand(ICommand* cmd)
	{
		m_commad = cmd;
	}

	void CInvoker::StartAction()
	{
		m_commad->Excute();
	}


	void TestCommad()
	{
		//! 创建命令的接收者
		IReciver* reciver = new ReciverA;

		//! 创建命令
		ICommand* cmd = new CommandA(reciver);

		//! 执行命令
		CInvoker invoker;
		invoker.SetCommand(cmd);
		invoker.StartAction();


		delete reciver;
		reciver = nullptr;

		delete cmd;
		cmd = nullptr;
	}
}