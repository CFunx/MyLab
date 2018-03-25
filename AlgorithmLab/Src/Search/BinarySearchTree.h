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

	//将数据插入到二叉搜索树中
	bool Insert(T NodeData);

	//中序遍历输出搜索二叉树
	void InOrder();

	//销毁二叉查找树
	//采用后续遍历的方法将节点删除
	void DestoryBST();

	//采用中序遍历销毁各个节点
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


//用后续遍历来销毁整个树
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
	
	//新建节点
	tagBSTNode<T>*  newnode = new tagBSTNode<T>;
	
	//有可能内存分配失败
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

	//当根节点是空的时候
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







