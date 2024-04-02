#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int rx;
    int ry;
    int bx;
    int by;
    int state;
}data;

typedef struct Node{
    data point;
    struct Node *next;
}Node;

typedef struct Queue{
    int count;
    Node *rear; //가장 최근(뒤) 노드의 주소
    Node *front; // 가장 과거(앞)의 노드 주소
}Queue;

int move();
data RB_moving(data point, int i);
data BR_moving(data point, int i);
data dequeue(Queue *queue);
void enqueue(Queue *queue, data point);
int isempty(Queue *queue);
void initQueue(Queue *queue);
int dir_x[4] = {0,0,-1,1};
int dir_y[4] = {1,-1,0,0};

Queue* ball;
char map[11][11];


int main(){
    data init;
    ball = (Queue*)calloc(1,sizeof(Queue));
    initQueue(ball);
    int n,m,depth =0, state=0;
    scanf("%d %d",&n,&m);
    getchar();
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
    //printf("%d %d %d %d\n",init.rx,init.ry,init.bx,init.by);

    enqueue(ball, init);
    while(state == 0){
        depth++;
        state = move();
        if(depth == 11) break;
        printf("queue count: %d\n",ball->count);
    }
    //state에 따라 결과 출력
    if(state == 0) printf("-1\n");
    else printf("%d\n",depth);
}

int move(){
    data point;
    data new_point;
    int n = ball->count;
    for(int i=0;i<n;i++){
        point = dequeue(ball);
        //up
        if(point.ry > point.by){
            new_point = RB_moving(point,0);
        }else{
            new_point = BR_moving(point,0);
        }
        if(new_point.state == 1){
            enqueue(ball, new_point);
        }else if(new_point.state == 2){
            return 1; //find
        }
        //down
        if(point.ry < point.by){
            new_point = RB_moving(point,1);
        }else{
            new_point = BR_moving(point,1);
        }
        if(new_point.state == 1){   //normal case
            enqueue(ball, new_point);
        }else if(new_point.state == 2){
            return 1; //find
        }
        //left
        if(point.rx < point.bx){
            new_point = RB_moving(point,2);
        }else{
            new_point = BR_moving(point,2);
        }
        if(new_point.state == 1){
            enqueue(ball, new_point);
        }else if(new_point.state == 2){
            return 1; //find
        }
        //right
        if(point.rx > point.bx){
            new_point = RB_moving(point,3);
        }else{
            new_point = BR_moving(point,3);
        }
        if(new_point.state == 1){
            enqueue(ball, new_point);
        }else if(new_point.state == 2){
            return 1; //find
        }

    }
    return 0;
}


data RB_moving(data point, int i){
    data new_point;
    int rx,ry,bx,by;
    rx = point.rx;
    ry = point.ry;
    bx = point.bx;
    by = point.by;
    new_point.state = 0;
    do{
        rx += dir_x[i];
        ry += dir_y[i];
        if(map[ry][rx] == 'O'){
            new_point.state = 2;
            return new_point;
        }
    }while(map[ry][rx]=='.');
    

    do{
        bx += dir_x[i];
        by += dir_y[i];
        if(map[by][bx]=='O'){
            new_point.state = 0;
        }
    }while(map[by][bx]=='.');
    
    if(point.rx == rx && point.ry ==ry&&point.bx==bx&&point.by==by){
        new_point.state=0;
    }
    return new_point;

}
data BR_moving(data point, int i){
    data new_point;
    int rx,ry,bx,by;
    rx = point.rx;
    ry = point.ry;
    bx = point.bx;
    by = point.by;
    new_point.state = 0;

    do{
        bx += dir_x[i];
        by += dir_y[i];
        if(map[by][bx]=='O'){
            new_point.state = 0;
            return new_point;
        }
    }while(map[by][bx]=='.');
    
    do{
        rx += dir_x[i];
        ry += dir_y[i];
        if(map[ry][rx] == 'O'){
            new_point.state = 2;
        }
    }while(map[ry][rx]=='.');
    
    if(point.rx == rx && point.ry ==ry&&point.bx==bx&&point.by==by){
        new_point.state=0;
    }
    return new_point;

}


void initQueue(Queue *queue){
    queue -> count = 0;
}

int isempty(Queue *queue){
    return queue->count == 0;
}

void enqueue(Queue *queue, data point){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> point = point;
    newNode -> next = NULL;
    if(isempty(queue)){
        queue->front = newNode;
    }else{
        queue->rear->next = newNode;
    }
    queue -> rear = newNode;
    queue -> count++;
}

data dequeue(Queue *queue){
    data point;
    Node *ptr;
    if(isempty(queue)){
        printf("Error, Queue is empty!\n");
        return point;
    }
    ptr = queue->front;
    point = ptr->point;
    queue->front = ptr->next;
    free(ptr);
    queue->count--;

    return point;
}