#include "../../stdafx.h"
#include "../BinaryTree.h"
#include "BinaryTree_test.h"

void  BinaryTreetest()
{
	BinaryTree<int> bttree(-1);
	//cout <<"the high of the tree is :"<<bttree.GetLeafes() << endl;

	//bttree.GetMirror();
	//bttree.PostOrderD();
	//cout << "=====前序遍历======" << endl;
	//bttree.PreOrder_iter();
	//cout << "=====中序遍历======" << endl;
	//bttree.Inorder_iter();

	//cout << "=====后序遍历======" << endl;
	//bttree.PostOrder_iter();
	//cout << "=====层序遍历======" << endl;
	//bttree.LeOrderD();

	cout << "=====二叉树某层叶节点数======" << endl;
	cout << "nodes :" << (bttree.nodesOnLeveln(10)) << endl;
	cout << "nodes :" << bttree.nodesOnLeveln(2) << endl;
}