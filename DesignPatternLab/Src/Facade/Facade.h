#pragma once
#include <iostream>

/**
	���ģʽ���Ƕ�����ģ��Ľӿڽ���һ���װ��ʹ���ø��Ӽ򵥺��á�
	������ʹ������˵��Ҫ�������ٵġ�֪ʶ�� ����ʹ�á�
*/


namespace nsFacade
{
	/* ��������������ģ�飬A��B��C �ֱ���������ͬ�Ĺ���
	   ������ģ�鰴��ĳ��˳������ϳ���ͬ�Ĺ��ܣ�Ϊ����ʹ����
	   ����ȥ�˽��������ģ��ľ��幦�ܣ�������Facadeģʽ������ģ���װ
	   ��һ��ʹ�ñȽϼ򵥵Ľӿ�������ʹ����ֻҪ���ô˼��ڼ��ɡ�
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