#pragma once
#include <iostream>
#include <map>
#include <mutex>


/**
*  ��Ԫģʽ����Ҫ�ǽ�����Ĳ��ֺͱ仯�Ĳ��������������Ĳ�����Ϊ��Ԫ������
   ������Ĳ�����Ϊ���ǹ���Ĳ��֣���ʱ����Ĳ��ֿ�����Ҫ�õ��ǹ���Ĳ��֡�
   ����Ĳ���ͨ��һ�����������й����ͻ�����ʹ�õ�ʱ��ȿ���ʹ�ù���Ĳ���Ҳ
   ��ʹ�ù���Ĳ��֡�
*/


//! ��Ԫ������
class IFlyWeight
{
public:
	virtual void Display() = 0;

	//! ͨ���˽ӿ���Ԫ/����Ԫ���ֿ��Ե��������Ľӿ�
	virtual void Add(IFlyWeight*  ptrflyWeight) = 0;
};


//! ��Ԫ����ʵ����
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



//! ����Ԫ���֣��ⲿ���ǿ�����ʱ�仯�Ĳ�����Ϊ���������,ֻ�ܹ��ڿͻ�����ʹ��
//! һ������Ԫ���ֿ��Բ�ֳɶ����Ԫ����
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



//! ��Ԫ����������������Ԫ�ࣨ�ڲ�״̬��Ŀǰ��ʱ�õ���ģʽ��ʵ�֡�
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

	//! �����Ԫ���������
	static std::map<std::string, IFlyWeight*>  m_flyweight;
	static std::mutex  m_mutex;
};





void TestFlyWeight();