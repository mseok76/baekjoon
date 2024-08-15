#include<stdio.h>

int main(){
    int T,m,n,k,temp,cnt;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&m,&n);
        if(m<n){
            temp=m;
            m=n;
            n=temp;
        }
        if(m==n){
            printf("%d 3\n",m);
        }else if(m <= n*2){
            printf("%d 7\n",n);
        }else{
            k = n+1;
            if(m+n == 2*k){
                printf("%d 5\n",k);
            }
            else if(m <= 2*n+2){
                printf("%d 7\n",k);
            }else{
                printf("%d %d\n",k,2*(m-2*k)+7);
            }
        }
    }
}
