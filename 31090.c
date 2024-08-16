#include <stdio.h>

int main(){
    int n,t,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        a = n%100;
        if(!a){
            printf("Bye\n");
            continue;
        }
        if((n+1)%a == 0)printf("Good\n");
        else printf("Bye\n");
    }
}