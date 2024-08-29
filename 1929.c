//에라토스테네스의 채
//Sieve of Eratosthenes

#include <stdio.h>
#include <stdbool.h>

int main(){
    int start, end, num = 2, temp;
    bool arr[1000001] = {0};
    arr[1] = 1;
    scanf("%d %d",&start, &end);

    while(num != end){
        if(arr[num] == 1){
            num++;
        }else{
            temp = 2*num;
            while(temp <= end){
                arr[temp] = 1;
                temp += num;
            }
            num++;
        }
    }

    for(int i = start;i<=end;i++){
        if(arr[i] == 0) printf("%d\n",i);
    }
    return 0;
}