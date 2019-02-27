#include <merge.h>
void mergeSortRec(Element arr[],int l, int r){
	if(r>l){
		int mid = (l+r)/2;
		mergeSortRec(arr,l,mid);
		mergeSortRec(arr,mid+1,r);
		Element newarr[r-l+1];

		recspace += sizeof(int)+(r-l+1)*sizeof(Element);

		merge(arr+l,mid-l+1,arr+mid+1,r-mid,newarr);
		for(int i=0;i<r-l+1;i++){
			arr[l+i]=newarr[i];
		}

/*	FOR DEBUGGING
		printf("%d %d\n",l,r);
		for(int i=0;i<3;i++){
			printf("%lf ",arr[i].cgpa);
		}
		putchar('\n');
*/

	}
}

void mergeSort(Element arr[],int n){
	mergeSortRec(arr,0,n-1);
}