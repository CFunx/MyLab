#pragma once
#include <iostream>
#include <vector>


/**
	迭代器模式
*/
namespace nsIterator
{
	class IContainers;
	class ConCreteContainer;

	class Iiterator
	{
	public:

		virtual size_t Size() = 0;
		virtual void Next() = 0;
		virtual size_t Value() = 0;
	};


	//! 每个具体的类有自己实现的迭代器
	class ConCreteIterator : public Iiterator
	{
	public:
		ConCreteIterator(ConCreteContainer* container);
		~ConCreteIterator();

		size_t Size() override;
		void Next() override;
		size_t Value() override;

	private:

		ConCreteContainer* m_containers;
	};


	class IContainers
	{
	public:
		virtual Iiterator* GetIterator() = 0;
	};


	class ConCreteContainer : public IContainers
	{
	public:
		ConCreteContainer();
		~ConCreteContainer();

		//! 创建自己的容器
		Iiterator* GetIterator() override;

		size_t GetSize();
		void  NextElem();
		size_t GetCurrentValue();

	private:

		std::vector<size_t> m_b;
		size_t  m_size;
	};


	void  TestIterator();
}