#pragma once
#include <iostream>
#include <list>
#include <map>

/**
*  状态模式，就是将状态和状态的选择行为分离开来。
*  这样既可以做到相应的扩展性同时增加了可维护性
* 
*/


//! 状态的抽象类
class IStste
{
public:
	virtual void Handle(std::string strStateID) = 0;

};



//! 具体的状态A
class ConcreteStateA : public IStste
{
public:
	ConcreteStateA() = default;
	~ConcreteStateA() = default;

	void Handle(std::string strStateID) override; 
};


class ConcreteStateB : public IStste
{
public:
	ConcreteStateB() = default;
	~ConcreteStateB() = default;

	void Handle(std::string strStateID) override;
};


//! 状态的上下文，这个类可以用来维护相应的状态同时做一些状态抉择动作
class ContextState
{
public:
	ContextState() = default;
	~ContextState() = default;
	
	//! 根据状态 初始化相应的状态
	bool Init(std::string strStateA, std::string strStateB);

	//! 销毁相应的状态
	bool Destory();

	void MakeChoice(std::string strStateID);

private:

	std::map<std::string, IStste* > m_state;

};



void TestState();