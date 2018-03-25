#include "../../stdafx.h"
#include "Stringtest.h"

void StringTest()
{
	String  str;

	/*char *src = "12456";
	char *dest = "456";
	
	wchar_t *src_w = L"123";
	wchar_t *dest_w =L"2";
	int index=str.findStrT(src, dest);
	cout << "match index is:" << index << endl;
	 */


	char *srckmp = "BBC ABCDAB ABCDABDABDE";
	char *destkmp = "ABCDABD";

	int ret=str.findStrKMPT(srckmp, destkmp);

	cout << ret << endl;

}