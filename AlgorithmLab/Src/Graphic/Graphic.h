#pragma  once

template <typename T>
class CGraphic
{
public:
	
	//邻接矩阵方法构造图
	CGraphic(size_t nvertex, bool IsDirected = false);

	//某个顶点的入读
	int Indegree(const size_t &vertex);

	//某个顶点的出度
    int Outdegree(const size_t &vertex);

	//深度优先遍历
	//vertex:开始遍历节点
	bool DFSTraver(const size_t &vertex=0);

	void OutPutDFST();

	//广度优先遍历
	bool BFSTraver(const size_t &vertex=0);

	//打印图初始的邻接矩阵
	void print();

	//更改边与边的连接情况
	bool  ModifyEdge(size_t edgeend, size_t edgestart,const T &value);

private:

	//顶点个数
    size_t m_nvertex;

	//存放遍历后顶点的容器
	vector<T> m_traver;
	
	//存放顶点容器
	vector <T>  m_vertex;

	//存放边的容器
	vector<vector <T> > m_Matrix; 
};


//广度优先遍历
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



//邻接矩阵中的 0表示两个顶点之间没有边，非0则表示存在对应的边
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

	//将m_vertex数组恢复原来的状态
	//可不可以直接用初始化的方式来执行清除原先的状态？
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


//IsDirected:表示的是否是有向图
//false:无向图  true:有向图
template<typename T>
CGraphic<T>::CGraphic(size_t nvertex, bool IsDirected)
{
	m_nvertex= nvertex;
	
	//为啥m_vertex(1,0);这种形式不行
	//三个for循环看着蛋疼啊
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