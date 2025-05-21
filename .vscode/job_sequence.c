#include<stdio.h>

void job(int n,int profit[],int deadline[]){
    //Found the maxdeadline
    int maxdeadline=0;
    for(int i=0;i<n;i++){
        if(deadline[i]>maxdeadline){
            maxdeadline=deadline[i];
        }
    }
    //Built an new array of the highest size of maximum deadline
    int slot[maxdeadline];
    for(int i=0;i<maxdeadline;i++){
        slot[i]=-1;
    }
    //sort jobs and deadlines 
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(profit[j]<profit[j+1]){
                //sort profits in descending order

                int temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;

                //sort deadlines
                temp=deadline[j];
                deadline[j]=deadline[j+1];
                deadline[j+1]=temp;
            }
        }
    }

    int total=0;

    //put the value of the index in the array slot
    for(int i=0;i<n;i++){
        for(int j=deadline[i]-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                total+=profit[i];
                break;
            }
        }
    }

    //print sob sequences
    printf("Job Sequences are:\n");
    for(int i=0;i<maxdeadline;i++){
        if(slot[i]!=-1){
            printf("Job:%d ",slot[i]+1);
        }
    }

    printf("\n");
    //print the total profit
    printf("Total profit is: %d",total);

}

int main(){
    int n;
    int profit[20],deadline[20];
    printf("enter the number of jobs:");
    scanf("%d",&n);

    //enter the profit amount of every jobs
    printf("enter the profit amount:");
    for(int i=0;i<n;i++){
        scanf("%d",&profit[i]);
    }

    //enter the deadline of every jobs
    printf("enter the deadlines:");
    for(int i=0;i<n;i++){
        scanf("%d",&deadline[i]);
    }

    //call the job function
    job(n,profit,deadline);

    return 0;
}