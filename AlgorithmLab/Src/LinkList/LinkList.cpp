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

//β�巨
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

	//�����ǿյ�ʱ��
	if (!m_IsInsert) { return 0; }

	TagLinkListNode *tempHead=m_Head;
	while (tempHead!=nullptr)
	{
		templen++;
		tempHead = tempHead->m_next;
	}
	return  templen;
}


//�ͷŶ�̬����Ľڵ����˳���ʱ��
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



//ɾ���ڵ��Ժ��п�����������ͱ�ɿյ�
//��ô����
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

	//��ɾ���ڵ���ͷ����ʱ��
	if (value == m_Head->m_data)
	{
		TagLinkListNode *tempTagHead = m_Head->m_next;
		delete m_Head;
		m_Head = nullptr;

		//����Ϊ�յ����
		if (nullptr==tempTagHead)
		{
			m_IsInsert = false;
		}
		m_Head = tempTagHead;
	}
}


//��ת����
//����һ�ַ���ò������������ָ����е��ڵĽ��
void CLinkList::Reverse()
{
	if (!m_IsInsert){ return; }
	if (nullptr == m_Head->m_next){ return; }

	TagLinkListNode *TempListNode = m_Head->m_next;
	
	//βָ��
	TagLinkListNode *TempTailNode = m_Head->m_next;
	TagLinkListNode *tempFirstNode = nullptr;
	TagLinkListNode *tempSecondNode = nullptr;
	m_Head->m_next = nullptr;

	while (nullptr!=TempListNode)
	{
		//�����ݴ�������ժ����
		tempFirstNode = TempListNode;
		TempListNode = TempListNode->m_next;
		tempFirstNode->m_next = nullptr;


		//����ͷ�巨�����ݲ��뵽������
		tempSecondNode = m_Head->m_next;
		m_Head->m_next = tempFirstNode;
        tempFirstNode->m_next = tempSecondNode;
	}

	TagLinkListNode *tempHeadNode=m_Head ;
	m_Head = m_Head->m_next;

	tempHeadNode->m_next = nullptr;
	TempTailNode->m_next =tempHeadNode ;
}


//TODO:����ȥ��
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
