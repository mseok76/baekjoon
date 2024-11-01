//graph, DFS
// need to use adjacency list, it use less memory

#include <stdio.h>
#include <stdlib.h>

int** graph;
int** graph_r;
int* cnt;
int* cnt_r;
int* checked;
int* counting;

int DFS(int start);
int DFS_r(int start);

int main(){
    int n,m,i,s,t,j;
    scanf("%d %d",&n,&m);

    graph = (int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++){
        graph[i] = (int*)calloc(n, sizeof(int));
    }
    graph_r = (int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++){
        graph_r[i] = (int*)calloc(625, sizeof(int));
    }

    cnt = (int*)calloc(n,sizeof(int));
    cnt_r = (int*)calloc(n,sizeof(int));
    checked = (int*)calloc(n,sizeof(int));
    counting = (int*)calloc(n,sizeof(int));

    int* size = (int*)malloc(n*sizeof(int));
    int* size_r = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        size[i] = 625;
        size_r[i] = 625;
    }

    int a,b,ans=0;
    for(i =0;i<m;i++){
        scanf("%d %d",&a,&b);
        graph[a-1][cnt[a-1]++] = b;
        graph_r[b-1][cnt_r[b-1]++] = a;
        if(cnt[a-1] == size[a-1]-1){
            size[a-1] *=2;
            graph[a-1] = (int*)realloc(graph[a-1],sizeof(int)*size[a-1]);
        }
        if(cnt_r[b-1] == size_r[b-1]-1){
            size_r[b-1] *=2;
            graph_r[b-1] = (int*)realloc(graph_r[b-1],sizeof(int)*size_r[b-1]);
        }
    }

    scanf("%d %d",&s,&t);   //start, target
    checked[s-1] = 1;
    checked[t-1] = 1;
    DFS(s);

    for(j=0;j<n;j++){
        checked[j] = 0;
    }
    checked[s-1] = 1;
    checked[t-1] = 1;
    DFS(t);

    for(j=0;j<n;j++){
        checked[j] = 0;
    }
    checked[s-1] = 1;
    checked[t-1] = 1;
    
    DFS_r(s);

    for(j=0;j<n;j++){
        checked[j] = 0;
    }
    checked[s-1] = 1;
    checked[t-1] = 1;
    DFS_r(t);

    counting[s-1] = 0;
    counting[t-1] = 0;
    for(i =0;i<n;i++){
        if(counting[i] == 4){
            ans++;
        }
    }
    printf("%d",ans);

}

int DFS(int start){
    checked[start-1] = 1; //reach
    counting[start-1]++;
    int next;
    //다음 node가 target인지 확인 후 DFS 전달
    for(int i =0;i<cnt[start-1];i++){
        next = graph[start-1][i];
        
        if(!checked[next-1]){
            DFS(next);
        }
    }
    return 0;
}

int DFS_r(int start){
    checked[start-1] = 1; //reach
    counting[start-1]++;
    int next;
    //다음 node가 target인지 확인 후 DFS 전달
    for(int i =0;i<cnt_r[start-1];i++){
        next = graph_r[start-1][i];
        
        if(!checked[next-1]){
            DFS_r(next);
        }
    }
    return 0;
}