#include "../stdafx.h"
#include "String.h"


int String::findStr(const char* src, const char* dest)
{
	if (!(src && dest)) return -1;

    size_t srclen  = strlen(src);
	size_t destlen = strlen(dest);

	if (srclen < destlen) return -3;

	size_t i = 0;
	size_t j = 0;

	while (src[i]!='\0' && dest[j]!='\0')
	{
		if (src[i++] == dest[j++]);
		else 
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (dest[j]=='\0')
	{
		size_t matchindex = i - j + 1;
		return matchindex;
	}
	else
	{
		return -2;
	}
}


int String::findStr(const wchar_t* src, const wchar_t* dest)
{
	if (!(src && dest)) return -1;

	size_t srclen = wcslen(src);
	size_t destlen = wcslen(dest);

	if (srclen < destlen) return -3;

	size_t i = 0;
	size_t j = 0;

	while (src[i] != L'\0' && dest[j] != L'\0')
	{
		if (src[i++] == dest[j++]);
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (dest[j] == L'\0')
	{
		size_t matchindex = i - j + 1;
		return matchindex;
	}
	else
	{
		return -2;
	}
}


int String::findStr_kmp(const char* src, const char* dest)
{
	if (!(src && dest)) return -1;

	int srclen = strlen(src);
	int destlen = strlen(dest);

	if (srclen < destlen) return -3;

	if (destlen == 1)
	{
		return findStr(src, dest);
	}

	int *pNext = mkNext(dest);

	if (!pNext)return -4;


	int srclcal = 0;
	int destlcal = 0;

	while ( (srclcal < srclen) && (destlcal < destlen) )
	{
		if (destlcal==-1 || src[srclcal]== dest[destlcal])
		{
			srclcal++;
			destlcal++;
		}
		else
		{
			destlcal = pNext[destlcal];
		}
	}

	
	if (destlcal== destlen)
	{
		delete[]pNext;
		pNext = nullptr;

		//返回匹配的位置
		return srclcal - destlcal;
	}
	else
	{
		delete[]pNext;
		pNext = nullptr;
		return -1;
	}
}


int String::findStr_kmp(const wchar_t* src, const wchar_t* dest)
{

	if (!(src && dest)) return -1;

	int srclen = wcslen(src);
	int destlen = wcslen(dest);

	if (srclen < destlen) return -3;

	if (destlen == 1)
	{
		return findStr(src, dest);
	}

	int *pNext = mkNext(dest);

	if (!pNext)return -4;


	int srclcal = 0;
	int destlcal = 0;

	while ((srclcal < srclen) && (destlcal < destlen))
	{
		if (destlcal == -1 || src[srclcal] == dest[destlcal])
		{
			srclcal++;
			destlcal++;
		}
		else
		{
			destlcal = pNext[destlcal];
		}
	}


	if (destlcal == destlen)
	{
		delete[]pNext;
		pNext = nullptr;

		//返回匹配的位置
		return srclcal - destlcal;
	}
	else
	{
		delete[]pNext;
		pNext = nullptr;
		return -1;
	}
}





int* String::mkNext(const char* patternstr)
{
	if (!patternstr) { return nullptr; }
	int patlen = strlen(patternstr);

	int *next =new int[patlen];
	assert(next);
	memset(next, 0, sizeof(int)*patlen);

	next[0] = -1;

	//最大前缀/后缀的匹配长度
	int matchlen = -1;

	//匹配的位置也就是说
	int matchlcal = 0;

	while (matchlcal < patlen-1)
	{
		//如果是开始匹配的是第一个字符 或者是说将要匹配的前后缀相等
		if (matchlen == -1 || patternstr[matchlen]==patternstr[matchlcal])
		{
			++matchlen;
			++matchlcal;

			if (patternstr[matchlen] != patternstr[matchlcal])
			{
				next[matchlcal] = matchlen;
			}
			else
			{

				next[matchlcal] = next[matchlen];
			}
		}
		else
		{
			matchlen = next[matchlen];
		}
	}

	return next;
}


int* String::mkNext(const wchar_t* patternstr)
{
	if (!patternstr) { return nullptr; }
	int patlen = wcslen(patternstr);

	int *next = new int[patlen];
	assert(next);
	memset(next, 0, sizeof(int)*patlen);

	next[0] = -1;

	//最大前缀/后缀的匹配长度
	int matchlen = -1;

	//匹配的位置也就是说
	int matchlcal = 0;

	while (matchlcal < patlen - 1)
	{
		//如果是开始匹配的是第一个字符 或者是说将要匹配的前后缀相等
		if (matchlen == -1 || patternstr[matchlen] == patternstr[matchlcal])
		{
			++matchlen;
			++matchlcal;

			if (patternstr[matchlen] != patternstr[matchlcal])
			{
				next[matchlcal] = matchlen;
			}
			else
			{

				next[matchlcal] = next[matchlen];
			}
		}
		else
		{
			matchlen = next[matchlen];
		}
	}

	return next;
}