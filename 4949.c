#include <stdio.h>

int main(){
    char c;
<<<<<<< HEAD
    int small=0, big=0, state = 0;
    while(c = getchar()){
        if(c == EOF) break;
        if(c == '(') small++;
        else if(c == ')') small--;
        else if(c == '[') big++;
        else if(c == ']') big--;
        else if(c == '.'){
            if(small == 0 && big == 0 && state != 1) printf("yes\n");
            else printf("no\n");
            small =0;
            big =0;
            state = 0;
        }
        if(small <0 || big < 0){
            state = 1;
=======
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
>>>>>>> b7dda23ed7e14e507249c2c6a2a13e6091b2e5d6
        }
    }
}