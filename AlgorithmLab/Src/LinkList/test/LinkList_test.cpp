#include "../../stdafx.h"
#include "../LinkList.h"
#include "LinkList_test.h"

void  LinkListTest()
{
	CLinkList mylist;
	mylist.Push(1);
	mylist.Push(1);
	mylist.Push(3);
	mylist.Push(4);
	mylist.Push(5);
	mylist.Push(6);
	mylist.Reverse();

	mylist.Erease(1);
	if (!mylist.IsEmpty())
	{
		printf("list is empty!\n");
	}
	else
	{
		mylist.Print();
	}
	printf("%d\n", mylist.GetLen());
}