#include <stdio.h>

int main(){
    int diry[4] = {-1,0,0,1};   //북 서 동 남
    int dirx[4] = {0,-1,1,0};
    int n,m,fuel,i,j,x,y;
    int car[2];
    scanf("%d %d %d",&n,&m,&fuel);
    int** map = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        map[i] = (int*)malloc(n*sizeof(n));
        for(j =0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    scanf("%d %d",&car[0],&car[1]);  // y x 순으로 입력
    for(i =2;i<2+m;i++){
        scanf("%d %d",&y,&x);
        map[y][x] = i;
        scanf("%d %d",&y,&x);
        map[y][x] = -1*i;       //시작점은 양수 도착점은 음수. 승객은 2 이상의 값.
    }

    //BFS start
    int queue[401][2];
    int top, bot;
    for(int pas = 0;pas<m;pas++){
        //승객 찾기
        top =0;
        bot =0;
        while(top > bot){

        }
    }

}