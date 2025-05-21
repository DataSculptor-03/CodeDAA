#include<stdio.h>

void insertion(int n,int arr[]){
    int j;
    for(int i=1;i<n;i++){
        int temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
    printf("Array elements after sorting are: ");
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
    insertion(n,arr);
    return 0;
}