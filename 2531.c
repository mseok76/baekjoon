#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 개선 방안 : 슬라이딩 윈도우 기법으로 eaten 배열을 전체 초기화하지 말고
// 앞의 1개를 초기화, 뒤의 1개를 update하면 해결될듯

int set_arr(bool* eaten, int d);

int main(){
    int n,d,k,c;
    scanf("%d %d %d %d",&n, &d, &k, &c);
    int* sushi = (int*)calloc(n,sizeof(int));
    bool* eaten = (bool*)calloc(d+1,sizeof(int));
    int i,j,cnt,max=0;

    for(i =0;i<n;i++){
        scanf("%d",&sushi[i]);
    }

    for(i=0;i<n;i++){
        set_arr(eaten,d);
        cnt = 0;
        for(j=i;j<k+i;j++){
            if(eaten[sushi[j%n]] == 0){
                cnt++;
                eaten[sushi[j%n]] = 1;
            }
        }
        // printf("\n");
        // for(int k=0;k<d+1;k++){
        //     printf("%d ",eaten[k]);
        // }
        // printf("\n");
        if(eaten[c] == 0) cnt++;
        if(max < cnt) max = cnt;
    }
    printf("%d\n",max);
    free(sushi);
    free(eaten);
}

int set_arr(bool* eaten,int d){
    for(int i =0;i<d+1;i++){
        eaten[i] = 0;
    }
    return 0;
}