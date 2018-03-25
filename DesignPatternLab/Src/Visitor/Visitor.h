#pragma once

#include<vector>
#include<iostream>


class ConcreteCustomerA;
class ConcreteCustomerB;


/**
* 针对不同的类携带不同的实现方法来给相应的类使用.
  实际上设计其中一个目的就是将变化的部分单独拿出来进行单独设计，以此来适应需求的变化
  这样更有利于后面的维护
*/
class IVisitor
{
public:
	virtual void HandleCustomerA (ConcreteCustomerA* ca) = 0;
	virtual void HandleCustomerB (ConcreteCustomerB* cb) = 0;
};



class ConcreteVistorA : public IVisitor
{
public:
	void HandleCustomerA (ConcreteCustomerA* ca) override;
	void HandleCustomerB (ConcreteCustomerB* cb) override;
	
};


class ConcreteVistorB : public IVisitor
{
public:
	void HandleCustomerA (ConcreteCustomerA* ca) override;
	void HandleCustomerB (ConcreteCustomerB* cb) override;
	
};



class ICustomer
{
public:
	virtual void Accept(IVisitor* visitor) = 0;
};



class ConcreteCustomerA : public ICustomer
{
public:
	void Accept(IVisitor* visitor) override;
	void Show();
	
};


class ConcreteCustomerB : public ICustomer
{
public:
	void Accept(IVisitor* visitor) override;
	void Show();
};


class CustomerContainers
{
public:

	CustomerContainers() = default;
	~CustomerContainers();


	void AddCustomer(ICustomer* customer);
	void HandleRequest(IVisitor* vistor);
	

private:

	std::vector<ICustomer*>  m_customers;

};


void TestVisitor();
