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

}