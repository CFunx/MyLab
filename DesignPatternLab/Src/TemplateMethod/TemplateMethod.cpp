#include "TemplateMethod.h"

CFramework::CFramework()
{
	std::cout << __func__ << std::endl;
}


CFramework::~CFramework()
{
	std::cout << __func__ << std::endl;
}


void CFramework::Step1()
{
	std::cout <<"I am CFramework::Step1"<< std::endl;
}

void CFramework::Step2()
{
	std::cout << "I am CFramework::Step3" << std::endl;
}

void CFramework::Step3()
{
	std::cout << "I am CFramework::Step3" << std::endl;
}



void CFrameExtendsA::Step1()
{
	std::cout << "I am [CFrameExtendsA]::Step1" << std::endl;
}

void CFrameExtendsA::Step2()
{
	std::cout << "I am [CFrameExtendsA]::Step2" << std::endl;
}

void CFrameExtendsB::Step3()
{
	std::cout << "I am --CFrameExtendsB--::Step3" << std::endl;
}


void TestTemplateMethod()
{
	CFramework* f = new CFrameExtendsA();
	CFramework* f1 = new CFrameExtendsB();

	f->Step1();
	f->Step2();
	f->Step3();


	f1->Step1();
	f1->Step2();
	f1->Step3();

	delete f;
	f = nullptr;

	delete f1;
	f1 = nullptr;
}