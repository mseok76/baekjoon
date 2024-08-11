#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    int t;
    unsigned long long n,k,cnt,a;
    scanf("%d",&t);
    for(int i =0;i<t;i++){
        scanf("%llu %llu",&n,&k);
        for(int j=0;j<k;j++){
            n /= 2;
            if(n==0)break;
        }
        cnt = (n+1)/2;
        printf("%llu\n",cnt);
    }
}
