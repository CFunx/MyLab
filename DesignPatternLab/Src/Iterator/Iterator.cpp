#include "Iterator.h"

namespace nsIterator
{
	ConCreteIterator::ConCreteIterator(ConCreteContainer* container)
		:m_containers(container)
	{

	}
	

	ConCreteIterator::~ConCreteIterator()
	{

	}


	size_t ConCreteIterator::Size()
	{
		return m_containers->GetSize();
	}


	void ConCreteIterator::Next()
	{
		m_containers->NextElem();
	}


	size_t ConCreteIterator::Value()
	{
		return m_containers->GetCurrentValue();
	}


	ConCreteContainer::ConCreteContainer()
	{
		m_b = { 1,2,3,45,6,78,9 };
		m_size = 0;
	}

	ConCreteContainer::~ConCreteContainer()
	{

	}

	Iiterator* ConCreteContainer::GetIterator()
	{
		return new ConCreteIterator(this);

	}

	size_t ConCreteContainer::GetSize()
	{
		return m_b.size();
	}

	void ConCreteContainer::NextElem()
	{
		if (m_size <= m_b.size()-1)
		{
			m_size++;
		}
		else
		{
			std::cout << "Out of range m_b.size()\n";
		}
	}


	size_t ConCreteContainer::GetCurrentValue()
	{
		if (m_size <= m_b.size() )
		{
			return m_b.at(m_size);
		}
		else
		{
			std::cout << "out of m_b.size()\n";
			return 0;
		}
	}


	void TestIterator()
	{

		//! 创建 相应的容器
		IContainers* containers = new ConCreteContainer;

		Iiterator* it = containers->GetIterator();

		std::cout << "size is :" << it->Size() << std::endl;
		
		it->Next();
		std::cout << "value is :" << it->Value() << std::endl;

		it->Next();
		std::cout << "value is :" << it->Value() << std::endl;

		it->Next();
		std::cout << "value is :" << it->Value() << std::endl;

		delete containers;
		containers = nullptr;
	}
}


