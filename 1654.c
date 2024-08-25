#include <stdio.h>
#define INT_MAX 2147483647

int k,n;
int arr[10000];
long long cnt(long long length);

int main(){
    int max=0;
    long long length,right,left=1;
    scanf("%d %d",&k,&n);

    for(int i =0;i<k;i++){
        scanf("%d",&arr[i]);
        if(max < arr[i]) max = arr[i];
    }
    right = max;    //test

    if(cnt(1) < n){
        printf("0\n");
        return 0;
    }
    
    while(1){
        if(right - left <= 1){
            break;
        }
        length = (right+left)/2;
        if(cnt(length) >= n){
            left = length;
        }else{
            right = length-1;
        }
        // printf("<%d %d>\n",left,right);
    }
    if(cnt(right) >= n){
        printf("%lld\n",right);
    }else{
        printf("%lld\n",left);
    }

    return 0;
}

long long cnt(long long length){
    long long cnt=0;
    for(int i=0;i<k;i++){
        cnt += (arr[i] / length);
    }
    return cnt;
}