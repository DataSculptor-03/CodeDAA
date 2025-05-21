#include<stdio.h>

void merge(int arr[],int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int k=0;
    int temp[end-start+1];
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[start + i] = temp[i];
    }

    printf("Sorted elements in the array are:\n");
    for(int i=0;i<k;i++){
        printf("%d ",temp[i]);
        printf("\n");
    }
}
//1st part to written
void mergesort(int arr[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
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
    mergesort(arr,0,n-1);
    return 0;
}