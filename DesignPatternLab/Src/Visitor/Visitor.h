#pragma once

#include<vector>
#include<iostream>


class ConcreteCustomerA;
class ConcreteCustomerB;


/**
* ��Բ�ͬ����Я����ͬ��ʵ�ַ���������Ӧ����ʹ��.
  ʵ�����������һ��Ŀ�ľ��ǽ��仯�Ĳ��ֵ����ó������е�����ƣ��Դ�����Ӧ����ı仯
  �����������ں����ά��
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
