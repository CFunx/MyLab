#pragma  once

template <typename  T>
struct tagBSTNode
{
	tagBSTNode<T>* parent=nullptr;
	tagBSTNode<T>* left=nullptr;
	tagBSTNode<T>* right=nullptr;
	T           data;
};



template <typename T>
class BST
{

public:

	BST();

	//�����ݲ��뵽������������
	bool Insert(T NodeData);

	//��������������������
	void InOrder();

	//���ٶ��������
	//���ú��������ķ������ڵ�ɾ��
	void DestoryBST();

	//��������������ٸ����ڵ�
	~BST();

private:

	tagBSTNode<T>  *m_root;
};



template<typename  T>
BST<T>::BST()
{
	m_root = nullptr;
}



//
template <typename T>
BST<T>::~BST()
{
}


//�ú�������������������
template<typename T>
void BST<T>::DestoryBST()
{
	if (nullptr==m_root)
	{
		return;
	}
}


template <typename  T>
void BST<T>::InOrder()
{
	if (!m_root)return;

	tagBSTNode*  p = m_root;
	tagBSTNode*  pr = nullptr;

	while (nullptr!=p)
	{
		if (nullptr!=p->left)
		{
			p = p->left;
		}
		else
		{
			cout << p->data << "  ";
			if (nullptr != p->right)
			{
				p = p->right;
			}
			else
			{
				pr = p;
				p = p->parent;
            /*******************
				     1
			        / \
			       2   2
			      /     \
			     3       3

			*******************/
				while (nullptr != p && (p->left != pr) || (p->right == nullptr))
				{
					if (p->left == pr)cout << p->data << "";
					pr = p;
					p = p->parent;
				}
			
				/*****************
				
				       1
			          / \
			         2   2   
			   ******************/
				if (nullptr!= p)
				{
					cout << p->data << "";
					p = p->right;
				}
			}
		}
	}
}



template<typename  T>
bool BST<T>::Insert(T NodeData)
{
	tagBSTNode<T>*  tempNode = m_root;
	tagBSTNode <T>* tempparent =nullptr;
	
	//�½��ڵ�
	tagBSTNode<T>*  newnode = new tagBSTNode<T>;
	
	//�п����ڴ����ʧ��
	assert(newnode != NULL);

	newnode->data = NodeData;

	while (nullptr!=tempNode)
	{
		tempparent = tempNode;

		if (tempNode->data >= NodeData)
		{
			tempNode = tempNode->left;
		}
		else
		{
			tempNode = tempNode->right;
		}
	}
	
	newnode->parent = tempparent;

	//�����ڵ��ǿյ�ʱ��
	if (nullptr==tempparent)
	{
		m_root = newnode;
	}
	else
	{
		if (tempparent->data>=NodeData)
		{
			tempparent->left = newnode;
		}
		else
		{
			tempparent->right = newnode;
		}
	}
}







