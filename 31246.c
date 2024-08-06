#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b);

int main(){
    int n,k,a,b,cnt=0,j=0;
    int arr[100000];
    scanf("%d %d",&n,&k);
    for(int i =0;i<n;i++){
        scanf("%d %d",&a,&b);
        if(a>=b) cnt++;
        else arr[j++] = (b-a);
    }
    if(k <= cnt) printf("0\n");
    else{
        k-=cnt;
        qsort(arr,n-cnt,sizeof(int),compare);
        // printf("cnt = %d\n",cnt);
        // for(int k =0;k<n-cnt; k++){
        //     printf("%d  ",arr[k]);
        // }
        printf("%d\n",arr[k-1]);
    }
    return 0;

}

int compare(const void* a, const void* b){
    return *(int*)b < *(int*)a;
}