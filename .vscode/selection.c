#include<stdio.h>

void selection(int n,int arr[]){
    int min,temp;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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
    selection(n,arr);
    return 0;
}