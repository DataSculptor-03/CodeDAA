#include<stdio.h>

void minmax(int arr[],int i,int j,int *min,int *max){
    int max1,max2,min1,min2;
    if(i==j){
        *min=*max=arr[i];
        return;
    }
    if(j==i+1){
        if(arr[i]<arr[j]){
            *max=arr[j];
            *min=arr[i];
        }else{
            *max=arr[i];
            *min=arr[j];
        }
        return;
    }
    int mid=(i+j)/2;
    minmax(arr,i,mid,&min1,&max1);
    minmax(arr,mid+1,j,&min2,&max2);

    *min=(min1<min2)?min1:min2;
    *max=(max1<max2)?max2:max1;
}

int main(){
    int n,max,min;
    int arr[20];
    printf("enter the array size:");
    scanf("%d",&n);
    printf("enter the array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    minmax(arr,0,n-1,&min,&max);
    printf("maximum elements in the array is: %d\n",max);
    printf("minimum elements in the array is: %d\n",min);
    return 0;
}