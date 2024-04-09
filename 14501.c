//퇴사
#include <stdio.h>
#include <stdlib.h>

int table[16][2];
int n;

int money(int day, int pay){
    int sum,max;
    max = pay;
    for(int i =day;i<=n;i++){
        if(i + table[i][0] > n+1){
            continue;
        }
        sum = money(i+table[i][0], pay + table[i][1]);
        if(max < sum){
            max = sum;
        }
    }
    // printf("max: %d\n",max);
    return max;
}

int main(){
    int pay,max;
    scanf("%d",&n);
    for(int i =1;i<=n;i++){
        scanf("%d %d",&table[i][0], &table[i][1]);
    }
    printf("%d",money(1,0));
}
