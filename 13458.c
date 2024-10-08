#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,b,c,tmp;
    long long ans =0;
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d %d",&b,&c);
    for(int i=0;i<n;i++){
        if(arr[i] <= b){
            ans++;
            continue;
        }else{
            tmp = (arr[i]-b)%c;
            ans += (long long)(tmp? (arr[i]-b)/c + 2 : (arr[i]-b)/c + 1);
        }
    }

    printf("%lld",ans);
    free(arr);
}