//https://softeer.ai/app/assessment/index.html?xid=269927&xsrfToken=4M6bnHN8h9VgLx2ELHieKsYi47mjU4C3&testType=practice

#include <stdio.h>

int arr[20][100][2];
int cnt_k[5];
int K,ans;

void DFS(int k, int minx, int miny, int maxx, int maxy);

int main(void)
{
    int n,i;
    scanf("%d %d",&n,&K);
    if(K == 1){
        printf("0");
        return 0;
    }
    int x,y,k,minx,miny,maxx,maxy;
    for(i=0;i<5;i++){
        cnt_k[i] = 0;
    }
    // printf("\n--\n");
    for(i = 0;i<n;i++){
        scanf("%d %d %d",&x,&y,&k);
        arr[k-1][cnt_k[k-1]][0] = x;
        arr[k-1][cnt_k[k-1]][1] = y;
        cnt_k[k-1]++;
    }
    ans = 5000000;
    // printf("\n");
    // for(i =0; i<5;i++){
    //     printf("%d ",cnt_k[i]);
    // }
    // printf("\n");
    for(i =0; i<cnt_k[0];i++){
        minx = arr[0][i][0];
        miny = arr[0][i][1];
        maxx = arr[0][i][0];
        maxy = arr[0][i][1];
        // printf("+");
        DFS(1,minx,miny,maxx,maxy);
    }
    printf("%d",ans);
    return 0;
}
// 7 3
// -4 0 1
// -5 -1 1
// 0 43 2
// 3 23 3
// 8 -19 2
// 10 0 3
// 20 0 2
void DFS(int k, int minx, int miny, int maxx, int maxy){
    //현재 min 값 backup... int 값으로 전달이므로 필요x
    int x,y,size;
    int axis[4] = {minx,miny,maxx,maxy};
    for(int i =0;i<cnt_k[k];i++){
        axis[0] = minx;
        axis[1] = miny;
        axis[2] = maxx;
        axis[3] = maxy;
        // printf("flag %d-%d\n",k,i);
        x = arr[k][i][0];
        y = arr[k][i][1];
        // printf("x:%d, y:%d\n",x,y);
        if(minx > x){
            axis[0] = x;
            axis[2] = maxx;
        }else if(maxx < x){
            axis[0] = minx;
            axis[2] = x;
        }
        if(miny > y){
            axis[1] = y;
            axis[3] = maxy;
        }else if(maxy < y){
            axis[1] = miny;
            axis[3] = y;
        }
        // printf("-y %d %d\n",axis[1],axis[3]);
        size = (axis[2] - axis[0])*(axis[3] - axis[1]);
        // printf("find\n");
        if(size > ans){
            continue;
        }
        if(k+1<K){
            // printf("k-%d, %d %d %d %d\n",k,minx,miny,maxx,maxy);
            DFS(k+1,axis[0],axis[1],axis[2],axis[3]);
        }else{
            // printf("%d %d %d %d update\n",axis[0],axis[1],axis[2],axis[3]);
            ans = size;
        }
    }

}