#include <stdio.h>
#include <stdlib.h>
// No.12100

int* moving(int* map, int dir);
int DFS(int* map, int depth);
void collect(int* moved_map,int dir);

int n,half=0;
int dir_y[5] = {-1,1,0,0};
int dir_x[5] = {0,0,1,-1};
int dirx[4] = {1,1,0,0};
int diry[4] = {0,0,1,1};

int main(){
    scanf("%d",&n);
    int* map = (int*)malloc(n*n*sizeof(int));
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i*n+j]);
            half += map[i*n+j];
        }
    }
    half = half/2;
    printf("%d\n",half);
    int depth =0;
    printf("%d",DFS(map, depth));
    free(map);
}

int DFS(int* map, int depth){;
    int* new_map = (int*)malloc(n*n*sizeof(int));
    int max[5] = {0};
    int* moved_map;
    for(int i = 0;i<n;i++){ //copy
        for(int j =0;j<n;j++){
            new_map[j+i*n] = map[i*n+j];
            if(map[i*n+j]>max[0]){
                max[0] = map[i*n+j];
            }
        }
    }
    if(depth == 4 || max[0] > half){   //종료 조건
        return max[0];
    }
    depth++;
//4 direction
    printf("flag2 depth:%d\n",depth);
    for(int i =0;i<4;i++){
        moved_map = moving(new_map,i);
        printf("test");
        max[i+1] = DFS(moved_map,depth);
    }
    printf("before free\n");
    free(moved_map);
    printf("after free\n");
//max of 5 value
    for(int i =1;i<5;i++){
        if(max[0] < max[i]){
            max[0] = max[i];
        }
    }
    printf("depth: %d,\tmax: %d\n",depth-1,max[0]);
    free(new_map);
    depth--;
    return max[0];
}


int* moving(int* map, int dir){
    int* moved_map = (int*)calloc(n*n,sizeof(int));
    for(int i = 0;i<n;i++){ //copy
        for(int j =0;j<n;j++){
            moved_map[j+i*n] = map[i*n+j];
        }
    }
    printf("flag1\n");

    int x,y,position, count =0;
    int comp1, comp2;
    switch (dir)
    {
    case 0:
        x = 0;
        y = 0;
        break;
    case 1:
        x = 0;
        y = n-1;
        break;
    case 2:
        x = 0;
        y = 0;
        break;
    case 3:
        x = n-1;
        y = 0;
    }
    for(int i=0;i<n;i++){   //시작점도 dir배열을 이용해서 선언하기....?
        do{
            if(moved_map[x+y*n] == 0){
                continue;
            }
            comp1 = moved_map[x+y*n];
            position = x+y*n;
            x+= dir_x[dir];
            y+= dir_y[dir];
            count++;

            while(moved_map[x+y*n] == 0 && count < n-1){
                x+=dir_x[dir];
                y+=dir_y[dir];
                count++;
            }
            comp2 = moved_map[x+y*n];
            if(comp1 == comp2){
                //input
                printf("here\n");
                moved_map[x+y*n] = comp1*2;
                moved_map[position] = 0;
            }
        }while(count < n-1);
        x+=dirx[dir];
        y+=diry[dir];
    }//0 없이 몰기
    collect(moved_map,dir);
    return moved_map;
}

void collect(int* moved_map, int dir){
    int stackx, stacky;
    if(dir == 0){
        stackx = 0;
        stacky = 0;
    }else if(dir == 1){

    }
}