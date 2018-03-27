#pragma once
#include <iostream>

/**
*  װ����ģʽ����Ҫ�Ƕ�̬�ĸ���װ���������صĹ��ܣ�
*/



//! ��װ�����
class IComponent
{
public:
	virtual void SomeOperation(std::string strContent) = 0;
};


class ComponentA : public IComponent
{
public:
	void SomeOperation(std::string strContent) override;
};



class ComponentB : public IComponent
{
public:
	void SomeOperation(std::string strContent) override;
};




//! װ����
class IDecorator : public IComponent
{
public:
	IDecorator(IComponent* Component);
	virtual ~IDecorator();

	void SomeOperation(std::string strContent) override;

	void Show(std::string strName);


protected:

	IComponent* m_Component;
};


class DecoratorA : public IDecorator
{
public:
	DecoratorA(IComponent* Component);
	virtual ~DecoratorA();

	void SomeOperation(std::string strContent)override;
	void ShowA(std::string);

};



class DecoratorB : public IDecorator
{
public:
	DecoratorB(IComponent* Component);
	virtual ~DecoratorB();

	void SomeOperation(std::string strContent)override;
	void ShowB(std::string strContent);

};



void TestDecorator();