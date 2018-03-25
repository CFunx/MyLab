#pragma  once

template <typename  T>
struct BTNode
{
	T           data;
	BTNode<T>*  left=nullptr;
	BTNode<T>*  right=nullptr;
};

/********************************************************
*	             TODO
*
* 1.在二叉树的构建过程中顺便将二叉树的高度计算出来
* 2.增加关于错误返回类型的eum用来表示不同情况的错误返回类型
* 3.递归存在性能和溢出的隐患将所有的递归改成非递归
* 4.两个数相加的地方存在溢出的隐患
*
********************************************************/
template <typename  T>
class BinaryTree
{

public:
	
	BinaryTree() = default;
	BinaryTree(T flag);
	
	//前序遍历
	void PreOrderD();
	void PreOrder_iter();
	void PreOrder_iter(BTNode<T>* nodeRoot);

    //中序遍历
    void InorderD();
    void Inorder_iter();
    void Inorder_iter(BTNode<T>* nodeRoot);

    //后序遍历
    void PostOrderD();
    void PostOrder_iter();
    void PostOrder_iter(BTNode<T>* nodeRoot);

    //层序遍历
    void LeOrderD();
	void LeOrder(BTNode<T>* bt);
    
    //求二叉树的高度
    const size_t GetHeight();

    //获得某个结点的总个数
    size_t GetOneNodeCount(T value);
										 
    //二叉树的叶节点的个数
    size_t GetLeafes();

    //将二叉查找树变为有序的双向链表
    BTNode<T>*  ToDoubleLinkList(BTNode<T>* nodeRoot, bool isRight=true);

    //利用中序遍历+双向链表的插入 构造双向链表
    BTNode<T>*  MakeDoubleLinkList(BTNode<T>* &nodeHead);

    //二叉树第K层的节点个数
	size_t nodesOnLeveln(size_t  nlevel);
	size_t nodesOnLeveln(BTNode<T> *nodeRoot,size_t  nlevel);

    //判断两棵二叉树是否结构相同
	bool isTheSameFrame(BTNode<T> *nodeRoot1);
	bool isTheSameFrame(BTNode<T> *nodeRoot, BTNode<T> *nodeRoot1);
  
	//判断是不是二叉搜索树
	bool isBST();
	bool isBST(BTNode<T> *nodeRoot);

    //判断二叉树是不是平衡二叉树
	bool  isAVL();
	bool  isAVL(BTNode<T> *nodeRoot);
  
	//二叉树的镜像
	void  GetMirror();
	void Mirror(BTNode<T>* bt);
   
  
    //二叉树中两个节点的最低公共祖先节点
  
    //二叉树中节点的最大距离
  
    //由前序遍历序列和中序遍历序列重建二叉树
  
    //判断二叉树是不是完全二叉树

    //二叉树中到某个节点的所有路径

    //删除二叉树中等于某个值的节点

    //插入某个节点

   ~BinaryTree();
private:
	
	BTNode<T>*  ConstructTree(BTNode<T>* bt);
	void DestoryTree(BTNode<T>* bt);
	
	//非递归销毁函数
	void DestoryTree_iter(BTNode<T>* nodeRoot);

	void PreOrder(BTNode<T>* bt);
	void Inorder(BTNode<T>* bt);
	void PostOrder(BTNode<T>* bt);

	size_t Height(BTNode<T>* bt);

	//获得某个结点值的总个数
	size_t GetOneNodeCount(BTNode<T>* bt,T value);

	//获取所有结点的个数
	size_t GetTotalNode()const;

	size_t GetLeafCount(BTNode<T>* bt);

	//获得二叉树的某层上的节点数
	size_t GetLevelNode(BTNode<T> *nodeRoot, size_t  nlevel);

	//根据高度之差判断是不是平衡二叉树
	bool isAVL(BTNode<T> *nodeRoot, size_t &heigh);


private:

	BTNode<T>*  m_root;
	T           m_endflag;

	//二叉树结点数
	size_t      m_node;
	size_t      m_high;
};




template <typename T>
BinaryTree<T>::BinaryTree(T flag)
{
	m_root = nullptr;
	m_endflag = flag;
	m_root=ConstructTree(m_root);	
}



template  <typename T>
BTNode<T>* BinaryTree<T>::ConstructTree(BTNode<T>* bt)
{
	T tempcin;
	cin >> tempcin;
	
	//处理输入分隔符
	if (tempcin==m_endflag)
	{
		bt = nullptr;
	}
	else
	{
		bt = new BTNode<T>;
		assert(bt != nullptr);
		bt->data = tempcin;

		cout << "Input Is :" << bt->data << endl;

		//TODO:此处会不会造成结点插入失败的情况呢？
		m_node++;
		bt->left=ConstructTree(bt->left);
		bt->right=ConstructTree(bt->right);
	}									 
	return bt;
}


template <typename T>
void BinaryTree<T>::PreOrderD()
{
	PreOrder(m_root);
}



template <typename T>
void BinaryTree<T>::PreOrder_iter()
{
	PreOrder_iter(m_root);
}

template <typename T>
void BinaryTree<T>::PreOrder_iter(BTNode<T>* nodeRoot)
{
	if (nodeRoot == nullptr)
	{
		cout << "The tree is empty\n";
		return;
	}
	stack<BTNode <T>* >  btStack;
	BTNode<T>* btNode = nodeRoot;

	while (btNode != nullptr || !(btStack.empty()))
	{
		while (btNode)
		{
			cout << btNode->data << " ";
			btStack.push(btNode);
			btNode = btNode->left;
		}
		if (!(btStack.empty()))
		{
			btNode = btStack.top();
			btStack.pop();
			btNode = btNode->right;
		}
	}
	cout << endl;
}


template <typename T>
void BinaryTree<T>::InorderD()
{
	Inorder(m_root);
}


template <typename T>
void BinaryTree<T>::Inorder_iter()
{
	Inorder_iter(m_root);
	
}

template <typename T>
void BinaryTree<T>::Inorder_iter(BTNode<T>* nodeRoot)
{
	if (nodeRoot == nullptr)
	{
		cout << "The tree is empty\n";
		return;
	}
	stack<BTNode <T>* >  btStack;
	BTNode<T>*  btNode = nodeRoot;

	while (btNode != nullptr || !(btStack.empty()))
	{
		while (btNode)
		{
			btStack.push(btNode);
			btNode = btNode->left;
		}

		if (!(btStack.empty()))
		{
			btNode = btStack.top();
			btStack.pop();
			cout << btNode->data << " ";
			btNode = btNode->right;
		}
	}
	cout << endl;
}




template <typename T>
void BinaryTree<T>::PostOrderD()
{
	PostOrder(m_root);
}


/*************基于叶节点的判断方式*****************/
template <typename T>
void BinaryTree<T>::PostOrder_iter()
{
	PostOrder_iter(m_root);
}

template <typename T>
void BinaryTree<T>::PostOrder_iter(BTNode<T>* nodeRoot)
{
	if (nodeRoot == nullptr)
	{
		cout << "The tree is empty\n";
		return;
	}

	stack<BTNode<T>* >  btStack;
	BTNode<T> *btCurrent = nodeRoot;

	BTNode<T> *preNode = nullptr;
	btStack.push(nodeRoot);

	while (!btStack.empty())
	{
		btCurrent = btStack.top();
		if (((btCurrent->left == nullptr) && (btCurrent->right == nullptr)) ||
			(preNode != nullptr && (btCurrent->left == preNode || btCurrent->right == preNode)))
		{
			cout << btCurrent->data << " ";
			btStack.pop();
			preNode = btCurrent;
		}
		else
		{
			//因为是栈所以必须是右子树先入栈
			if (btCurrent->right) btStack.push(btCurrent->right);
			if (btCurrent->left) btStack.push(btCurrent->left);
			
		}
	}
	cout << endl;
}



template <typename T>
void BinaryTree<T>::LeOrderD()
{
	LeOrder(m_root);
}



template  <typename T>
void BinaryTree<T>::LeOrder(BTNode<T>* bt)
{
	if (!bt)
	{
		cout << "The tree is empty" << endl;
		return;
	}

	queue<BTNode<T>* >  QBt;
	QBt.push(bt);

	BTNode<T>* Tempode = nullptr;

	while (!QBt.empty())
	{
		Tempode = QBt.front();
		cout << Tempode->data << " ";
		QBt.pop();

		if (Tempode->left != nullptr)
		{
			QBt.push(Tempode->left);
		}

		if (Tempode->right != nullptr)
		{
			QBt.push(Tempode->right);
		}
	}
	cout << endl;
}



template <typename T>
void BinaryTree<T>::PreOrder(BTNode<T>* bt)
{
	if (bt==nullptr)return;
	cout << bt->data << " " << endl;
	PreOrder(bt->left);
	PreOrder(bt->right);
}



template <typename T>
void BinaryTree<T>::Inorder(BTNode<T>* bt)
{
	if (bt == nullptr)return;
	Inorder(bt->left);
	cout << bt->data << " " << endl;
	Inorder(bt->right);
}



template <typename T>
void BinaryTree<T>::PostOrder(BTNode<T>* bt)
{
	if (bt == nullptr)return;
	PostOrder(bt->left);
	PostOrder(bt->right);
	cout << bt->data << " " << endl;
}


template<typename T>
const size_t BinaryTree<T>::GetHeight()
{
	m_high =Height(m_root)
	return m_high;
}



template<typename T>
size_t BinaryTree<T>::Height(BTNode<T>* bt)
{
	if (!bt) return 0;
	size_t ldeep = Height(bt->left);
	size_t rdeep = Height(bt->right);
	return ldeep >= rdeep ? ldeep + 1 : rdeep +1 ; 
}


template<typename  T>
size_t BinaryTree<T>::GetOneNodeCount(T value)
{
	return GetOneNodeCount(m_root, value);
}


template <typename T>
size_t BinaryTree<T>::GetOneNodeCount(BTNode<T>* bt, T value)
{
	if (bt == nullptr) return 0;
	size_t lcount = GetOneNodeCount(bt->left, value);
	size_t rcount= GetOneNodeCount(bt->right, value);

	return lcount + rcount + (bt->data == value ? 1 : 0);
}



template<typename T>
size_t BinaryTree<T>::GetTotalNode() const
{
	return m_node;
}

template <typename T>
void BinaryTree<T>::DestoryTree(BTNode<T>* bt)
{
	if (bt!=nullptr)
	{
		DestoryTree(bt->left);
		DestoryTree(bt->right);
		cout << "delete node is :" << bt->data << endl;
		delete bt;
		bt = nullptr;
	}
}


template <typename T>
void BinaryTree<T>::DestoryTree_iter(BTNode<T>* nodeRoot)
{
	if (nodeRoot == nullptr)
	{
		cout << "The tree is empty\n";
		return;
	}

	stack<BTNode<T>* >  btStack;
	BTNode<T> *btCurrent=nullptr;

	BTNode<T> *preNode = nullptr;
	btStack.push(nodeRoot);

	while (!btStack.empty())
	{
		btCurrent = btStack.top();
		if (((btCurrent->left == nullptr) && (btCurrent->right == nullptr)) ||
			(preNode != nullptr && (btCurrent->left == preNode || btCurrent->right == preNode)))
		{
			btStack.pop();
			preNode = btCurrent;
			cout << "delete node is :" << btCurrent->data << endl;
			delete btCurrent;
			btCurrent = nullptr;
		}
		else
		{
			if (btCurrent->right) btStack.push(btCurrent->right);
			if (btCurrent->left) btStack.push(btCurrent->left);
		}
	}
	cout << endl;
}


template<typename T>
size_t BinaryTree<T>::GetLeafes()
{
	return GetLeafCount(m_root);
}



//前序遍历的变种
template<typename T>
size_t BinaryTree<T>::GetLeafCount(BTNode<T>* bt)
{
	if (bt == nullptr)return 0;

	//先计算这样才能判断其左右结点是否为空
	if (bt->left == nullptr &&
		bt->right == nullptr)
		return 1;

	size_t Lleaf = GetLeafCount(bt->left);
	size_t Rleaf = GetLeafCount(bt->right);
	return (Lleaf + Rleaf);
}



template<typename T>
void BinaryTree<T>::Mirror(BTNode<T>* bt)
{
	if (bt == nullptr) return;
	BTNode<T>* tempbt=nullptr;

	tempbt = bt->left;
	bt->left = bt->right;
	bt->right = tempbt;
	Mirror(bt->left);
	Mirror(bt->right);
}


template <typename T>
void BinaryTree<T>::GetMirror()
{
	Mirror(m_root);
}



//TODO:test
template <typename T>
BTNode<T>*  BinaryTree<T>::ToDoubleLinkList(BTNode<T> *nodeRoot, bool isRight)
{
	if (!nodeRoot)return nullptr;

	BTNode<T> *chLeft = nullptr;
	BTNode<T> *chRight = nullptr;

	if (nodeRoot->left)
	{
		chLeft = ToDoubleLinkList(nodeRoot->left, false);
	}

	if (chLeft)
	{
		chLeft->right = nodeRoot;
		nodeRoot->left = chLeft;
	}

	if (nodeRoot->right)
	{
		chRight = ToDoubleLinkList(nodeRoot->right, true);
	}

	if (chRight)
	{
		chRight->left = nodeRoot;
		nodeRoot->right = chRight;
	}

	BTNode<T> *tempNode = nodeRoot;
	if (isRight)
	{
		while (tempNode->left) 
		{
			tempNode = tempNode->left;
		}
	}
	else
	{
		while (tempNode->right)
		{
			tempNode = tempNode->right;
		}
	}

	return tempNode;
}


//TODO: test
template <typename T>
BTNode<T>* BinaryTree<T>::MakeDoubleLinkList(BTNode<T>* &nodeHead)
{
	if (!m_root) return nullptr;
	stack<BTNode<T>* >  btStack;
	BTNode<T> * tmpCurentNode = nullptr;
	bool isHead = true;
	BTNode<T> * btNode =m_root;
	while ( (btNode!=nullptr) || !(btStack.empty() ))
	{
		while (btNode)
		{
			btStack.push(btNode);
			btNode = btNode->left;
		}

		if (!(btStack.empty() ) )
		{
			btNode = btStack.pop();
			
			if (isHead)
			{
				tmpCurentNode = btNode;
				nodeHead = tmpCurentNode;
				isHead = false;
				btNode = btNode->right;
			}
			else
			{
				tmpCurentNode->right = btNode;
				btNode->left = tmpCurentNode;
				tmpCurentNode = tmpCurentNode->right;
				btNode = btNode->right;
			}
		}
	}
	return nodeHead;
}



template <typename T>
size_t BinaryTree<T>::GetLevelNode(BTNode<T> *nodeRoot, size_t  nlevel)
{
    //Note nlevel < 1
	if (nodeRoot==nullptr || nlevel <1)return 0;
	if (nlevel == 1)
	{
		cout << nodeRoot->data <<" "<< endl;
		return 1;
	}

	size_t numLeft = GetLevelNode(nodeRoot->left, nlevel - 1);
	size_t numRight = GetLevelNode(nodeRoot->right, nlevel - 1);

	return numLeft + numRight;
}


template <typename T>
size_t BinaryTree<T>::nodesOnLeveln(size_t  nlevel)
{
	return nodesOnLeveln(m_root, nlevel);
}


template <typename T>
size_t BinaryTree<T>::nodesOnLeveln(BTNode<T> *nodeRoot, size_t  nlevel)
{
	if (!nodeRoot)
	{
		cout << "The tree is null" << endl;
		return 0;
	}

	if (nlevel == 0)return 0;
	if (nlevel == 1)return 1;

	return  GetLevelNode(nodeRoot, nlevel);
}

//判断两棵树是否相同
//TODO:test
template <typename  T>
bool  BinaryTree<T>::isTheSameFrame(BTNode<T> *nodeRoot1)
{
	return isTheSameFrame(m_root, nodeRoot1);
}


//TODO:test
template <typename  T>
bool  BinaryTree<T>::isTheSameFrame(BTNode<T> *nodeRoot, BTNode<T> *nodeRoot1)
{
	if ((nodeRoot == nullptr && nodeRoot1 == nullptr) )
	{
		//都为空的情况
		return true;
	}
	else if (nodeRoot == nullptr || nodeRoot1 == nullptr)
	{
		//其中一个为空的情况
		return false;
	}
	else //(nodeRoot!=nullptr && nodeRoot1!=nullptr) 
	{
		//都不为空的情况
		cout << "nodeRoot :" << nodeRoot->data << "  "
			<< "nodeRoot1 :" << nodeRoot1->data << endl;
		return true;
	}

	bool isLeft = isTheSameFrame(nodeRoot->left, nodeRoot1->left);
	bool isRigth = isTheSameFrame(nodeRoot->right, nodeRoot1->right);

	return (isLeft&&isRigth);
}




//AVL树的条件
//1.是二叉搜索树
//2.左子树和右子树的高度差的绝对值不能大于1

//TODO:test
template <typename  T>
bool  BinaryTree<T>::isAVL()
{
	return isAVL(m_root);
}



//TODO:test
template <typename  T>
bool BinaryTree<T>::isAVL(BTNode<T> *nodeRoot)
{
	size_t heigh = 0;
	return 	(isBST(nodeRoot) && isAVL(nodeRoot, heigh));
}


//TODO: test
template <typename  T>
bool BinaryTree<T>::isAVL(BTNode<T> *nodeRoot,size_t &heigh)
{
	 if (!nodeRoot)
	 {
		 heigh = 0;
		 return true;
	 }

	 size_t lheigh=0;
	 size_t rheigh = 0;

	 bool isleft = isAVL(nodeRoot->left, lheigh);
	 bool isright = isAVL(nodeRoot->right, rheigh);

	 if (isleft && isright && abs(lheigh-rheigh)<=1)
	 {
		 //从叶结点开始计算其左子树和右子树的高度
		 //然后计算高度差
		 //TODO:其实只要找到其中的某个子树不是AVL那么就直接返回false
		 //这样就没有必要计算玩整个树了,但是递归只能遍历完成整个树
		 //所以还是用非递归代替
		 heigh = max(lheigh, rheigh) + 1;
		 return true;
	 }
	 else
	 {
		 heigh = max(lheigh, rheigh) + 1;
		 return false;
	 }
}


//判断是不是二叉搜索树，用中序遍历的方法来比较是不是一个有序的数列
//TODO:test
template <typename T>
bool BinaryTree<T>::isBST()
{
	return isBST(m_root)
}

//TODO:test
template <typename T>
bool BinaryTree<T>::isBST(BTNode<T> *nodeRoot)
{
	if (nodeRoot == nullptr)
	{
		cout << "The tree is empty\n";
		return false;
	}

	if ((nodeRoot->left==nullptr) &&(nodeRoot->right==nullptr))
	{
		cout << "The tree only one node" << endl;
		return true;
	}

	stack<BTNode <T>* >  btStack;
	BTNode<T>*  btNode = nodeRoot;
	
	//用来存放遍历过的前一个结点
	T nodetmp;

	//是否是访问到的第一个结点
	bool isFirstNode = true;
	while (btNode != nullptr || !(btStack.empty()))
	{
		while (btNode)
		{
			btStack.push(btNode);
			btNode = btNode->left;
		}

		if (!(btStack.empty()))
		{
			btNode = btStack.top();
			btStack.pop();


			//对于比较暂时只支持内置类型的比较
			if (isFirstNode)
			{
				nodetmp = btNode->data;
				isFirstNode = false;
			}
			else
			{
				if (btNode->data <= nodetmp) return false;
				nodetmp = btNode->data;
			}

			cout << btNode->data << " ";
			btNode = btNode->right;
		}
	}
	cout << endl;
	return true;
}





template <typename T>
BinaryTree<T>::~BinaryTree()
{
	cout << "====析构函数调用=====" << endl;
	//DestoryTree(m_root);
	DestoryTree_iter(m_root);
}

