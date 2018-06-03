#include "Builder.h"
#include <cassert>

namespace nsBuilder
{
	CBuilderA::CBuilderA()
		:m_ProductName("")
	{

	}
		

	void CBuilderA::CreateName(std::string strName)
	{
		m_ProductName = strName;
		m_ProductName = m_ProductName + "====";
	}

	void CBuilderA::BeautifyName()
	{
		m_ProductName = m_ProductName +"so beautiful\n";
	}
	
	std::string CBuilderA::GetName()
	{
		return m_ProductName;
	}


	CBuilderB::CBuilderB()
		:m_ProductName("")
	{

	}


	void CBuilderB::CreateName(std::string strName)
	{
		m_ProductName = strName;
		m_ProductName = m_ProductName + "******";
	}

	void CBuilderB::BeautifyName()
	{
		m_ProductName = m_ProductName + "so ugly\n";
	}

	std::string CBuilderB::GetName()
	{
		return m_ProductName;
	}

	void CDirector::SetBuilder(IBuilder* builder)
	{
		assert(nullptr != builder);
		m_builder = builder;

	}

	void CDirector::Constructor(std::string strName)
	{
		m_builder->CreateName(strName);
		m_builder->BeautifyName();
		std::string strTmp = m_builder->GetName();

		std::cout << "Final result is:" << strTmp.c_str();
	}


	void  TestBuilder()
	{
		//! 创建具体的创建者
		IBuilder* builderA = new CBuilderA();

		IBuilder* builderB = new CBuilderB();


		//! 创建指导者
		CDirector director;


		//! 生成具体的产品
		director.SetBuilder(builderA);
		director.Constructor("Jimmy");
		delete builderA;
		builderA = nullptr;


		director.SetBuilder(builderB);
		director.Constructor("Jeff");

		delete builderB;
		builderB = nullptr;
	}
}