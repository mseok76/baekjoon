#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int rx;
    int ry;
    int bx;
    int by;
}data;

typedef struct Node{
    int *data;
    struct Node *next;
}Node;

typedef struct Queue{
    int count;
    Node *rear; //가장 최근(뒤) 노드의 주소
    Node *front; // 가장 과거(앞)의 노드 주소
}Queue;

int* dequeue(Queue *queue);
void enqueue(Queue *queue, int *data);
int isempty(Queue *queue);
void initQueue(Queue *queue);
int move();
int R_direction(int x, int y, int* data,int dir);
int B_direction(int x, int y, int* data,int dir);


Queue* ball;
char map[10][10];
int main(){
    data init;
    ball = (Queue*)calloc(1,sizeof(Queue));
    initQueue(ball);
    int n,m,depth =0, state=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%c",&map[i][j]);
            if(map[i][j] == 'R'){
                init.rx = j;
                init.ry = i;
            }else if(map[i][j] == 'B'){
                init.bx = j;
                init.by = i;
            }
        }
        getchar();
    }
    enqueue(ball, init);
    while(state == 0){
        depth++;
        state = move();
        if(depth == 50) break;
    }
    //state에 따라 결과 출력
    if(state == 0) printf("-1\n");
    else printf("%d\n",depth);
}

int move(){
    data = dequeue(ball);
    int rx = data[0];
    int ry = data[1];
    int bx = data[2];
    int by = data[3];
    int state = 0;
    //up
    if(ry < by){    //R first
        if(R_direction(rx,ry,data,0)) return 1;
        if(B_direction(bx,by,data,0)) state = 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }else{
        if(B_direction(bx,by,data,0)) state = 1;
        if(R_direction(rx,ry,data,0)) return 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }
    //down
    if(ry > by){    //R first
        if(R_direction(rx,ry,data,1)) return 1;
        if(B_direction(bx,by,data,1)) state = 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }else{
        if(B_direction(bx,by,data,1)) state = 1;
        if(R_direction(rx,ry,data,1)) return 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }
    //left
    if(rx < bx){    //R first
        if(R_direction(rx,ry,data,2)) return 1;
        if(B_direction(bx,by,data,2)) state = 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }else{
        if(B_direction(bx,by,data,2)) state = 1;
        if(R_direction(rx,ry,data,2)) return 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }
    //right
    if(rx > bx){    //R first
        if(R_direction(rx,ry,data,3)) return 1;
        if(B_direction(bx,by,data,3)) state = 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }else{
        if(B_direction(bx,by,data,3)) state = 1;
        if(R_direction(rx,ry,data,3)) return 1;
        if(state == 0) enqueue(ball,data);
        state = 0;
    }
    return 0;
}

int R_direction(int x, int y, int* data,int dir){
    if(dir == 0){   //up
        while(1){
            if (map[--y][x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }else if(dir == 1){ //down
        while(1){
            if (map[++y][x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }else if(dir == 2){ //left
        while(1){
            if (map[y][--x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }else if(dir == 3){ //right
        while(1){
            if (map[y][++x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }
    data[0] = ++x;
    data[1] = ++y;
}

int B_direction(int x, int y, int* data,int dir){
    if(dir == 0){   //up
        while(1){
            if (map[--y][x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }else if(dir == 1){ //down
        while(1){
            if (map[++y][x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }else if(dir == 2){ //left
        while(1){
            if (map[y][--x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }else if(dir == 3){ //right
        while(1){
            if (map[y][++x] != '.'){
                if(map[y][x] == 'O') return 1;
                else break;
            }
        }
    }
    data[2] = ++x;
    data[3] = ++y;
}

void initQueue(Queue *queue){
    queue -> count = 0;
}

int isempty(Queue *queue){
    return queue->count == 0;
}

void enqueue(Queue *queue, int *data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(isempty(queue)){
        queue->front = newNode;
    }else{
        queue->rear->next = newNode;
    }
    queue -> rear = newNode;
    queue -> count++;
}

int* dequeue(Queue *queue){
    int* data;
    Node *ptr;
    if(isempty(queue)){
        printf("Error, Queue is empty!\n");
        return 0;
    }
    ptr = queue->front;
    data = ptr->data;
    queue->front = ptr->next;
    free(ptr);
    queue->count--;

    return data;
}