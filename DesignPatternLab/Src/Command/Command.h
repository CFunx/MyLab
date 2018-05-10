#pragma once
#include <iostream>

/**
	����ģʽ���ǽ���ͬ��������з�װ��Ȼ�󽫲�ͬ�Ľ����ߣ�Ҳ���������ʵ���ߣ�
	���뵽�����н�����صľ����������������Խ������ɵ���װ���������������Ĳ���
*/

namespace nsCmd
{
	class IReciver
	{
	public:
		//! ���ĳ������ִ�еĲ���
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


	//! ����Ĵ�����
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