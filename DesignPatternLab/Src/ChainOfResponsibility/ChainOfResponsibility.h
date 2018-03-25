#pragma once
#include <iostream>

/**
  \brief ������ģʽ����Ҫ�ǽ�һ�������ڲ�ͬ�Ĵ������д�����ȥ
         �ڿ�ÿһ��ģʽ��ʱ����Ҫ�ǿ�����ģʽ��ôӦ����ص�����任��
		 �Լ���Ӧ�Ա仯ʱ��Ŀ���չ����Ӧ��ά���ɱ�������������
*/


//! ����Task��ͳһ�ӿ�
class ITasks
{
public:
	void SetTaskType(std::string strTaskType);
	std::string GetTaskType();
private:

	std::string m_strTaskType;
};

class IHandler
{
public:
	virtual void SetHandler(IHandler* handler) = 0;
	virtual void HandleTask(ITasks& tasks) = 0;
	virtual void SetTaskType(std::string strTaskType) = 0;
};


class HandlerA : public IHandler
{
public:
	HandlerA();
	virtual ~HandlerA();
	virtual void SetHandler(IHandler* handler)override;
	virtual void HandleTask(ITasks& tasks) override;
	virtual void SetTaskType(std::string strTaskType)override;
private:

	IHandler* m_handler;
	std::string m_strTaskType;

};



class HandlerB : public IHandler
{
public:
	HandlerB();
	virtual ~HandlerB();
	virtual void SetHandler(IHandler* handler)override;
	virtual void HandleTask(ITasks& tasks)override;
	virtual void SetTaskType(std::string strTaskType) override;
private:
	IHandler* m_handler;
	std::string m_strTaskType;
};



void TestChainOfResponsibility();






