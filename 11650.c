#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int* A = *(int**)a;
    int* B = *(int**)b;
    if(A[0] > B[0]){
        return 1;
    }else if(A[0] == B[0]){
        if(A[1] > B[1]){
            return 1;
        }
    }
    return -1;
}

int main(){
    int n,i;
    scanf("%d",&n);
    int** arr = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        arr[i] = (int*)malloc(sizeof(int)*2);
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    qsort(arr, n,sizeof(arr[0]),compare);
    for(i = 0;i<n;i++){
        printf("%d %d\n",arr[i][0], arr[i][1]);
    }

    for(i =0;i<n;i++){
        free(arr[i]);
    }
    free(arr);
}

