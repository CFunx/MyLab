#include "../../stdafx.h"
#include "../BinarySearchTree.h"
#include "../SearchAlgorithm.h"
#include "../DisJointSet.h"



void Searchtest()
{
	int  myarry[] = { 1, 2, 3, 4, 4, 5, 6 };
	CSearch search;
	cout << search.BinarySearch(myarry, 7, 4) << endl;
	cout << search.LowBound(myarry, 7, 4) << endl;
	cout << search.HighBound(myarry, 7, 4) << endl;
}

void DisjointSetstest()
{
	DisjointSets s(10);
	s.printElementSets();
	s.mergeSet(s.findSet(5), s.findSet(3));
	s.printElementSets();
	s.mergeSet(s.findSet(1), s.findSet(3));
	s.printElementSets();
	s.mergeSet(s.findSet(6), s.findSet(7));
	s.printElementSets();
	s.mergeSet(s.findSet(8), s.findSet(9));
	s.printElementSets();
	s.mergeSet(s.findSet(6), s.findSet(9));
	s.printElementSets();
	s.addElements(3);
	s.printElementSets();
	s.mergeSet(s.findSet(11), s.findSet(12));
	s.printElementSets();
	s.mergeSet(s.findSet(9), s.findSet(10));
	s.printElementSets();
	s.mergeSet(s.findSet(7), s.findSet(11));
	s.printElementSets();

	if (!s.isInSameSet(3, 0, 2, 6))
	{
		cout << "No" << endl;
	}

}


void BinarySearchTreetest()
{
	tagBSTNode<int> *b = NULL;
	tagBSTNode<int> a;
	a.data = 5;
	a.left = b;
}