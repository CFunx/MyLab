#pragma once
#include <iostream>
#include <list>
#include <map>

/**
*  ״̬ģʽ�����ǽ�״̬��״̬��ѡ����Ϊ���뿪����
*  �����ȿ���������Ӧ����չ��ͬʱ�����˿�ά����
* 
*/


//! ״̬�ĳ�����
class IStste
{
public:
	virtual void Handle(std::string strStateID) = 0;

};



//! �����״̬A
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


//! ״̬�������ģ�������������ά����Ӧ��״̬ͬʱ��һЩ״̬������
class ContextState
{
public:
	ContextState() = default;
	~ContextState() = default;
	
	//! ����״̬ ��ʼ����Ӧ��״̬
	bool Init(std::string strStateA, std::string strStateB);

	//! ������Ӧ��״̬
	bool Destory();

	void MakeChoice(std::string strStateID);

private:

	std::map<std::string, IStste* > m_state;

};



void TestState();