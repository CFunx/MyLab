#pragma once
#include <iostream>

/**
  定义一系列操作的步骤，这些操作步骤的实现可以选择在子类中进行实现或者是扩展
*/



//! 框架类主要是用来提供相应的操作以及相关的默认实现，与此同时其方法可以被子类的代替
class CFramework
{
public:
	CFramework();
	 virtual ~CFramework();
	
	 virtual void Step1();
	 virtual void Step2();
	 virtual void Step3();
};



//! 操作步骤的覆盖类
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