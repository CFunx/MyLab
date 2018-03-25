#pragma  once

template <typename T>
class CGraphic
{
public:
	
	//�ڽӾ��󷽷�����ͼ
	CGraphic(size_t nvertex, bool IsDirected = false);

	//ĳ����������
	int Indegree(const size_t &vertex);

	//ĳ������ĳ���
    int Outdegree(const size_t &vertex);

	//������ȱ���
	//vertex:��ʼ�����ڵ�
	bool DFSTraver(const size_t &vertex=0);

	void OutPutDFST();

	//������ȱ���
	bool BFSTraver(const size_t &vertex=0);

	//��ӡͼ��ʼ���ڽӾ���
	void print();

	//���ı���ߵ��������
	bool  ModifyEdge(size_t edgeend, size_t edgestart,const T &value);

private:

	//�������
    size_t m_nvertex;

	//��ű����󶥵������
	vector<T> m_traver;
	
	//��Ŷ�������
	vector <T>  m_vertex;

	//��űߵ�����
	vector<vector <T> > m_Matrix; 
};


//������ȱ���
template <typename  T>
bool CGraphic<T>::BFSTraver(const size_t &vertex/* =0 */)
{
	if (vertex > m_nvertex)
	{
		return false;
	}

	size_t tempvertex = vertex;
	queue<T> bfsqueue;

	bfsqueue.push(tempvertex);
	m_vertex[tempvertex] = 1;
	size_t walkerindex = 0;

	while (!bfsqueue.empty())
	{
		while (walkerindex < m_nvertex)
		{
			if (m_Matrix[tempvertex][walkerindex] != 0 && m_vertex[walkerindex] == 0)
			{
				bfsqueue.push(walkerindex);
				m_vertex[walkerindex] = 1;
				walkerindex++;
			}
			else
			{
				walkerindex++;
			}	
		}
		walkerindex = 0;
		tempvertex = bfsqueue.front();
		cout << tempvertex << " ";
		bfsqueue.pop();

	}
	for (auto &j : m_vertex)
	{
		j = 0;
	}

	return true;
}



//�ڽӾ����е� 0��ʾ��������֮��û�бߣ���0���ʾ���ڶ�Ӧ�ı�
template <typename T>
bool CGraphic<T>::DFSTraver(const size_t &vertex/* =0 */)
{
	if (vertex>m_nvertex)
	{
		return false;
	}

	size_t tempvertex = vertex;
	stack<T> vertexstack;
	vertexstack.push(tempvertex);

	m_vertex[tempvertex] = 1;
	m_traver.push_back(vertex);

	size_t walkindex = 0;
	while (!vertexstack.empty())
	{
		 while( walkindex < m_nvertex)
		{
			if (m_Matrix[tempvertex][walkindex]!=0 && m_vertex[walkindex]==0)
			{
				m_traver.push_back(walkindex);
				m_vertex[walkindex] = 1;
				tempvertex = walkindex;
				walkindex = 0;
				vertexstack.push(walkindex);
			}
			else
			{
				walkindex++;
			}
		}
		 walkindex = 0;
		 tempvertex = vertexstack.top();
		 vertexstack.pop();
	}

	//��m_vertex����ָ�ԭ����״̬
	//�ɲ�����ֱ���ó�ʼ���ķ�ʽ��ִ�����ԭ�ȵ�״̬��
	// 
	for (auto & i:m_vertex )
	{
		i= 0;
	}
	return true;
}



template <typename  T>
int CGraphic<T>::Indegree(const size_t &vertex)
{
	if (vertex > m_nvertex){ return -1; }
	size_t nIndegree = 0;

	for (size_t i=0; i < m_nvertex; i++)
	{
		if (m_Matrix[i][vertex]!=0)
		{
			nIndegree++;
		}
	}

	return nIndegree;
}


template <typename  T>
int CGraphic<T>::Outdegree(const size_t &vertex)
{
	if (vertex > m_nvertex){ return -1; }
	size_t nOutdegree = 0;

	for (size_t i = 0; i < m_nvertex; i++)
	{
		if (m_Matrix[vertex][i] != 0)
		{
			nOutdegree++;
		}
	}
	return nOutdegree;
}



template <typename T>
void CGraphic<T>::OutPutDFST()
{
	for (auto & i : m_traver)
	{
		cout << m_traver[i] << " ";
	}
	cout << endl;
}


//IsDirected:��ʾ���Ƿ�������ͼ
//false:����ͼ  true:����ͼ
template<typename T>
CGraphic<T>::CGraphic(size_t nvertex, bool IsDirected)
{
	m_nvertex= nvertex;
	
	//Ϊɶm_vertex(1,0);������ʽ����
	//����forѭ�����ŵ��۰�
	for (size_t i = 0; i < m_nvertex; i++)
	{
		m_vertex.push_back(0);
	}
	
	for (size_t j = 0; j < m_nvertex; j++)
	{
		m_Matrix.push_back(m_vertex);
	}

	for (size_t m = 0; m < m_nvertex;m++)
	{
		for (size_t n = 0; n < m_nvertex; n++)
		{
			cout << "please input edege:\n";
			cout << "Edge " << m << "---" << n << "lenth is:";
			cin >> m_Matrix[m][n];
		}
	}
}





template <typename T>
bool CGraphic<T>::ModifyEdge(size_t edgeend, size_t edgestart, const T &value)
{
	if ((edgestart>m_nvertex) || (edgestart > m_vertex))
	{
		return false;
	}
	m_Matrix[edgeend][edgestart] = value;
	return true;
}




template<typename T>
void CGraphic<T>::print()
{

	for (size_t i = 0; i < m_nvertex; i++)
	{
		for (size_t j = 0; j < m_nvertex;j++)
		{
			cout << m_Matrix[i][j] << " ";
		}
		cout << endl;
	}
}