#include "AbsFactory.h"

namespace nsAbsFactory
{
	
	
	ICpu* CSchemaA::CreateCpu()
	{
		return new CIntelCpu(128,"intel");
	}

	IMainBoard* CSchemaA::CreateMainBoard()
	{
		return new CGigaBoard(128,"Giga");
	}

	ICpu* CSchemaB::CreateCpu()
	{
		return new CAMDCpu(64, "AMD");
	}

	IMainBoard* CSchemaB::CreateMainBoard()
	{
		return new CDellBoard(64,"Dell");
	}
	
	CIntelCpu::CIntelCpu(int nPins, std::string strBrand)
		 :m_pins(nPins),
		 m_strBrand(strBrand)
	 {
	 }

	 CIntelCpu::~CIntelCpu()
	 {
	 }

	int CIntelCpu::GetPins()
	{
		return m_pins;
	}

	std::string CIntelCpu::GetBrand()
	{
		return m_strBrand;
	}

	
	 CAMDCpu::CAMDCpu(int nPins, std::string strBrand)
		 :m_pins(nPins),
		 m_strBrand(strBrand)
	 {

	 }

	 CAMDCpu::~CAMDCpu()
	{
	}

	int  CAMDCpu::GetPins()
	{
		return m_pins;
	}

	std::string  CAMDCpu::GetBrand()
	{
		return m_strBrand;
	}

	 CGigaBoard::CGigaBoard(int nPins, std::string strBrand)
		 :m_pins(nPins),
		 m_strBrand(strBrand)
	 {

	 }

	 CGigaBoard::~CGigaBoard()
	{
	}

	int  CGigaBoard::GetPins()
	{
		return m_pins;
	}

	std::string  CGigaBoard::GetBrand()
	{
		return m_strBrand;
	}

	 CDellBoard::CDellBoard(int nPins, std::string strBrand)
		 :m_pins(nPins),
		 m_strBrand(strBrand)
	{
	}

	 CDellBoard::CDellBoard()
	{
	}

	int  CDellBoard::GetPins()
	{
		return m_pins;
	}

	std::string CDellBoard::GetBrand()
	{
		return m_strBrand;
	}

	void  TestAbsFactory()
	{

		//! 创建能生产各种产品的工厂
		AbsFactory* sa = new CSchemaA;
		AbsFactory* sb = new CSchemaB;

		//! 创建各种产品
		ICpu* saCpu =  sa->CreateCpu();
		IMainBoard* saBoard = sa->CreateMainBoard();

		ICpu* sbCpu = sb->CreateCpu();
		IMainBoard* sbBoard = sb->CreateMainBoard();

		std::cout << "The schemaA produced computer cpuInfo :" <<
			" Brand:" << saCpu->GetBrand() << "  pins :" << saCpu->GetPins()
			<< " MainBoard info :"
			<< " Brand:" << saBoard->GetBrand()
			<< "  pins :" << saBoard->GetPins() << std::endl;


		std::cout << "The schemaB produced computer cpuInfo :" <<
			" Brand:" << sbCpu->GetBrand() << "  pins :" << sbCpu->GetPins()
			<< " MainBoard info :"
			<< " Brand:" << sbBoard->GetBrand()
			<< "  pins :" << sbBoard->GetPins() << std::endl;

		delete sa;
		sa = nullptr;

		delete sb;
		sb = nullptr;

		delete saCpu;
		saCpu = nullptr;

		delete sbCpu;
		sbCpu = nullptr;

		delete saBoard;
		saBoard = nullptr;

		delete sbBoard;
		sbBoard = nullptr;
	}
}
