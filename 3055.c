#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    int count;
    Node *rear; //가장 최근(뒤) 노드의 주소
    Node *front; // 가장 과거(앞)의 노드 주소
}Queue;

void initQueue(Queue *queue);
int isempty(Queue *queue);
void enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
int bfs(Queue *hod, Queue *water);
void water_diffuse(int y,int x);
int hod_diffuse(int y,int x);
char **array;
int w,h;
Queue *hod;
Queue *water;

int main(){
    initQueue(hod);
    initQueue(water);
    scanf("%d %d",&h,&w);
    array = (char**)malloc(h,sizeof(char*));
    for(int i=0;i<h;i++){
        array[i] = (char*)malloc(w,sizeof(char));
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%c",&array[i][j]);
            if(array[i][j] == 'S'){
                enqueue(hod,i);
                enqueue(hod,j);
            }else if(array[i][j] == '*'){
                enqueue(water,i);
                enqueue(water,j);
            }
        }
    }
    int depth =0,a;
    a = bfs(hod, water);
    if(a == -1){
        printf("KAKTUS\n");
    }else{
        printf("%d",a);
    }
    return 0;
}



int bfs(Queue *hod, Queue *water){
    int x,y,a, count =0;
    do{
        count ++;
        for(int i=0;i<water -> count;i+=2){
            y = dequeue(water);
            x = dequeue(water);
            water_diffuse(y,x);
        }

        for(int i=0;i<water -> count;i+=2){
            y = dequeue(water);
            x = dequeue(water);
            a = hod_diffuse(y,x);
            if(a) return count;
        }

    }while(hod -> count != 0);
    return -1;
}

int hod_diffuse(int y, int x){
    if(y+1 < h){
        if(array[y+1][x] == 'D'){
            return 1;
        }else if(array[y+1][x] == '.'){
            enqueue(hod, y);
            enqueue(hod, x);
        }
    }
    if(y > 0){
        if(array[y-1][x] == 'D'){
            return 1;
        }else if(array[y-1][x] == '.'){
            enqueue(hod, y);
            enqueue(hod, x);
        }
    }
    if(x+1 < w){
        if(array[y][x+1] == 'D'){
            return 1;
        }else if(array[y][x+1] == '.'){
            enqueue(hod, y);
            enqueue(hod, x);
        }
    }
    if(y > 0){
        if(array[y-1][x] == 'D'){
            return 1;
        }else if(array[y-1][x] == '.'){
            enqueue(hod, y);
            enqueue(hod, x);
        }
    }
}

void water_diffuse(int y, int x){
    if(y+1 < h){

    }
    if(y > 0){

    }
    if(x+1 < w){

    }
    if(y > 0){
        
    }
}

void initQueue(Queue *queue){
    return queue -> count =0;
}

int isempty(Queue *queue){
    return queue->count == 0;
}

void enqueue(Queue *queue, int data){
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

int dequeue(Queue *queue){
    int data;
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