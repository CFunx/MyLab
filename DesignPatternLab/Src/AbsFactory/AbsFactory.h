#pragma once
#include <iostream>
#include <string>

/**
	抽象工厂就是提供一个创建一系列相关或相互依赖对象的接口，而无需指定
	他们具体的类.
*/


namespace nsAbsFactory
{
	/* 以组装电脑为例,cup的脚针数必须和主板的上脚针数目一样才能够进行电脑的组装
	   现在又两种组装方案： 
	                 1. intel的Cpu + 技嘉的主板； 
	                 2. AMD的Cpu  + 戴尔的主板
  */

	class ICpu;
	class IMainBoard;

	class AbsFactory
	{
	public:
		//! 这两个接口产生的对象具有一定的关系，这个关系的维护或者是组织
		//! 是在具体的工厂中进行维护的
		virtual ICpu* CreateCpu() = 0;
		virtual IMainBoard* CreateMainBoard() = 0;
	};



	//! 方案一 intelCpu + dellboard
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