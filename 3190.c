#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int x;
    int y;
    struct _node* next;
}node;

node* head;
node* tail;
int count = 0;

void enqueue(int x, int y){
    node* t = (node*)malloc(sizeof(node));
    if(count == 0){
        head = t;
        tail = t;
    }else{
        tail->next = t;
    }
    t->next = NULL;
    tail = t;
    t->x = x;
    t->y = y;
    count++;
}

node* dequeue(){
    node* t = (node*)malloc(sizeof(node));
    if(count == 0){
        printf("No more queue to pop");
        return t;
    }
    t = head;
    head = head->next;
    count--;
    return t;
}

int map[100][100] = {0};
char direction[10000] = {'\0'};
int dirx[4] = {0,-1,0,1};
int diry[4] = {-1,0,1,0};

int main(){
    int n,k,l,x,y,init,time;
    int dir = 3; //right
    char aa;
    node* temp;
    map[0][0] = 1;
    enqueue(0,0);

    scanf("%d",&n); //n is size of map
    scanf("%d",&k); //k is number of apple
    for(int i=0;i<k;i++){
        scanf("%d %d",&x,&y);
        map[--y][--x] = 2;
    }
    scanf("%d",&l);
    for(int i =0;i<l;i++){
        scanf("%d %c",&init, &aa);
        direction[init-1] = aa;
    }
    x=0;
    y=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }

    for(time=0;time<10000;){
        printf("count: %d\n",count);
        if(direction[time] > 'A'){
            if(direction[time] == 'D'){
                if(dir == 0){
                    dir = 3;
                }else{
                    dir--;
                }
            }else if(direction[time] == 'L'){
                if(dir == 3){
                    dir = 0;
                }else{
                    dir++;
                }
            }
        }
        //changed direction
        x+= dirx[dir];
        y+= diry[dir];
        time++;
        if(x >= n||y>=n||x<0||y<0){ //wall
            break;
        }
        printf("%d %d\n",x,y);
        enqueue(x,y);
        if(map[y][x] != 2){
            temp = dequeue();
            map[temp->y][temp->x] = 0;
            free(temp);
        }
        if (map[y][x] == 1 ){
            break;
        }else{
            map[y][x] = 1;
        }
    }
    printf("%d",time+2);
}