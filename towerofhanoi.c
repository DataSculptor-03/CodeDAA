#include<stdio.h>

void toh(int n,char a,char b,char c){
    if(n==1){
        printf("move the 1st disk from : %c to : %c\n",a,c);
        return;
    }
    toh(n-1,a,c,b);
    printf("move the %d disk from : %c to : %c\n",n,a,c);
    toh(n-1,b,a,c);
}

int main(){
    int n;
    printf("enter the number of disk:");
    scanf("%d",&n);
    toh(n,'a','b','c');
    return 0;
}