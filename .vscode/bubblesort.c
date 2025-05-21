#include<stdio.h>

void bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("array elements after sorting are:");
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
    bubble(arr,n);
    return 0;
}