#pragma  once

class CLinkList
{
public:
	CLinkList();
	void Push(int  value);
	int  GetLen();

	bool IsEmpty();
	
	void ReleaseList();
	void Print();

	//按值擦除
	void Erease(int value);

	//翻转单链表
	void Reverse();

	//链表去重
	void Unique();
	
	~CLinkList();
private:
	typedef struct TagLinkListNode
	{
		int             m_data;
		TagLinkListNode*  m_next;
		TagLinkListNode() :m_next(nullptr){}

	}TAGLinkListNode;

private:

	TagLinkListNode  *m_Head;
	TagLinkListNode  *m_Current;

	//判断链表是否为空
	bool             m_IsInsert;
};