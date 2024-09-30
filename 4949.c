#include <stdio.h>

int main(){
    char c;
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
        }
    }
}