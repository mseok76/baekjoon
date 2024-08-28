#include <stdio.h>

int main(){
    int T, n, k, num, pri;
    int arr[100];
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i =0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        num =0;
        pri = arr[k];

        int start = 0, a, b;
        for(int i =9;i>0;i--){
            a = start;
            b = a;
            for(a; a!=(b+n); a++){
                if(arr[a%n] == i){
                    num++;
                    if(a%n == k){
                        printf("%d\n",num);
                        i = 0;
                        break;
                        }
                    start = a%n+1;
                }
            }
        }

    }
}