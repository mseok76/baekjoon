#include<stdio.h>

int main(){
    int stack[100001];
    int cnt,temp,n,sum=0;
    scanf("%d",&n);
    cnt = 0;
    while(n--){
        scanf("%d",&temp);
        if(temp == 0){
            cnt--;
        }else{
            stack[cnt++] = temp;
        }
    }
    for(int i=0;i<cnt;i++){
        sum+=stack[i];
    }
    printf("%d",sum);
}