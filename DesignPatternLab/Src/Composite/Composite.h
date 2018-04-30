#pragma once
#include <iostream>
#include <vector>

/**
	组合模式主要用来处理"叶子对象"和"组合对象"时的关系,对这两种对象的接口进行统一到一个抽象类中
	这样就不需要区分是叶子还是组合对象的情况，继而做到了统一的访问方式。
*/


namespace Composite
{

	//! 此类就是叶子节点和组合对象接口的集合
	class IComponent
	{
	public:
		IComponent() = default;
		virtual ~IComponent() = default;

		//! 组合节点需要的接口，叶子节点实际上是不需要的
		virtual void SetChild(IComponent* component);

		//! 打印相关结构的名字
		virtual void PrintStruct();

	};


	class CComposite : public IComponent
	{
	public:
		CComposite(std::string strName);
		~CComposite();

		void SetChild(IComponent* component) override;

		void PrintStruct() override;
	private:

		std::string m_comName;

		std::vector<IComponent*> m_comCotainers;

	};


	class CLeaf : public IComponent
	{
	public:
		CLeaf(std::string strName);
		~CLeaf();

		void PrintStruct() override;

	private:
		std::string m_comName;
	};


	void TestComposite();
}