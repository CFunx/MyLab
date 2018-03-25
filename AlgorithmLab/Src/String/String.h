#pragma once



//TODO:没有必要将宽字符和窄字符的方法都写一遍
//各种错误处理用enum 类型的方式返回以便于知道其准确意思

class String  final
{
public:

	//BF
	template <typename  T>
	int findStrT(const T* src, const T* dest);

	//KMP
	template <typename  T>
	int findStrKMPT(const T* src, const T* dest);


private:

	//BF:简单朴素算法
	int findStr(const char* src, const char* dest);
	int findStr(const wchar_t* src, const wchar_t* dest);

	//KMP
	int findStr_kmp(const char* src, const char* dest);
	int findStr_kmp(const wchar_t* src, const wchar_t* dest);
	int* mkNext(const char* patternstr);
	int* mkNext(const wchar_t* patternstr);


};


template <typename  T>
int String::findStrT(const T* src, const T* dest)
{
	int  ret = findStr(src, dest);
	return  ret;
}


template <typename  T>
int String::findStrKMPT(const T* src, const T* dest)
{
	int ret = findStr_kmp(src, dest);
	return  ret;
}