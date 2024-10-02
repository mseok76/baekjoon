//graph, DFS

#include <stdio.h>
#include <stdlib.h>

int** graph;
int* cnt;
int* checked;
int* checked_t;

int DFS_s(int start);
int DFS_t(int target);

int main(){
    int n,m,i,s,t;
    scanf("%d %d",&n,&m);

    graph = (int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++){
        graph[i] = (int*)calloc(n, sizeof(int));
    }
    cnt = (int*)calloc(n,sizeof(int));
    checked = (int*)calloc(n,sizeof(int));
    checked_t = (int*)calloc(n,sizeof(int));

    int a,b,ans=0;
    for(i =0;i<m;i++){
        scanf("%d %d",&a,&b);
        graph[a-1][cnt[a-1]++] = b;
    }

    scanf("%d %d",&s,&t);   //start, target
    checked[t-1] = 3;
    checked_t[s-1] = 3;
    DFS_s(s);
    DFS_t(t);
    for(i=0;i<n;i++){
        if(checked[i] == 2 && checked_t[i]==2){
            ans++;
        }
    }
    printf("%d\n",ans);
    for(i =0;i<n;i++){
        printf("%d ",checked[i]);
    }
    printf("\n");
    for(i =0;i<n;i++){
        printf("%d ",checked_t[i]);
    }
}

int DFS_s(int start){
    printf("DFS_s:%d\n",start);
    checked[start-1] = 1; //not reach
    int next,temp;
    //다음 node가 target인지 확인 후 DFS 전달
    for(int i =0;i<cnt[start-1];i++){
        next = graph[start-1][i];
        
        if(!checked[next-1]){
            if(DFS_s(next) == 2){checked[start-1] = 2;}
        }else if(checked[next-1] >= 2){
            checked[start-1] = 2;
        }
    }
    return checked[start-1];
}

int DFS_t(int target){
    checked_t[target-1] = 1; //not reach
    int next,temp;
    //다음 node가 target인지 확인 후 DFS 전달
    for(int i =0;i<cnt[target-1];i++){
        next = graph[target-1][i];
        
        if(!checked_t[next-1]){
            if(DFS_t(next) == 2){checked_t[target-1] = 2;}
        }else if(checked_t[next-1] >= 2){
            checked_t[target-1] = 2;
        }else{
            
            
        }
    }
    return checked_t[target-1];
}