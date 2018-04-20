#include "Util.h"
#include <cassert>
#include <limits.h>



//! 出现异常怎么处理？？
int CUtil::Atoi(const char* str)
{
	assert(str != nullptr);
	
	//! 以空格开始的
	while (*str == 32)
	{
		str++;
	}

	int sign = 1;
	int c = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}

	int sum = 0;
	
	//! 结束符问题 
	while (*str >= '0' && *str <= '9' && *str)
	{ 
		c = *str - '0';
		if (sign > 0 && (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && (c > INT_MAX % 10))))
		{
			return INT_MAX;
		}
		if (sign < 0 && (sum > -(INT_MIN / 10) || (sum == -(INT_MIN / 10) && (c > -(INT_MIN % 10)))))
		{
			return INT_MAX;
		}

		sum *= 10;
		sum += c;
		str++;
	}
	return sign * sum;
}