#include "Facade.h"

namespace nsFacade
{

	void CModuleA::FunctionA()
	{
		std::cout << __FUNCTION__ << " is writting log \n";
	}

	void CModuleB::FunctionB()
	{
		std::cout << __FUNCTION__ << " is  Reading log \n";
	}


	void CModuleC::FunctionC()
	{
		std::cout << __FUNCTION__ << " is  Deleting log \n";
	}


	void CFacade::TestModuleABC()
	{
		m_moduleA.FunctionA();
		m_moduleB.FunctionB();
		m_moduleC.FunctionC();
	}


	void TestFacade()
	{
		CFacade facade;
		facade.TestModuleABC();
	}
}