#include "TemplateClass.h"


void CTmpCl<double>::DisPlay(double t)
{
	std::cout << __func__ << "DisPlay(double t) \n";
}


void TestCTmpCl()
{
	int n = 2;
	int m = 3;

	//! 创建对象1
	CTmpCl<int> obj1(n);

	CTmpCl<int> obj2(obj1);

	CTmpCl<int> obj3 = obj1;

	obj2 = obj3;

	CTmpCl<double> obj4;
	obj4.DisPlay(1.0);
}