#include <stdio.h>
#include <string.h>

int main(){
    int queue[10000];
    int head = -1;
    int tail = -1;
    char command[10];
    int n,temp;
    scanf("%d",&n);
    while(n--){
        scanf("%s",command);
        // printf("---\n");     debugging
        if(!strcmp(command, "push")){
            scanf("%d",&temp);
            queue[++tail] = temp;

        }else if(!strcmp(command, "pop")){
            if(tail <= head) printf("-1\n");
            else printf("%d\n",queue[++head]);

        }else if(!strcmp(command, "size")){
            printf("%d\n",tail-head);

        }else if(!strcmp(command, "empty")){
            printf("%d\n",tail==head?1:0);

        }else if(!strcmp(command, "front")){
            if(tail == head) printf("-1\n");
            else printf("%d\n",queue[head+1]);

        }else if(!strcmp(command, "back")){
            if(tail == head) printf("-1\n");
            else printf("%d\n",queue[tail]);

        }else{
            printf("ERR\n");
        }
    }
    
    
}