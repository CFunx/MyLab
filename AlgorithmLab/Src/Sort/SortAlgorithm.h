#pragma  once

class SortAlgorithm
{
public:

	//ð������
	template<typename T>
	void BubbleSort(T *Array, unsigned int nItem);

	//shell ����
	template <typename T>
	void ShellSort(T *Array,  int nItem);

	//shell�������һ��ʵ�ַ�ʽ
	//���ַ�ʽ���õ��ǽ����ķ�ʽ�����渳ֵ
	// ���ַ�ʽ������ϱ���shellSort �����
	// �����ٶ���������shellSort
	template <typename T>
	void ShellSort2(T *Array, int nItem);


	//���ַ�ʽ����Sedgewick ��������
	template <typename T>
	void ShellSortWithSedgewick(T *Array, int nItem);


	//��������
	template<typename T>
	void InsertSort(T *Array,  int nItem);

	//��ѡ������
	template<typename T>
	void SimpleSelectSort(T *Array, unsigned int nItem);


	//��������
	template <typename T>
	void QuickSort(T *Array, unsigned int nLow, unsigned int nHigh);


	//֧���Ѱ��
	template<typename T>
	size_t  Pivotkey(T *Array, unsigned int nLow, unsigned int nHigh);


	//������
	template <typename T>
	void HeapSort(T *arry, size_t arraysize);


	//����
	template <typename T>
	void  BuildHeap(T *arry, size_t arraysize);


	//������������
	template <typename T>
	void  MaxHeapify(T *arry, size_t arraysize, size_t location);


    /******************** �鲢�����е�bug ����Ҫ��һ���ľ�����***********/

	//�鲢����
	template<typename T>
	void MergeSort(T *src, int len);

	template<typename T>
	void MergePass(T *src, T *dest, int lenstep, int len);


	template<typename T>
	void Merge(T *src, T *dest, int start,  int mid, int end);


	/************************��������************************/

	//�������򣨴�������ֻ��������������������һ�����֪������Ҫ��������ֵ�������÷�Χ�Ե�
	template <typename T>
	void CountingSort(T *arry, size_t arrylen, T maxvalue);

};




///////////////////ʵ��//////////////////////

//���㷨һ���Ƚ����Ե�ȱ����ǵ�������ֻ���������ٵ�Ԫ�ض���Ԫ�ص�ֵ���Ƚϴ��ʱ��
//�ͻ���ɼ���ռ��˷Ѻ�ʱ����Ҳ��Ƚϴ����Դ��㷨�ʺ�Ԫ�������϶��Ҿ��ȷֲ����������
//Ҫ������㷨�Ǵ������±�Ϊ1�������ʼ���е�
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


	//ͳ��Ҫ������ֵ�ĸ���
	for (size_t i = 1; i < arrylen;i++)
	{
		assistarry[arry[i]] += 1;
	}

	//ͳ��ĳ����ֵ���ź��������е�λ��
	//TODO:Ϊɶ ����� int ��size_t �������ͻᱨ�� 
	for (int j = 1; j <= maxvalue;j++)
	{
		assistarry[j] += assistarry[j - 1];
	}

	//���ݸ�������assistarry����ֵ�ź�����ڽ��������resultarry
	for (size_t n = arrylen - 1; n >= 1; n--)
	{
		//������arry�������ҵ�Ҫ��������ּ� m=arry[n],Ȼ���������У�assistarry���в���m�ڽ�������е�λ��l
		//Ȼ��arry[n] ���ڽ��������l��λ��
		// ��󽫸���������l��ֵ��1
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




//ð������
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


//shell����
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
				//֮������j+gap ����ֱ����i����Ϊ�����i 
				//i��һֱ����� Ӱ�������Ա�����j+gap
				Array[j + gap] = Array[j];
            }
			Array[j + gap] = tempnum;
		}
	}
}



//�˷�����shellsort�ı����ý������渳ֵ�ȽϺ����
//����Ч���Ե�
template <typename T>
void SortAlgorithm::ShellSort2(T *Array, int nItem)
{
	assert(Array != NULL);
	if (nItem <= 1)return;
	
	 int gap = nItem >> 1;
	 int  i = gap;
	 int  j = i - gap;

	//����
	for (; gap > 0; gap = gap >> 1)
	{
		//��ÿ�������������
		for (i = gap; i < nItem; i++)
		{
			for (j = i - gap; (j >= 0) && (Array[j+gap]< Array[j]); j -= gap)
			{
				//������ʱ�Ƚϴ�
				swap(Array[j + gap], Array[j]);
			}	
		}
	}
}





//����sedgewick�������н���shell����
//��������4^k+3*2^k-1+1
template <typename  T>
void SortAlgorithm::ShellSortWithSedgewick(T *Array,  int nItem)
{
	assert(Array != nullptr);
	if (nItem<=1)return;
	
	vector<int> gap;
	gap.push_back(1);
	int  gapindex = 1;

	//ȡ�ò�������
	while (gapindex)
	{  
		//TODO:Ϊɶ���ﲻ���� ǿ��ת���ͻ��ڱ����ʱ�����һ��Ѿ��棿
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



//��������
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


//��ѡ������
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




//��������
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



//��������Ѱ��֧��λ��
template<typename T>
size_t SortAlgorithm::Pivotkey(T *Array, unsigned int nLow, unsigned int nHigh)
{
	unsigned int Low = nLow;
	unsigned int High = nHigh;

	//��ʼ�����������͵���֧��
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




//�鲢����
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


//���ݵĲ����Ǵ�������±�Ϊ1�������ʼ��
//�����������ʱ��ע����
template <typename T>
void SortAlgorithm::HeapSort(T *arry, size_t arraysize)
{
	//�����ʽ��ֵ��0��ʱ��Ż����
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




//����
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


//�����򱣳���������
//location �Ĵ�С�����ϲ�����֤����ȷ��
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

