#include <stdio.h>

int main(){
    int n, cnt;
    char c;
    scanf("%d",&n);
    getchar();
    
    while(n--){
        cnt = 0;
        while(1){
            c = getchar();
            if(c == '\n' || c == '\0') break;
            else if (c == '('){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt < 0) cnt = 100;
        }
        if(cnt == 0) printf("YES\n");
        else printf("NO\n");
    }
}
