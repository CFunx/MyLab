#pragma once
#include <iostream>
#include <vector>


/**
	������ģʽ
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


	//! ÿ������������Լ�ʵ�ֵĵ�����
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

		//! �����Լ�������
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