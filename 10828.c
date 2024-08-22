#include <stdio.h>
#include <string.h>

char com1[] = "push";
char com2[] = "pop";
char com3[] = "size";
char com4[] = "top";
char com5[] = "empty";

int stack[100000];
int push(int x);
int pop();
int top = -1;

int main(){
    int n,temp;
    char command[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",command);
        if(!strcmp(command, com1)){
            scanf("%d",&temp);
            push(temp);
        }else if(!strcmp(command,com2)) printf("%d\n",pop());
        else if(!strcmp(command,com3)) printf("%d\n",top+1);
        else if (!strcmp(command,com4)){
            if(top == -1) printf("-1\n");
            else printf("%d\n",stack[top]);
        }
        else if (!strcmp(command,com5)){
            if(top == -1) printf("1\n");
            else printf("0\n");
        }
    }
}

int push(int x){
    stack[++top] = x;
    return x;
}

int pop(){
    if(top == -1){
        return -1;
    }
    return stack[top--];
}