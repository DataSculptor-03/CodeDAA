#include<stdio.h>

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;

        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;

        heapify(arr,i,0);
    }
    printf("elements after sorting is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    int arr[20];
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("enter the array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    return 0;
}