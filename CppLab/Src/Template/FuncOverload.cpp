#include "FuncOverload.h"

void TestFuncOverload()
{
	const int a = 40;
	const int b = 60;
	
	const int* const pa = &a;
	const int* const pb = &b;

	 //! 调用全局变量中的max()函数
	::max(pa, pb);
	
	//! 不优先调用非模板函数，而是强制调用模板
	::max<>(12, 4);

	//! 剩余的模板参数自己推导
	::max<int>(3, 1);

	::min(a, b);

}