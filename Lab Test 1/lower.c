#include "node.h"
BOOL IsLower_GM(int id1, int id2)
{
	int group1,group2,member1,member2;
	group1=id1%10000;
	group2=id2%10000;
	
	member1=(id1/10000)%1000;
	member2=(id2/10000)%1000;
	
	if((group1<group2) || (group1==group2 && member1<member2))
		return TRUE;
	return FALSE;
	
}
