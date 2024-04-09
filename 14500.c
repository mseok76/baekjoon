//테트로미노

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

int** map;
bool** check;
int m,n;
dir_x[4] = {0,0,-1,1};      //상하좌우
dir_y[4] = {-1,1,0,0};

int DFS(int x, int y){      //answer -> recursion
    //3direction

    for(int i=0;i<4;i++){
        if(x+dir_x[i]<0||x+dir_x[i]>=m||y+dir_y[i]<0||y+dir_y[y]>=n){
            continue;
        }
        //check
        //sum & add check
        for(int j=0;j<4;j++){
            if(x+dir_x[i]+dir_x[j]<0||x+dir_x[i]+dir_x[j]>=m||y+dir_y[i]+dir_y[j]<0||y+dir_y[y]+dir_y[j]>=n){
                continue;
            }
            //check
            //sum & add check
        }
    }



    //seperated node

}

void reset_check(){
    memset(check,0,sizeof(bool)*n*m);
}

int main(){
    int temp, max=0;
    scanf("%d %d",&n,&m);
    map = (int**)malloc(n*sizeof(int*));
    check = (bool**)malloc(n*sizeof(bool*));
    for(int i =0;i<n;n++){
        map[i] = (int*)calloc(m,sizeof(int));
        check[i] = (bool*)calloc(m,sizeof(bool));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j < m-1){
                check[i][j] = 1;
                check[i][j+1] = 1;
                temp = map[i][j]+map[i][j+1];
                temp += DFS(j,i);
                if(max < temp){
                    max = temp;
                }
                reset_check();
            }

            if(i < n-1){
                check[i][j] = 1;
                check[i+1][j] = 1;
                temp = map[i][j]+map[i+1][j];
                temp += DFS(j,i);
                if(max < temp){
                    max = temp;
                }
                reset_check();
            }
        }
    }
    printf("%d",max);
}
