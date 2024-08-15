#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
    int t;
    unsigned long long n,k,cnt,a;
    scanf("%d",&t);
    for(int i =0;i<t;i++){
        scanf("%llu %llu",&n,&k);
        if(k > 60){
            printf("0\n");
            continue;
        }
        a = 1;
        a = a << k;
        if(n < a){
            printf("0\n");
            continue;
        }
        cnt = n/a;
        cnt = cnt/2;
        printf("%llu\n",cnt);
    }
}