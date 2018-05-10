#pragma once
#include <iostream>

/**
	命令模式就是将不同的命令进行封装，然后将不同的接收者（也就是命令的实现者）
	传入到命令中进行相关的具体命令，这里命令可以进行自由的组装或者其他针对命令的操作
*/

namespace nsCmd
{
	class IReciver
	{
	public:
		//! 针对某个命令执行的操作
		virtual void Action() = 0;
	};


	class ReciverA : public IReciver
	{
	public:
		ReciverA() = default;
		~ReciverA()= default;

		void Action() override;
	};


	class ICommand
	{
	public:
		virtual void Excute() = 0;
	};


	class CommandA : public ICommand
	{
	public:
		CommandA(IReciver* reciver);
		~CommandA();

		void Excute() override;

	private:
		IReciver*  m_Reciver;
	};


	//! 命令的触发者
	class CInvoker
	{
	public:
		CInvoker() = default;
		~CInvoker() = default;

		void SetCommand(ICommand* cmd);

		void StartAction();

	private:

		ICommand* m_commad;
	};

	void TestCommad();

}