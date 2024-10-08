#include <stdio.h>
#include <stdlib.h>

void rotate(int dir);
int* dice;

int main(){
    dice = (int*)calloc(6,sizeof(int));
    // dice[0] = 2;
    // dice[1] = 4;
    // dice[2] = 6;
    // dice[3] = 3;
    // dice[4] = 5;
    // dice[5] = 1;

    int dirx[4] = {1,-1,0,0};
    int diry[4] = {0,0,-1,1};
    int n,m,r,c,t,i,j;
    scanf("%d %d %d %d %d",&n,&m,&r,&c,&t);
    int** map = (int**)malloc(n*sizeof(int*));
    for(i =0;i<n;i++){
        map[i] = (int*)malloc(m*sizeof(int));
        for(j = 0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    //n이 세로, m이 가로
    //r이 세로, c가 가로
    //dir: 1 2 3 4 순서로 동 서 남 북
    int dir,x,y;
    while(t--){
        scanf("%d",&dir);
        y = r + diry[dir-1];
        x = c + dirx[dir-1];
        if(y < 0 || y >= n || x < 0 || x >= m){
            continue;
        }
        r = y;
        c = x;
        rotate(dir);
        if(map[r][c] == 0){
            map[r][c] = dice[2];
        }else{
            dice[2] = map[r][c];
            map[r][c] = 0;
        }

        printf("%d\n",dice[5]);
    }
    free(dice);

}


void rotate(int dir){
    int temp;
    switch (dir){
    case 1:
        temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[5];
        dice[5] = temp;
        break;

    case 2:
        temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[2];
        dice[2] = temp;
        break;
    
    case 3:
        temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[2];
        dice[2] = temp;
        
        break;

    case 4:
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[4];
        dice[4] = dice[5];
        dice[5] = temp;
        break;
    
    default:
        printf("ERR wrong direction");
    }
}