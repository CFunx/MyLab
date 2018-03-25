#pragma  once

class CSearch
{
public:

	template<typename  T>
	long BinarySearch(const T * arry, size_t arrylen, T target);


	//查找第一个大于或等于某个元素的位置。
	template<typename  T>
	long LowBound(const T * arry, size_t arrylen, T target);


	//查找第一个大于某个元素的位置
	template<typename  T>
	long HighBound(const T * arry, size_t arrylen, T target);
};




//二分查找
//输入要查找的序列必须是有序的
//把所有的要找的元素都找出来呢还是只找一个呢?
template <typename T>
long CSearch::BinarySearch(const T* arry, size_t arrylen, T target)
{
	assert((arry != nullptr) && (arrylen >= 0));
	if (1==arrylen)
	{
		if (arry[0] == target)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	size_t  Begin = 0;
	size_t  End = arrylen - 1;
	size_t  Mid ;

	while (Begin<=End)
	{
		//防止溢出
		Mid =Begin + ( (End-Begin) >> 1);
		if (target==arry[Mid])
		{
			return Mid;
		}
		else if (target<arry[Mid])
		{
			End = Mid - 1;
		}
		else
		{
			Begin = Mid + 1;
		}
	}
	return -1;
}


template <typename  T>
long CSearch::LowBound(const T * arry, size_t arrylen, T target)
{
	assert((arry != nullptr) && (arrylen >= 0));
	if (1 == arrylen)
	{
		if( arry[0] >= target)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	//用来存放一个元素的下标
	long  templocation=-1;

	size_t  Begin = 0;
	size_t  End = arrylen - 1;
	size_t  Mid;

	while (Begin<End)
	{
		Mid = Begin + ( (End - Begin) >> 1 );
		if (arry[Mid]>=target)
		{
			End = Mid;
			templocation = Mid;
		}
		else
		{
			Begin = Mid + 1;

			//有可能Mid+1 就是第一个大于Target的数目
			templocation = Begin;
		}
	}
	return templocation;
}



//感觉和上面的方法重复率非常高
template <typename  T>
long CSearch::HighBound(const T * arry, size_t arrylen, T target)
{
	assert((arry != nullptr) && (arrylen >= 0));
	if (1 == arrylen)
	{
		if (arry[0]  >= target)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	//用来存放一个元素的下标
	long  templocation = -1;

	size_t  Begin = 0;
	size_t  End = arrylen - 1;
	size_t  Mid;

	while (Begin < End)
	{
		Mid = Begin + ( (End - Begin) >> 1 );
		if (arry[Mid] >target)
		{
			End = Mid;
			templocation = Mid;
		}
		else
		{
			Begin = Mid + 1;
			templocation = Begin;
		}
	}
	return templocation;
}


