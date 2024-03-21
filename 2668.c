#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100001

bool visited[2][MAX];
int N, cnt;
int * arr;
int* team;

void dfs(int num){
    visited[0][num] = true;
    int rink = arr[num];
    if (!visited[0][rink]) dfs(rink);
    else if (!visited[1][rink]){
        int self = rink;
        team[self] = 1;
        while (self != num){
            self = arr[self];
            team[self] = 1;
            cnt++;
        }
        cnt++;
    }
    visited[1][num] = true;
}
int main(){

    for(int i=0;i<2;i++){
        for(int j=0;j<MAX;j++){
            visited[i][j] = 0;
        }
    }
    cnt = 0;
    
    scanf("%d", &N);  
    arr = (int*)malloc((N+1)*sizeof(int));
    team = (int*)calloc(N+1,sizeof(int));  
    for (int i = 1; i <= N; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++){
        if (!visited[0][i]){
            dfs(i);
        }
    }
        

    printf("%d\n",cnt);
    for(int i=1;i<=N;i++){
        if(team[i] == 1)printf("%d\n",i);
        //printf("%d ",team[i]);
    }

}