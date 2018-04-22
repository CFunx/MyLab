#include "FuncOverload.h"

void TestFuncOverload()
{
	const int a = 40;
	const int b = 60;
	
	const int* const pa = &a;
	const int* const pb = &b;

	 //! ����ȫ�ֱ����е�max()����
	::max(pa, pb);
	
	//! �����ȵ��÷�ģ�庯��������ǿ�Ƶ���ģ��
	::max<>(12, 4);

	//! ʣ���ģ������Լ��Ƶ�
	::max<int>(3, 1);

	::min(a, b);

	if (a)
	{
		std::cout << "1111\n";
	}
	
	//https://stackoverflow.com/questions/7460410/lvalue-to-rvalue-conversions
	//https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/
    //http://en.cppreference.com/w/cpp/language/implicit_conversion
    //http://en.cppreference.com/w/cpp/concept/PODType
}