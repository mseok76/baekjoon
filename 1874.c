#include <stdio.h>

int stack[100000];
int top,i,prev;

void stack_init();

int main(){
    stack_init();
    int arr[100000];
    int n, max=0,min = 1000000;
    scanf("%d",&n);

    for(int j = 0;j<n;j++){ //check NO case
        scanf("%d",&arr[j]);
        if(prev < arr[j]){
            if(arr[j] < max){
                printf("NO\n");
                return 0;
            }else max = arr[j];
        }else{
            if(arr[j] > min){
                printf("NO\n");
                return 0;
            }else min = arr[j];
            
        }
        prev = arr[j];
    }

    stack_init();

    for(int j = 0;j<n;j++){ //check NO case
        if(prev < arr[j]){

            while(i != arr[j]){
                stack[++top] = i++;
                printf("+\n");
            }
            stack[++top] = i++;
            printf("+\n");

            top--;
            printf("-\n");
        }else{

            while(stack[top--] != arr[j]){
                printf("-\n");
            }
            printf("-\n");
        }
        prev = arr[j];
    }
}

void stack_init(){
    i=1;
    top=-1;
    prev = 0;
}