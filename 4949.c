#include <stdio.h>

int main(){
    char c;
    int state = -1,cnt=100;
    int stack[200];
    while(c = getchar()){
        if(c == '\n'){
            continue;
        }
        // printf("~%d\n",state);
        if(state == -1){
            if(c == '.'){
                break;
            }
            state = 0;
        }
        if(c == EOF) break;
        if(state == 0){
            if(c == '('){
                stack[cnt++] = 1;
            }
            else if(c == ')'){
                if(stack[--cnt] != 1){
                    state= 1;
                    }
                }
            else if(c == '['){
                stack[cnt++] = -1;
                }
            else if(c == ']'){
                if(stack[--cnt] != -1){
                    state= 1;
                    }
                }
        }
        if(c == '.'){
            if(state == 0 && cnt == 100) printf("yes\n");
            else printf("no\n");
            state = -1;
            cnt = 100;
        }
    }
}