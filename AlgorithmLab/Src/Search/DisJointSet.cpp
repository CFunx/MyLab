#include "../stdafx.h"
#include <cstdarg>
#include "DisJointSet.h"

DisjointSets::DisjointSets():m_numElements(0),m_numSets(0){}

DisjointSets::DisjointSets(size_t count) : m_numElements(0),m_numSets(0)
{
	addElements(count);
}

DisjointSets::DisjointSets(const DisjointSets& s)
{
	this->m_numElements = s.m_numElements;
	this->m_numSets = s.m_numSets;

	m_nodes.resize(m_numElements);
	for (size_t i = 0; i < m_numElements; ++i)
	{
		m_nodes[i] = new Node(*s.m_nodes[i]);
	}

	for (size_t j = 0; j < m_numElements; ++j)
	{
		if (m_nodes[j]->parent != nullptr)
		{
			m_nodes[j]->parent = m_nodes[s.m_nodes[j]->parent->index];
		}
	}
}

DisjointSets::~DisjointSets()
{
	deleteAllElements();
}


//查找的同时，顺便用路径压缩降低树的高度
//返回要查找点的树的根节点
size_t DisjointSets::findSet(size_t elementId) const
{
	assert(elementId < m_numElements);

	Node *curNode= m_nodes[elementId];
	while (curNode->parent != nullptr)
	{
		curNode = curNode->parent;
	}

	Node* root = curNode;

	//将所有结点指的父节点都指向刚刚查找到的根节点
	curNode = m_nodes[elementId];
	while(curNode != root)
	{
		Node* next = curNode->parent;
		curNode->parent = root;
		curNode = next;
	}

	return root->index;
}

//将树合并成一棵树
/*
setId1=	FindSet(elementId1);
setId2=	FindSet(elementId2);
*/
void DisjointSets::mergeSet(size_t setId1, size_t setId2)
{
	assert(setId1 < m_numElements);
	assert(setId2 < m_numElements);

	//在一个集合中
	if(setId1 == setId2)return; 

	Node *set1 = m_nodes[setId1];
	Node *set2 = m_nodes[setId2];

	
	if (set1->rank > set2->rank)
	{
		set2->parent = set1;
	}	
	else if (set1->rank < set2->rank)
	{
		set1->parent = set2;
	}
	else 
	{
		set2->parent = set1;
		++(set1->rank); // update rank
	}

	--m_numSets;
}

void DisjointSets::addElements(size_t numToAdd)
{
	m_nodes.insert(m_nodes.end(), numToAdd, (Node*)nullptr);
	size_t totalElements = m_numElements + numToAdd;

	for(size_t i = m_numElements; i <totalElements; ++i)
	{
		m_nodes[i] = new Node();
		assert(m_nodes[i]!= nullptr);
		m_nodes[i]->index = i;	
	}

	m_numElements += numToAdd;
	m_numSets     += numToAdd;
}


void DisjointSets::deleteAllElements()
{
	cout << "delete element" << endl;

	for (size_t i = 0; i < m_numElements; ++i)
	{
		delete m_nodes[i];
		m_nodes[i] = nullptr;
	}
	m_nodes.clear();
	m_numElements = 0;
	m_numSets = 0;
}

size_t DisjointSets::numElements() const
{
	return m_numElements;
}

size_t DisjointSets::numSets() const
{
	return m_numSets;
}

void DisjointSets::printElementSets()
{
	for (size_t i = 0; i < m_numElements; ++i)
	{
		cout << findSet(i) << "  ";
	}
	cout << endl;
}


bool DisjointSets::isInSameSet(size_t param1, size_t param2)
{
	 if (param1==param2)
	 {
		 return true;
	 }
	 else
	 {
		 return (findSet(param1) == findSet(param2));
	 }
}

//size_t countparam：输入参数的个数
bool DisjointSets::isInSameSet(size_t countparam, ...)
{
	assert(countparam >2);

	vector<size_t> resultFindset;
	va_list ap;
	va_start(ap, countparam);
	for (size_t i = 0; i < countparam; i++)
	{
		resultFindset.push_back(findSet(va_arg(ap, size_t)));
	}

	va_end(ap);
	for (size_t m = 0,n=m+1; m < countparam-1; m++,n++)
	{
		if (resultFindset[m] ^ (resultFindset[n]) )
		{
			return false;
		}
	}
	return true;
}