#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[500001] = {0};

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x <= 0) {
            arr[-x+1]++;
        } else {
            arr[0]++;
            arr[x]--;
        }
    }

    int count = 0, sum = 0;
    int possible[500001];
    for (int i = 0; i <= n; i++) {
        sum += arr[i];
        if (sum == i) {
            possible[count++] = i;
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", possible[i]);
    }

    return 0;
}