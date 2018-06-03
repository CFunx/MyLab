#pragma  once
#include <iostream>
#include <string>

/**
	生成器模式(Builder)就是将一个对象的构建与其表示分离，使得同样的构建过程可以创建
	不同的表示，主要适用于相同的步骤但是每个步骤的实现是不同的情况
*/

namespace nsBuilder
{
	//! 创建者主要是用来约束创建步骤的接口，以及组组件的组装功能
	//! 将组装好的组件组装到产品中去
	class IBuilder
	{
	public:
		virtual void CreateName(std::string strName) = 0;
		virtual void BeautifyName() = 0;
		virtual std::string GetName() = 0;
	};



	//! 具体的实现类A,主要实现
	class CBuilderA : public IBuilder
	{
	public:
		CBuilderA();
		~CBuilderA() = default;
		
		void CreateName(std::string strName) override;
		void BeautifyName() override;
		std::string GetName() override;

	private:

		//! 被构建的产品
		std::string m_ProductName;
	};


	class CBuilderB : public IBuilder
	{
	public:
		CBuilderB();
		~CBuilderB() = default;

		void CreateName(std::string strName) override;
		void BeautifyName() override;
		std::string GetName() override;
	private:
		//! 被构建的产品
		std::string  m_ProductName;
	};


	//! 指导者用来根据需求组装生成者，或者是根据某个规则
	//! 来调用不同的步骤,在复杂的情况下还要和Builder来进行通信
	//！实际上Director就是根据需求组装产品的过程
	class CDirector
	{
	public:
		CDirector()= default;
		~CDirector() = default;
		void SetBuilder(IBuilder* builder);
		void Constructor(std::string strName);
	private:
		IBuilder* m_builder;
	};


	void TestBuilder();

}