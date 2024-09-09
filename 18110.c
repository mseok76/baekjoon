#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(){
    double n, cut, sum = 0;
    int arr[300000];
    scanf("%lf",&n);
    if(n == 0){
        printf("0\n");
        return 0;
    }
    cut = n * 0.15;
    cut = round(cut);
    // printf("cut : %lf\n",cut);       //testing code

    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);

    for(int i = cut; i< n - cut; i++){
        sum += arr[i];
    }
    sum = round(sum / (n-2*cut));
    printf("%.0lf\n",sum);
}

int compare(const void* a, const void* b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A > B) return 1;
    else if(A < B) return -1;
    else return 0;
}