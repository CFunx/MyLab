#include "Composite/Composite.h"
#include <cassert>


namespace nsComposite
{
	void IComponent::SetChild(IComponent* component)
	{
		assert(nullptr != component);
	}


	void IComponent::PrintStruct()
	{

	}


	CComposite::CComposite(std::string strName)
		:m_comName(strName)
	{

	}


	CComposite::~CComposite()
	{

	}


	void CComposite::SetChild(IComponent* component)
	{
		assert(nullptr != component);
		m_comCotainers.push_back(component);
	}


	void CComposite::PrintStruct()
	{
		auto it = m_comCotainers.begin();

		for (it; it != m_comCotainers.end(); ++it)
		{
			std::cout << m_comName.c_str() << std::endl;
			(*it)->PrintStruct();
		}

	}


	CLeaf::CLeaf(std::string strName)
		:m_comName(strName)
	{

	}


	CLeaf::~CLeaf()
	{

	}


	void CLeaf::PrintStruct()
	{
		std::cout <<m_comName.c_str()<<"\n";
	}



	void TestComposite()
	{
		//! 创建一个根节点
		IComponent* root = new CComposite("root");

		//! 子节点
		IComponent* subchild = new CComposite(" -subchild");

		//! 叶子节点
		IComponent* leaf = new CLeaf("  --leaf");

		//! 组装

		root->SetChild(subchild);
		subchild->SetChild(leaf);

		root->PrintStruct();


		delete root;
		root = nullptr;

		delete subchild;
		subchild = nullptr;

		delete leaf;
		leaf = nullptr;
	}
}