#include <stdio.h>
#include <stdbool.h>

#define MAX 100001
bool visited[2][MAX];
int arr[MAX], N, cnt;

void dfs(int num, int depth){
    if (!depth){
        for (int i = 1; i <= N; i++)
            if (!visited[0][i])
                dfs(i, depth + 1);
    }
	
    visited[0][num] = true;
    int rink = arr[num];
    if (!visited[0][rink]) dfs(rink, depth);
    else if (!visited[1][rink]){
        int self = rink;
        while (self != num){
            self = arr[self];
            cnt++;
        }
        cnt++;
    }
    visited[1][num] = true;
}
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        memset(visited, 0, sizeof(visited));
        cnt = 0;
		
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &arr[i]);
			
        dfs(1, 0);
        printf("%d\n", N - cnt);
    }
}