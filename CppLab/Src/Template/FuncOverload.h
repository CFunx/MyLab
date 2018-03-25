#pragma once
#include<iostream>

template<typename T>
inline T* const& max(T* const& a, T* const& b)
{
	printf("%d\n", *a);
	return *a > *b ? a : b;
}


template<typename T>
inline T max(T  a, T  b)
{
	printf("%d\n", a);
	return a > b ? a : b;
}


//! ģ�����Ϊ��Ĭ��ֵ
template<typename T = int>
inline T* const& min(T* const& a, T* const& b)
{
	printf("%d\n", *a);
	return *a > *b ? b : a;
}

template<typename T>
inline T const& min(T const& a, T const& b)
{
	printf("%d\n", a);
	return a > b ? a : b;
}


void TestFuncOverload();