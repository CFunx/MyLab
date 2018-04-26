#pragma once
#include <iostream>

/**
  ����һϵ�в����Ĳ��裬��Щ���������ʵ�ֿ���ѡ���������н���ʵ�ֻ�������չ
*/



//! �������Ҫ�������ṩ��Ӧ�Ĳ����Լ���ص�Ĭ��ʵ�֣����ͬʱ�䷽�����Ա�����Ĵ���
class CFramework
{
public:
	CFramework();
	 virtual ~CFramework();
	
	 virtual void Step1();
	 virtual void Step2();
	 virtual void Step3();
};



//! ��������ĸ�����
class CFrameExtendsA : public CFramework
{
public:
	CFrameExtendsA() = default;
	~CFrameExtendsA() = default;

	void Step1() override;
	void Step2() override;
};


class CFrameExtendsB : public CFramework
{
public:
	CFrameExtendsB() = default;
	~CFrameExtendsB() = default;

	void Step3() override;
};


void TestTemplateMethod();