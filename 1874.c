#include <stdio.h>
#include <stdbool.h>

int stack[100000];
int top,i,prev;

void stack_init();

int main(){
    stack_init();
    bool output[200000];
    int n, input, t= 0;
    scanf("%d",&n);

    stack_init();

    for(int j = 0;j<n;j++){ //check NO case
        scanf("%d",&input);
        if(prev < input){      //pushing to reach the target    

            while(i != input){
                stack[++top] = i++;
                if(i > input){
                    printf("NO\n");
                    return 0;
                }
                output[t++] = 1;
            }
            stack[++top] = i++;
            output[t++] = 1;

            top--;
            output[t++] = 0;
        }else{              //poping to reach the target

            while(stack[top--] != input){
                if(stack[top+1] < input){
                    printf("NO\n");
                    return 0;
                }
                output[t++] = 0;
            }
            output[t++] = 0;
        }
        prev = input;
    }
    for(int j = 0;j<t;j++){
        printf("%c\n", output[j]?'+':'-');
    }
}

void stack_init(){
    i=1;
    top=-1;
    prev = 0;
}