#include <stdio.h>

int main(){
    int w, quo, remain, three;
    scanf("%d",&w);
    quo = w / 5;
    remain = w % 5;
    switch (remain)
    {
    case 0:
        three = 0;
        break;
    case 1:
        quo -= 1;
        three = 2;
        if(quo < 0){
            printf("-1\n");
            return 0;
        }
        break;
    case 2:
        quo -= 2;
        three = 4;
        if(quo < 0){
            printf("-1\n");
            return 0;
        }
        break;
    case 3:
        three = 1;
        break;
    case 4:
        quo -= 1;
        three = 3;
        if(quo < 0){
            printf("-1\n");
            return 0;
        }
        break;
    
    default:
        break;
    }
    printf("%d\n",quo+three);
    return 0;
}