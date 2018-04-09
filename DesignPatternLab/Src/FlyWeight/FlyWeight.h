#pragma once
#include <iostream>
#include <map>
#include <mutex>


/**
*  享元模式，主要是将不变的部分和变化的部分离出来，不变的部分作为享元（共享）
   不共享的部分作为（非共享的部分）有时共享的部分可能需要用到非共享的部分。
   共享的部分通过一个工厂来进行管理，客户端在使用的时候既可以使用共享的部分也
   会使用共享的部分。
*/


//! 享元抽象类
class IFlyWeight
{
public:
	virtual void Display() = 0;

	//! 通过此接口享元/非享元部分可以调用其它的接口
	virtual void Add(IFlyWeight*  ptrflyWeight) = 0;
};


//! 享元具体实现类
class ConcreteFlyWeight : public IFlyWeight
{
public:
	ConcreteFlyWeight(std::string strName);
	~ConcreteFlyWeight();


	void Display() override;
	void Add(IFlyWeight* ptrflyWeight)override;


private:
	std::string m_strName;
	IFlyWeight* m_ptrflyWeight;
};



//! 非享元部分，这部分是可能随时变化的不能作为共享的来用,只能够在客户端中使用
//! 一个非享元部分可以拆分成多个享元部分
class ConcreteUnFlyWeight : public IFlyWeight
{
public:
	ConcreteUnFlyWeight(std::string strName);
	~ConcreteUnFlyWeight();

	void Display() override;
	void Add(IFlyWeight* ptrflyWeight)override;


private:

	std::string m_strName;
	IFlyWeight* m_ptrflyWeight;
};



//! 享元工厂，用来管理享元类（内部状态）目前暂时用单利模式来实现。
class FlyweightFactory final
{
public:
	
	static FlyweightFactory& GetInstance();
	IFlyWeight* GetFlyWeight(std::string strName);
	void Destory();

private:
	FlyweightFactory() = default;
	~FlyweightFactory() = default;

	FlyweightFactory(const FlyweightFactory&) = delete;
	FlyweightFactory& operator = (const FlyweightFactory&) = delete;
	

private:

	//! 存放享元对象的容器
	static std::map<std::string, IFlyWeight*>  m_flyweight;
	static std::mutex  m_mutex;
};





void TestFlyWeight();