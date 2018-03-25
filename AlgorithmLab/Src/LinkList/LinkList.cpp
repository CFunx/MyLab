#include "../stdafx.h"
#include "LinkList.h"


CLinkList::CLinkList()
{
	m_Head = new TagLinkListNode;
	m_IsInsert = false;
}

void CLinkList::Print()
{
	if (false == m_IsInsert){ return;}
	TagLinkListNode *tempListNode = m_Head;
	
	while (nullptr!=tempListNode)
	{
		printf("%d  ", tempListNode->m_data);
		tempListNode = tempListNode->m_next;
	}
	printf("\n");
}


bool CLinkList::IsEmpty()
{
	return m_IsInsert;
}

//尾插法
void CLinkList::Push(int value)
{
	if (false == m_IsInsert)
	{
		m_IsInsert = true;
		m_Head ->m_data= value;
		m_Current = m_Head;
	}
	else
	{
		TagLinkListNode* InsertNode = new TagLinkListNode;
		InsertNode->m_data = value;
		m_Current->m_next = InsertNode;
		m_Current = InsertNode;	
	}
}

int  CLinkList::GetLen()
{
	int   templen=0;

	//队列是空的时候
	if (!m_IsInsert) { return 0; }

	TagLinkListNode *tempHead=m_Head;
	while (tempHead!=nullptr)
	{
		templen++;
		tempHead = tempHead->m_next;
	}
	return  templen;
}


//释放动态申请的节点在退出的时候
void CLinkList::ReleaseList()
{
	TagLinkListNode *rHead = m_Head;
	while (rHead!=nullptr)
	{
		m_Head = m_Head->m_next;
		delete rHead;
		rHead = nullptr;
		rHead = m_Head;
	}
}



//删除节点以后有可能整个链表就变成空的
//怎么处理
void CLinkList::Erease(int value)
{
	if (!m_IsInsert) { return; }

	TagLinkListNode  *TagHead = m_Head;
	TagLinkListNode  *TagNext = TagHead->m_next;

	while (nullptr!=TagNext)
	{
		if (TagNext->m_data==value)
		{
			TagLinkListNode *TagtemListNode = nullptr;
			TagtemListNode = TagNext->m_next;
			delete TagNext;
			TagNext = nullptr;
			TagNext = TagtemListNode;
			TagHead->m_next = TagNext;
		}
		else
		{ 
			TagHead = TagNext;
			TagNext = TagNext->m_next;
		}
	}

	//当删除节点是头结点的时候
	if (value == m_Head->m_data)
	{
		TagLinkListNode *tempTagHead = m_Head->m_next;
		delete m_Head;
		m_Head = nullptr;

		//链表为空的情况
		if (nullptr==tempTagHead)
		{
			m_IsInsert = false;
		}
		m_Head = tempTagHead;
	}
}


//翻转链表
//还有一种方法貌似是设置三个指针进行倒腾的结果
void CLinkList::Reverse()
{
	if (!m_IsInsert){ return; }
	if (nullptr == m_Head->m_next){ return; }

	TagLinkListNode *TempListNode = m_Head->m_next;
	
	//尾指针
	TagLinkListNode *TempTailNode = m_Head->m_next;
	TagLinkListNode *tempFirstNode = nullptr;
	TagLinkListNode *tempSecondNode = nullptr;
	m_Head->m_next = nullptr;

	while (nullptr!=TempListNode)
	{
		//将数据从链表上摘下来
		tempFirstNode = TempListNode;
		TempListNode = TempListNode->m_next;
		tempFirstNode->m_next = nullptr;


		//利用头插法将数据插入到链表中
		tempSecondNode = m_Head->m_next;
		m_Head->m_next = tempFirstNode;
        tempFirstNode->m_next = tempSecondNode;
	}

	TagLinkListNode *tempHeadNode=m_Head ;
	m_Head = m_Head->m_next;

	tempHeadNode->m_next = nullptr;
	TempTailNode->m_next =tempHeadNode ;
}


//TODO:链表去重
void CLinkList::Unique()
{






}


CLinkList::~CLinkList()
{
	ReleaseList();
	m_IsInsert = false;
	delete m_Head;
	m_Head = nullptr;

} 
