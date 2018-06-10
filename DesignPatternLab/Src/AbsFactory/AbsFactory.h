#pragma once
#include <iostream>
#include <string>

/**
	���󹤳������ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ��
	���Ǿ������.
*/


namespace nsAbsFactory
{
	/* ����װ����Ϊ��,cup�Ľ����������������Ͻ�����Ŀһ�����ܹ����е��Ե���װ
	   ������������װ������ 
	                 1. intel��Cpu + ���ε����壻 
	                 2. AMD��Cpu  + ����������
  */

	class ICpu;
	class IMainBoard;

	class AbsFactory
	{
	public:
		//! �������ӿڲ����Ķ������һ���Ĺ�ϵ�������ϵ��ά����������֯
		//! ���ھ���Ĺ����н���ά����
		virtual ICpu* CreateCpu() = 0;
		virtual IMainBoard* CreateMainBoard() = 0;
	};



	//! ����һ intelCpu + dellboard
	class CSchemaA : public AbsFactory
	{
	public:
		 ICpu* CreateCpu() override;
		 IMainBoard* CreateMainBoard() override;
	};


	class CSchemaB : public AbsFactory
	{
	public:
		ICpu* CreateCpu() override;
		IMainBoard* CreateMainBoard() override;
	};


	class ICpu
	{
	public:
		virtual int GetPins() = 0;
		virtual std::string GetBrand() = 0;
	};

	class IMainBoard
	{
	public:
		virtual int GetPins() = 0;
		virtual std::string GetBrand() = 0;
	};


	
	class CIntelCpu : public ICpu
	{
	public:
		CIntelCpu(int nPins, std::string strBrand);
		~CIntelCpu();

		int GetPins() override;
		std::string GetBrand() override;

	private:
		int m_pins;
		std::string m_strBrand;
	};



	class CAMDCpu : public ICpu
	{
	public:
		CAMDCpu(int nPins, std::string strBrand);
		~CAMDCpu();

		int GetPins() override;
		std::string GetBrand() override;

	private:
		int m_pins;
		std::string m_strBrand;
	};

	
	class CGigaBoard : public IMainBoard
	{
	public:
		CGigaBoard(int nPins, std::string strBrand);
		~CGigaBoard();

		int GetPins() override;
		std::string GetBrand() override;

	private:
		int m_pins;
		std::string m_strBrand;
	};

	class CDellBoard : public IMainBoard
	{
	public:
		CDellBoard(int nPins, std::string strBrand);
		CDellBoard();

		int GetPins() override;
		std::string GetBrand() override;

	private:
		int m_pins;
		std::string m_strBrand;
	};

	void TestAbsFactory();

}