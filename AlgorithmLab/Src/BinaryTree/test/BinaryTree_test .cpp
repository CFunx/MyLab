#include "../../stdafx.h"
#include "../BinaryTree.h"
#include "BinaryTree_test.h"

void  BinaryTreetest()
{
	BinaryTree<int> bttree(-1);
	//cout <<"the high of the tree is :"<<bttree.GetLeafes() << endl;

	//bttree.GetMirror();
	//bttree.PostOrderD();
	//cout << "=====ǰ�����======" << endl;
	//bttree.PreOrder_iter();
	//cout << "=====�������======" << endl;
	//bttree.Inorder_iter();

	//cout << "=====�������======" << endl;
	//bttree.PostOrder_iter();
	//cout << "=====�������======" << endl;
	//bttree.LeOrderD();

	cout << "=====������ĳ��Ҷ�ڵ���======" << endl;
	cout << "nodes :" << (bttree.nodesOnLeveln(10)) << endl;
	cout << "nodes :" << bttree.nodesOnLeveln(2) << endl;
}