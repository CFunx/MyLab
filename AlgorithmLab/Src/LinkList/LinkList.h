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

	//��ֵ����
	void Erease(int value);

	//��ת������
	void Reverse();

	//����ȥ��
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

	//�ж������Ƿ�Ϊ��
	bool             m_IsInsert;
};