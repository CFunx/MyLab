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
* 1.�ڶ������Ĺ���������˳�㽫�������ĸ߶ȼ������
* 2.���ӹ��ڴ��󷵻����͵�eum������ʾ��ͬ����Ĵ��󷵻�����
* 3.�ݹ�������ܺ���������������еĵݹ�ĳɷǵݹ�
* 4.��������ӵĵط��������������
*
********************************************************/
template <typename  T>
class BinaryTree
{

public:
	
	BinaryTree() = default;
	BinaryTree(T flag);
	
	//ǰ�����
	void PreOrderD();
	void PreOrder_iter();
	void PreOrder_iter(BTNode<T>* nodeRoot);

    //�������
    void InorderD();
    void Inorder_iter();
    void Inorder_iter(BTNode<T>* nodeRoot);

    //�������
    void PostOrderD();
    void PostOrder_iter();
    void PostOrder_iter(BTNode<T>* nodeRoot);

    //�������
    void LeOrderD();
	void LeOrder(BTNode<T>* bt);
    
    //��������ĸ߶�
    const size_t GetHeight();

    //���ĳ�������ܸ���
    size_t GetOneNodeCount(T value);
										 
    //��������Ҷ�ڵ�ĸ���
    size_t GetLeafes();

    //�������������Ϊ�����˫������
    BTNode<T>*  ToDoubleLinkList(BTNode<T>* nodeRoot, bool isRight=true);

    //�����������+˫������Ĳ��� ����˫������
    BTNode<T>*  MakeDoubleLinkList(BTNode<T>* &nodeHead);

    //��������K��Ľڵ����
	size_t nodesOnLeveln(size_t  nlevel);
	size_t nodesOnLeveln(BTNode<T> *nodeRoot,size_t  nlevel);

    //�ж����ö������Ƿ�ṹ��ͬ
	bool isTheSameFrame(BTNode<T> *nodeRoot1);
	bool isTheSameFrame(BTNode<T> *nodeRoot, BTNode<T> *nodeRoot1);
  
	//�ж��ǲ��Ƕ���������
	bool isBST();
	bool isBST(BTNode<T> *nodeRoot);

    //�ж϶������ǲ���ƽ�������
	bool  isAVL();
	bool  isAVL(BTNode<T> *nodeRoot);
  
	//�������ľ���
	void  GetMirror();
	void Mirror(BTNode<T>* bt);
   
  
    //�������������ڵ����͹������Ƚڵ�
  
    //�������нڵ��������
  
    //��ǰ��������к�������������ؽ�������
  
    //�ж϶������ǲ�����ȫ������

    //�������е�ĳ���ڵ������·��

    //ɾ���������е���ĳ��ֵ�Ľڵ�

    //����ĳ���ڵ�

   ~BinaryTree();
private:
	
	BTNode<T>*  ConstructTree(BTNode<T>* bt);
	void DestoryTree(BTNode<T>* bt);
	
	//�ǵݹ����ٺ���
	void DestoryTree_iter(BTNode<T>* nodeRoot);

	void PreOrder(BTNode<T>* bt);
	void Inorder(BTNode<T>* bt);
	void PostOrder(BTNode<T>* bt);

	size_t Height(BTNode<T>* bt);

	//���ĳ�����ֵ���ܸ���
	size_t GetOneNodeCount(BTNode<T>* bt,T value);

	//��ȡ���н��ĸ���
	size_t GetTotalNode()const;

	size_t GetLeafCount(BTNode<T>* bt);

	//��ö�������ĳ���ϵĽڵ���
	size_t GetLevelNode(BTNode<T> *nodeRoot, size_t  nlevel);

	//���ݸ߶�֮���ж��ǲ���ƽ�������
	bool isAVL(BTNode<T> *nodeRoot, size_t &heigh);


private:

	BTNode<T>*  m_root;
	T           m_endflag;

	//�����������
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
	
	//��������ָ���
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

		//TODO:�˴��᲻����ɽ�����ʧ�ܵ�����أ�
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


/*************����Ҷ�ڵ���жϷ�ʽ*****************/
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
			//��Ϊ��ջ���Ա���������������ջ
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



//ǰ������ı���
template<typename T>
size_t BinaryTree<T>::GetLeafCount(BTNode<T>* bt)
{
	if (bt == nullptr)return 0;

	//�ȼ������������ж������ҽ���Ƿ�Ϊ��
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

//�ж��������Ƿ���ͬ
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
		//��Ϊ�յ����
		return true;
	}
	else if (nodeRoot == nullptr || nodeRoot1 == nullptr)
	{
		//����һ��Ϊ�յ����
		return false;
	}
	else //(nodeRoot!=nullptr && nodeRoot1!=nullptr) 
	{
		//����Ϊ�յ����
		cout << "nodeRoot :" << nodeRoot->data << "  "
			<< "nodeRoot1 :" << nodeRoot1->data << endl;
		return true;
	}

	bool isLeft = isTheSameFrame(nodeRoot->left, nodeRoot1->left);
	bool isRigth = isTheSameFrame(nodeRoot->right, nodeRoot1->right);

	return (isLeft&&isRigth);
}




//AVL��������
//1.�Ƕ���������
//2.���������������ĸ߶Ȳ�ľ���ֵ���ܴ���1

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
		 //��Ҷ��㿪ʼ���������������������ĸ߶�
		 //Ȼ�����߶Ȳ�
		 //TODO:��ʵֻҪ�ҵ����е�ĳ����������AVL��ô��ֱ�ӷ���false
		 //������û�б�Ҫ��������������,���ǵݹ�ֻ�ܱ������������
		 //���Ի����÷ǵݹ����
		 heigh = max(lheigh, rheigh) + 1;
		 return true;
	 }
	 else
	 {
		 heigh = max(lheigh, rheigh) + 1;
		 return false;
	 }
}


//�ж��ǲ��Ƕ���������������������ķ������Ƚ��ǲ���һ�����������
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
	
	//������ű�������ǰһ�����
	T nodetmp;

	//�Ƿ��Ƿ��ʵ��ĵ�һ�����
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


			//���ڱȽ���ʱֻ֧���������͵ıȽ�
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
	cout << "====������������=====" << endl;
	//DestoryTree(m_root);
	DestoryTree_iter(m_root);
}

