//테트로미노
//브루트포스

#include <stdio.h>
#include <stdlib.h>


int main(){
    //define every shape
    int tetris[19][6] = {  //x y 순으로 나머지 3개의 점에 대한 상대 좌표
    {1,0,2,0,3,0},{0,1,0,2,0,3},{1,0,0,1,1,1},
    {0,1,0,2,1,2},{0,1,0,2,-1,2},{1,0,0,1,0,2},{1,0,1,1,1,2},
    {0,1,1,1,2,1},{0,1,1,0,2,0},{1,0,2,0,2,-1},{1,0,2,0,2,1},
    {0,1,1,1,1,2},{0,1,-1,1,-1,2},{1,0,1,1,2,1},{1,0,1,-1,2,-1},
    {1,0,1,1,2,0},{1,0,1,-1,2,0},{0,1,1,1,0,2},{0,1,-1,1,0,2}
    };

    int n,m,i,j;    //세로가 n,y 가로가 m,x
    scanf("%d %d",&n,&m);
    int** map = (int**)calloc(n,sizeof(int*));
    for(i =0;i<n;i++){
        map[i] = (int*)calloc(m,sizeof(int));
        for(j = 0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    // printf("flag\n");
    // for(i = 0;i<n;i++){
        
    // }
    int x,y,temp,ans = 0;
    for(i =0;i<n;i++){
        for(j=0;j<m;j++){
            for(int k =0;k<19;k++){
                temp = map[i][j];
                for(int t = 0;t<3;t++){
                    x = j + tetris[k][2*t];
                    y = i + tetris[k][2*t+1];
                    if(x < 0 || x >= m || y < 0 || y >= n){
                        temp =0;
                        break;
                    }
                    temp += map[y][x];
                }
                if(temp > ans){
                        ans = temp;
                }
            }
        }
    }
    printf("%d\n",ans);

    for(i=0;i<n;i++){
        free(map[i]);
    }
    free(map);
}