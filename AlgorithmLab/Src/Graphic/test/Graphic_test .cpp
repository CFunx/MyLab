#include "../../stdafx.h"
#include "../Graphic.h"
#include "Graphic_test.h"

void Graphictest()
{
	CGraphic<int> graphic(4);

	//graphic.print();
	//graphic.DFSTraver(3);
	//graphic.OutPutDFST();
	graphic.BFSTraver();
}