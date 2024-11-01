#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,ans,temp,last;
    scanf("%d",&n);
    int* bridge = (int*)malloc(n*sizeof(int));
    int* max = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&bridge[i]);
    }
    //max[n-1] = 1;
    for(int last =n-1;last >=0 ;last--){
        max[last] = 1;
        temp = last;
        while(++temp < n){
            //printf("last,temp %d %d %d\n",last,temp,max[temp]);
            if(bridge[last] >= bridge[temp]) continue;
            if(max[last] <= max[temp]){
                max[last] = max[temp]+1;
            }
        }
    }
    ans = 0;
    for(i =0;i<n;i++){
        //printf("%d,",max[i]);
        if(ans < max[i]) ans = max[i];
    }
    printf("%d\n",ans);

    free(max);
    free(bridge);
    return 0;
}