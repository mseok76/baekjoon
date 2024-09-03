#include <stdio.h>

int main(){
    int n,k,num=0,cnt;
    scanf("%d %d",&n,&k);
    int arr[1001] = {0};
    printf("<");
    for(int i =0;i<n-1;i++){
        cnt = k;
        while(1){
            num%=n;
            num++;
            if(arr[num] == 0) cnt--;
            if(cnt == 0){
                printf("%d, ",num);
                arr[num] = 1;
                break;
            }
        }
    }
    num=1;
    while(arr[num++] == 1);
    printf("%d>",num-1);
}