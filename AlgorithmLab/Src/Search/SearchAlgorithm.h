#pragma  once

class CSearch
{
public:

	template<typename  T>
	long BinarySearch(const T * arry, size_t arrylen, T target);


	//���ҵ�һ�����ڻ����ĳ��Ԫ�ص�λ�á�
	template<typename  T>
	long LowBound(const T * arry, size_t arrylen, T target);


	//���ҵ�һ������ĳ��Ԫ�ص�λ��
	template<typename  T>
	long HighBound(const T * arry, size_t arrylen, T target);
};




//���ֲ���
//����Ҫ���ҵ����б����������
//�����е�Ҫ�ҵ�Ԫ�ض��ҳ����ػ���ֻ��һ����?
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
		//��ֹ���
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

	//�������һ��Ԫ�ص��±�
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

			//�п���Mid+1 ���ǵ�һ������Target����Ŀ
			templocation = Begin;
		}
	}
	return templocation;
}



//�о�������ķ����ظ��ʷǳ���
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

	//�������һ��Ԫ�ص��±�
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


