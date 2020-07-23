#include<stdio.h>
#include<time.h>

//Merge Sort

void _printArr(int arr[],int n);
void merge(int arr[],int s,int m,int e);
void mergeSort(int arr[],int s,int e);

void _printArr(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void merge(int arr[],int s,int m,int e){
	
	/*s initial value
	m middle value
	e is the final value*/
	
	//I found the size of the arrays on the left and right.
	int n1=m-s+1;
	int n2=e-m;
	
	
	int left[n1+1];//We'll put a larger value at the end than any other number so you can compare.
	int right[n2+1];
	
	int i;
	for(i=0;i<n1;i++){
		left[i]=arr[s+i];
	}
	for(i=0;i<n2;i++){
		right[i]=arr[m+i+1];
	}
	
	//If the elements in the series on the right or left are over, we write them so that the elements in the other series are sorted.
	left[n1]=right[n2-1]+1;
	right[n2]=left[n1-1]+1;
	
	
	
	int l_indx=0;
	int r_indx=0;
	for(i=s;i<=e;i++){
		if(left[l_indx]<=right[r_indx]){
			arr[i]=left[l_indx];
			l_indx++;
		}
		else{
			arr[i]=right[r_indx];
			r_indx++;
		}
	}
	
	
	
	
}

void mergeSort(int arr[],int s,int e){
	
	if(s<e){
		int m=(s+e)/2;
		mergeSort(arr,s,m);
		mergeSort(arr,m+1,e);
		merge(arr,s,m,e);
	}
	
}

int main(){
	
	int n,k;
	
	time_t t;
	
	srand(time(NULL));
	
	printf("Enter size of array:");
	scanf("%d",&n);
	
	int arr[n];
	
	
	for(k=0;k<n;k++){
		arr[k]=(rand() %50);
	}
	
	_printArr(arr,n);
	
	mergeSort(arr,0,n);
	
	_printArr(arr,n);
	
	
	
	return 0;
}
