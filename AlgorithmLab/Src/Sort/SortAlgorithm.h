#pragma  once

class SortAlgorithm
{
public:

	//冒泡排序
	template<typename T>
	void BubbleSort(T *Array, unsigned int nItem);

	//shell 排序
	template <typename T>
	void ShellSort(T *Array,  int nItem);

	//shell排序的另一种实现方式
	//此种方式采用的是交换的方式来代替赋值
	// 此种方式在理解上比上shellSort 好理解
	// 但是速度上略慢于shellSort
	template <typename T>
	void ShellSort2(T *Array, int nItem);


	//此种方式采用Sedgewick 递增序列
	template <typename T>
	void ShellSortWithSedgewick(T *Array, int nItem);


	//插入排序
	template<typename T>
	void InsertSort(T *Array,  int nItem);

	//简单选择排序
	template<typename T>
	void SimpleSelectSort(T *Array, unsigned int nItem);


	//快速排序
	template <typename T>
	void QuickSort(T *Array, unsigned int nLow, unsigned int nHigh);


	//支点的寻找
	template<typename T>
	size_t  Pivotkey(T *Array, unsigned int nLow, unsigned int nHigh);


	//堆排序
	template <typename T>
	void HeapSort(T *arry, size_t arraysize);


	//建堆
	template <typename T>
	void  BuildHeap(T *arry, size_t arraysize);


	//保持最大堆性质
	template <typename T>
	void  MaxHeapify(T *arry, size_t arraysize, size_t location);


    /******************** 归并排序有点bug 还需要进一步的纠正下***********/

	//归并排序
	template<typename T>
	void MergeSort(T *src, int len);

	template<typename T>
	void MergePass(T *src, T *dest, int lenstep, int len);


	template<typename T>
	void Merge(T *src, T *dest, int start,  int mid, int end);


	/************************线性排序************************/

	//计数排序（此种排序只能用于正整数的排序而且还必须知道所有要排序的最大值）其适用范围略低
	template <typename T>
	void CountingSort(T *arry, size_t arrylen, T maxvalue);

};




///////////////////实现//////////////////////

//此算法一个比较明显的缺点就是当数组中只有数量较少的元素而且元素的值还比较大的时候
//就会造成极大空间浪费和时间上也会比较大所以此算法适合元素数量较多且均匀分布的情况下用
//要排序的算法是从数组下标为1的情况开始排列的
template <typename T>
void SortAlgorithm::CountingSort(T* arry, size_t arrylen, T maxvalue)
{
	assert(arry != nullptr);
	if ((arrylen<=2)||maxvalue<1) { return; }

	if (3==arrylen)
	{
		if (arry[1]>arry[2])
		{
			swap(arry[1], arry[2]);
			return;
		}
		else
		{
			return;
		}
	}

	T* resultarry = new T[arrylen];
	assert(nullptr != resultarry);
	memset(resultarry, 0, ( arrylen*sizeof(T))  );
	
	T* assistarry = new T[maxvalue + 1];
	assert(nullptr != assistarry);
	memset(assistarry, 0, (maxvalue + 1) * sizeof(T));


	//统计要排序数值的个数
	for (size_t i = 1; i < arrylen;i++)
	{
		assistarry[arry[i]] += 1;
	}

	//统计某个数值在排好序数组中的位置
	//TODO:为啥 下面的 int 用size_t 来代替后就会报错 
	for (int j = 1; j <= maxvalue;j++)
	{
		assistarry[j] += assistarry[j - 1];
	}

	//根据辅助数组assistarry将数值排好序放在结果数组中resultarry
	for (size_t n = arrylen - 1; n >= 1; n--)
	{
		//首先在arry数组中找到要排序的数字即 m=arry[n],然后辅助数组中（assistarry）中查找m在结果数组中的位置l
		//然后将arry[n] 放在结果数组中l的位置
		// 最后将辅助数组中l的值减1
		resultarry[assistarry[ arry[n] ] ] = arry[n];
		assistarry[arry[n]] -= 1;
	}

	for (size_t m = 1; m < arrylen;m++)
	{
		arry[m] = resultarry[m];
	}

	delete [] resultarry;
	delete [] assistarry;
}




//冒泡排序
template<typename T>
void SortAlgorithm::BubbleSort(T *Array, unsigned int nItem)
{
	assert(Array != NULL);
	if (nItem <= 1)return;
	
	bool   changeflag = true;
	size_t changelocation = nItem - 1;
	size_t temploaction;
	for (size_t i = 0; (i < nItem - 1) && (changeflag); i++)
	{
		changeflag = false;
		for (size_t j = 0; j <changelocation; j++)
		{
			if (Array[j]>Array[j + 1])
			{
				swap(Array[j], Array[j + 1]);
				changeflag = true;
				temploaction = j;
			}
		}
		changelocation = temploaction;
	}
}


//shell排序
template <typename T>
void SortAlgorithm::ShellSort(T *Array,  int nItem)
{
	assert(Array != NULL);
	if (nItem <= 1)return;
	
	T tempnum;
	int gap=nItem>>1;
	int  i = gap;
    int  j = i - gap;
		 
	for ( ;gap>0 ; gap=gap >> 1)
	{
		for (i=gap; i < nItem; i++)
		{
			tempnum = Array[i];
			
			for (j=i-gap ;(j>=0)&&(tempnum<Array[j]) ; j-=gap)
			{
				//之所以用j+gap 而不直接用i是因为如果用i 
				//i是一直不变的 影响结果所以必须用j+gap
				Array[j + gap] = Array[j];
            }
			Array[j + gap] = tempnum;
		}
	}
}



//此方法是shellsort的变种用交换代替赋值比较好理解
//但是效率略低
template <typename T>
void SortAlgorithm::ShellSort2(T *Array, int nItem)
{
	assert(Array != NULL);
	if (nItem <= 1)return;
	
	 int gap = nItem >> 1;
	 int  i = gap;
	 int  j = i - gap;

	//分组
	for (; gap > 0; gap = gap >> 1)
	{
		//对每个分组进行排序
		for (i = gap; i < nItem; i++)
		{
			for (j = i - gap; (j >= 0) && (Array[j+gap]< Array[j]); j -= gap)
			{
				//交换耗时比较大
				swap(Array[j + gap], Array[j]);
			}	
		}
	}
}





//利用sedgewick递增序列进行shell排序
//递增序列4^k+3*2^k-1+1
template <typename  T>
void SortAlgorithm::ShellSortWithSedgewick(T *Array,  int nItem)
{
	assert(Array != nullptr);
	if (nItem<=1)return;
	
	vector<int> gap;
	gap.push_back(1);
	int  gapindex = 1;

	//取得步长序列
	while (gapindex)
	{  
		//TODO:为啥这里不进行 强制转换就会在编译的时候出现一大堆警告？
		int  gapnum = (int)( (pow(4, gapindex)) + (3 * (pow(2, gapindex - 1))) + 1 );

		gapindex++;
		if (gapnum >nItem)
		{
			break;
		}
		else
		{
			gap.push_back(gapnum);
		}
	}

	int  gapsize = gap.size();

	T tempnum;
	int  i ,j;
	int realgap;

	for (; gapsize >0; gapsize--)
	{
		realgap = gap[gapsize-1];

		for (i = realgap; i < nItem; i++)
		{
			tempnum = Array[i];

			for (j = i - realgap; (j >= 0) && (tempnum < Array[j]); j -=realgap)
			{
				Array[j + realgap] = Array[j];
			}
			Array[j + realgap] = tempnum;
		}
	}
}



//插入排序
template<typename T>
void SortAlgorithm::InsertSort(T *Array,  int nItem)
{
	assert(Array != NULL);
	if (nItem <= 1)return;
	
	T tempbuf;
	for ( int i = 1; i < nItem; i++)
	{
		tempbuf = Array[i];
		int j;
		for (j = i - 1; tempbuf < Array[j] && j>=0; j--)
		{
			Array[j + 1] = Array[j];
		}
		Array[j + 1] = tempbuf;
	}
}


//简单选择排序
template<typename T>
void SortAlgorithm::SimpleSelectSort(T *Array, unsigned int nItem)
{
	assert(NULL != Array);
	if (nItem <= 1) return;
	size_t max = 0;
	for (size_t i = 0; i < nItem; i++)
	{
		max = i;
		for (size_t j = i + 1; j < nItem; j++)
		{
			if (Array[j] < Array[i])
			{
				max = j;
			}
		}
		if (max != i)
		{
			swap(Array[max], Array[i]);
		}
	}
}




//快速排序
template <typename T>
void SortAlgorithm::QuickSort(T *Array, unsigned int nLow, unsigned int nHigh)
{
	assert((Array != NULL) || (nLow > nHigh));
	if ((nHigh - nLow) <= 1)return;

	size_t Pivot;
	while (nLow < nHigh)
	{
		Pivot = Pivotkey(Array, nLow, nHigh);
		QuickSort(Array, nLow, Pivot - 1);
		nLow = Pivot + 1;
	}
}



//快速排序寻找支点位置
template<typename T>
size_t SortAlgorithm::Pivotkey(T *Array, unsigned int nLow, unsigned int nHigh)
{
	unsigned int Low = nLow;
	unsigned int High = nHigh;

	//开始假设数组的最低点是支点
	T tempivot = Array[Low];
	while (Low < High)
	{
		while ((Low < High) && (tempivot <= Array[High]))
		{
			High--;
		}
		Array[Low] = Array[High];
		while ((Low < High) && (tempivot >= Array[Low]))
		{
			Low++;
		}
		Array[High] = Array[Low];
	}
	Array[Low] = tempivot;
	return Low;
}




//归并排序
template<typename T>
void SortAlgorithm::MergeSort(T *src, int len)
{
	assert((src != NULL));

	T *dest = new T[len];
	if (dest == NULL)return;
	
	int lenstep = 1;
	while (lenstep < len)
	{
		MergePass(src, dest, lenstep, len);
		lenstep = 2 * lenstep;
	}
	delete[]dest;
}



template<typename T>
void SortAlgorithm::MergePass(T *src, T *dest, int lenstep, int len)
{
	assert(lenstep < len);

	int beginLocation = 0;
	while (beginLocation <= len - 2 * lenstep)
	{
		cout << beginLocation << endl;
		Merge(src, dest, beginLocation, beginLocation + lenstep - 1, beginLocation + (2 * lenstep) - 1);
		beginLocation = beginLocation + (2 * lenstep);
	}
	if (beginLocation < len - lenstep + 1)
	{
		Merge(src, dest, beginLocation, beginLocation + lenstep - 1, len);
	}
	else
	{
		for (int i = beginLocation; i <= len; i++)
		{
			dest[i] = src[i];
		}
	}

	for (int i = 0; i < len; i++)
	{
		src[i] = dest[i];
	}
}


template<typename T>
void SortAlgorithm::Merge(T *src, T *dest, int start, int mid, int end)
{
	assert((src != NULL));
	int desthead = start;
	int srchead = start;
	int midhead = mid + 1;
	while ((srchead <= mid) && (midhead <= end))
	{
		if (src[srchead] < src[midhead])
		{
			dest[desthead++] = src[srchead++];
		}
		else
		{
			dest[desthead++] = src[midhead++];
		}
	}
	if (srchead <= mid)
	{
		while (srchead <= mid)
		{
			dest[desthead++] = src[srchead++];
		}
	}
	else
	{
		while (midhead <=end)
		{
			dest[desthead++] = src[midhead++];
		}
	}
}


//数据的操作是从数组的下标为1的情况开始的
//所以在输入的时候注意下
template <typename T>
void SortAlgorithm::HeapSort(T *arry, size_t arraysize)
{
	//当表达式的值是0的时候才会成立
	assert((arry != nullptr) && (arraysize >0));

	size_t  temparraysize = arraysize-1;
	size_t  Index = arraysize-1;
	BuildHeap(arry, temparraysize);
	for (; Index >0;Index--)
	{
		swap(arry[1], arry[temparraysize]);
		temparraysize--;
		MaxHeapify(arry, temparraysize, 1);
	}
}




//建堆
template <typename T>
void SortAlgorithm::BuildHeap(T *arry, size_t arraysize)
{
	size_t temparraysize = arraysize;
	size_t nheaphead = temparraysize >> 1;

	for (; nheaphead >0; nheaphead--)
	{
		MaxHeapify(arry, temparraysize, nheaphead);
	}
}


//堆排序保持最大堆性质
//location 的大小是由上层来保证其正确性
template <typename T>
void SortAlgorithm::MaxHeapify(T *arry, size_t arraysize, size_t location)
{
	size_t  nheapleft = 0;
	size_t  nheapright = 0;
	size_t  nheaphead = location;
	size_t  ntempheaphead =0;

	do 
	{
		ntempheaphead = nheaphead;

		nheapleft = nheaphead << 1;
		nheapright = (nheaphead << 1) + 1;
		if (((nheapleft<=arraysize)) &&(arry[nheapleft]>arry[nheaphead]))
		{
			nheaphead = nheapleft;
		}
		if (((nheapright <=arraysize)) && (arry[nheapright]>arry[nheaphead]))
		{
			nheaphead = nheapright;
		}

		if (nheaphead!=ntempheaphead)
		{
			swap(arry[nheaphead], arry[ntempheaphead]);
		}

	} while (nheaphead!=ntempheaphead);
}

