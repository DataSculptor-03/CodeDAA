#include<stdio.h>

void knapsack(int n,int capacity,int object[],float weight[],float profit[],float ratio[]){
    //Ratio calculation
    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }
    //sort the items
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //ratio sorting
            if(ratio[i]<ratio[j]){
                float temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;


                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }

    float totalprofit=0.0;
    float x[20]={0.0};

    //Capacity check
    for(int i=0;i<n;i++){
        if(capacity>=weight[i]){
            x[i]=1.00;
            totalprofit+=profit[i];
            capacity-=weight[i];
        }else{
            x[i]=(capacity/weight[i]);
            totalprofit+=x[i]*profit[i];
            break;
        }
    }

    printf("Fractional talen:\n");
    for(int i=0;i<n;i++){
        printf("Item %d taken:%f\n",i+1,x[i]);
    }

    printf("total profit is:%f\n",totalprofit);
}

int main(){
    int object[20],capacity,n;
    float weight[20],profit[20],ratio[20];

    printf("enter the total no of objects:");
    scanf("%d",&n);

    printf("enter the capacity of the knapsack:");
    scanf("%d",&capacity);

    printf("enter the weight of the objects:");
    for(int i=0;i<n;i++){
        scanf("%f",&weight[i]);
    }

    printf("enter the profits of all objects:");
    for(int i=0;i<n;i++){
        scanf("%f",&profit[i]);
    }

    knapsack(n,capacity,object,weight,profit,ratio);
    return 0;
}