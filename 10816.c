#include <stdio.h>
#include <stdlib.h>
#define val 10000000

int main(){
    int n, m, temp;
    
    scanf("%d",&n);
    int* arr = (int*)calloc(2*val,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        arr[val+temp]++;
    }

    scanf("%d",&m);
    for(int i =0;i<m;i++){
        scanf("%d",&temp);
        printf("%d ",arr[val+temp]);
    }

}