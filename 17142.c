//17142 연구소3 삼성 기출

#include <stdio.h>
#include <stdlib.h>

int** map;
int** check;
int act[10];
int deact[10][2];
int ans, deact_cnt, empty_cnt, n, m, id;
int queue[2501][2];

void combination(int cnt){
    int start, temp;
    if(cnt == m){
        //BFS
        id++;
        int top = 0, bot = 0, count = 0,x,y;
        int empty = empty_cnt;
        int dirx[4] = {1,-1,0,0};
        int diry[4] = {0,0,1,-1};
        for(int i =0;i<m;i++){      //start point
            queue[top][0] = deact[act[i]][0];
            queue[top++][1] = deact[act[i]][1];
            check[deact[act[i]][0]][deact[act[i]][1]] = id;
            // printf("%d %d / ",deact[act[i]][0],deact[act[i]][1]);
        }
        // printf("---\n");
        while(top > bot){
            if(empty == 0){
                ans = count;
                // printf("*%d*\n",ans);
                break;
            }
            count++;
            // printf("count %d\n",count);
            if(count > ans){break;}
            temp = top-bot;
            for(int i =0;i<temp;i++){
                int out[2] = {queue[bot][0], queue[bot++][1]};
                for(int j =0;j<4;j++){
                    y = out[0] + diry[j];
                    x = out[1] + dirx[j];
                    if(y < 0 || y >= n || x < 0 || x >= n || check[y][x] == id){
                        continue;
                    }

                    if(map[y][x] == 1){
                        continue;
                    }
                    // printf("xy: %d %d\n",x,y);
                    if(map[y][x] == 2){
                        check[y][x] = id;
                        queue[top][0] = y;
                        queue[top++][1] = x;
                    }else{
                        empty--;
                        // printf("--\n");
                        check[y][x] = id;
                        queue[top][0] = y;
                        queue[top++][1] = x;
                    }
                    
                }
            }

        }

    }else{
        //combination
        if(cnt == 0){
            start = 0;
        }else{
            start = act[cnt-1] + 1;
        }
        for(int i =start;i<deact_cnt;i++){
            act[cnt] = i;
            combination(cnt+1);
        }
    }
}

int main(){
    int i, j;
    ans = 2500;
    empty_cnt = 0;
    id = 0;
    scanf("%d %d",&n,&m);
    map = (int**)malloc(n*sizeof(int*));
    check = (int**)malloc(n*sizeof(int*));
    deact_cnt = 0;
    for(i =0;i<n;i++){
        map[i] = (int*)malloc(n*sizeof(int));
        check[i] = (int*)malloc(n*sizeof(int));
    }
    for(i =0;i<n;i++){
        for(j =0;j<n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2){
                deact[deact_cnt][0] = i;
                deact[deact_cnt++][1] = j;
            }else if(map[i][j] == 0) empty_cnt++;
        }
    }
    // printf("empty: %d\n",empty_cnt);
    combination(0);

    if(ans == 2500) printf("-1\n");
    else printf("%d\n",ans);
    for(i =0 ;i<n;i++){
        free(map[i]);
        free(check[i]);
    }
    free(map);
    free(check);
}
