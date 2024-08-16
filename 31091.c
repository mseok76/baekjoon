#include <stdio.h>

int main(){
    int n,k,cnt,tot=0;
    int ret[500000];
    int arr[500000];
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(k=0;k<=n;k++){
        cnt =0;
        for(int i =0;i<n;i++){
            if(arr[i] < 0){
                if((-arr[i])<k) cnt++;
            }else{
                if(arr[i] > k) cnt++;
            }
        }
        if(cnt == k) ret[tot++] = k;
    }
    printf("%d\n",tot);
    for(int i =0;i<tot;i++){
        printf("%d ",ret[i]);
    }
}