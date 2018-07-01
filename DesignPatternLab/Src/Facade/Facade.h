#pragma once
#include <iostream>

/**
	外观模式就是对现有模块的接口进行一层封装，使其变得更加简单好用。
	这样对使用者来说需要掌握最少的“知识” 即可使用。
*/


namespace nsFacade
{
	/* 假设现在有三个模块，A，B，C 分别负责三个不同的功能
	   这三个模块按照某种顺序能组合出不同的功能，为了让使用者
	   不用去了解这个三个模块的具体功能，我们用Facade模式将三个模块封装
	   成一个使用比较简单的接口这样，使用者只要调用此几口即可。
	*/

	class CModuleA
	{
	public:
		void FunctionA();
	};


	class CModuleB
	{
	public:
		void FunctionB();
	};


	class CModuleC
	{
	public:
		void FunctionC();
	};


	class CFacade
	{
	public:
		CFacade()  = default;
		~CFacade() = default;

		void TestModuleABC();
	private:
		CModuleA  m_moduleA;
		CModuleB  m_moduleB;
		CModuleC  m_moduleC;
	};

	void TestFacade();

}