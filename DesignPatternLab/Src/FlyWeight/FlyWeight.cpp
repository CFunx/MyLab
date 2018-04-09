#include "FlyWeight.h"
#include <memory>



ConcreteFlyWeight::ConcreteFlyWeight(std::string strName)
	:m_strName(strName),
	m_ptrflyWeight(nullptr)
{

}


ConcreteFlyWeight::~ConcreteFlyWeight()
{

}

void ConcreteFlyWeight::Display()
{
	std::cout << "I am ConcreteFlyWeight::Display my name is:" 
		<< m_strName.c_str() << std::endl;
}


void ConcreteFlyWeight::Add(IFlyWeight* ptrflyWeight)
{
	std::cout << __func__ << "  add IflyWeight\n";
	m_ptrflyWeight = ptrflyWeight;
}




ConcreteUnFlyWeight::ConcreteUnFlyWeight(std::string strName)
	:m_strName(strName),
	m_ptrflyWeight(nullptr)
{

}


ConcreteUnFlyWeight::~ConcreteUnFlyWeight()
{

}

void ConcreteUnFlyWeight::Display()
{
	std::cout << "I am ConcreteUnFlyWeight::Display my name is:"
		<< m_strName.c_str() << std::endl;
}


void ConcreteUnFlyWeight::Add(IFlyWeight* ptrflyWeight)
{
	std::cout << __func__ << "  add IflyWeight\n";
	m_ptrflyWeight = ptrflyWeight;
}





std::map<std::string, IFlyWeight*> FlyweightFactory::m_flyweight;
std::mutex FlyweightFactory::m_mutex;

FlyweightFactory& FlyweightFactory::GetInstance()
{
	//! c++11 is thread safe
	static FlyweightFactory flyInstance;
	return flyInstance;
}



IFlyWeight* FlyweightFactory::GetFlyWeight(std::string strName)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	auto it = m_flyweight.begin();

	for( ; it != m_flyweight.end(); ++it)
	{
		if (it->first == strName)
		{
			return it->second;
		}
	}

	IFlyWeight* ifly = new ConcreteFlyWeight(strName);
	m_flyweight.insert(std::pair<std::string,IFlyWeight*>(strName,ifly));

	return ifly;
}



void FlyweightFactory::Destory()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	auto it = m_flyweight.begin();

	for (; it != m_flyweight.end(); ++it)
	{
		delete it->second;
		it->second = nullptr;
	}

	m_flyweight.clear();
}




void TestFlyWeight()
{
	//! 享元对象 使用
	FlyweightFactory::GetInstance().GetFlyWeight("one")->Display();
	FlyweightFactory::GetInstance().GetFlyWeight("two")->Display();
	FlyweightFactory::GetInstance().GetFlyWeight("one")->Display();

	FlyweightFactory::GetInstance().Destory();


	//! 非享元对象使用
	//std::shared_ptr<IFlyWeight> i(new ConcreteUnFlyWeight("three"));
	std::shared_ptr<IFlyWeight*> i= std::make_shared<IFlyWeight*>(new ConcreteUnFlyWeight("three"));
	(**i).Display();
}
