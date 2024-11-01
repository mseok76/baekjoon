#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,n,k,a,b;
    double sum;
    scanf("%d %d",&n,&k);
    int* score = (int*)malloc(n*sizeof(int));
    for(i =0;i<n;i++){
        scanf("%d",&score[i]);
    }
    while(k--){
        scanf("%d %d",&a,&b);
        sum=0;
        for(i=a-1;i<b;i++){
            sum += score[i];
        }
        printf("%.2f\n",sum/(b-a+1));
    }
    return 0;
}