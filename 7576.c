#include<stdio.h>
#include<stdlib.h>

int stack[2000000];
int top = 0, end = 0, w, h;
int** arr;

void BFS();

int main() {
	int day = 0;
	
	scanf("%d %d", &w, &h);
	arr = (int**)malloc(sizeof(int) * w * h);
	for (int i = 0;i < h;i++) {
		arr[i] = (int*)malloc(sizeof(int) * w);
	}

	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				stack[top++] = i;
				stack[top++] = j;
			}
		}
	}
	//BFS
	int temp;
	while (top != end) {
		//printf("day : %d , top : %d, end : %d\n", day, top, end);
		temp = top - end;
		for (int i = 0;i < temp ;i+=2) {
			BFS();
		}
		day++;
	}
	
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			//printf("%d ", arr[i][j]);
			if (arr[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
		//printf("\n");
	}
	printf("%d\n", day - 1);



	for (int i = 0;i < h;i++) {
		free(arr[i]);
	}
	free(arr);
}

void BFS() {
	int a, b;
	a = stack[end++];
	b = stack[end++];
	if (a != 0) {
		if (arr[a - 1][b] == 0) {
			stack[top++] = a - 1;
			stack[top++] = b;
			arr[a - 1][b] = 1;
		}
	}
	if (a != h - 1) {
		if (arr[a + 1][b] == 0) {
			stack[top++] = a + 1;
			stack[top++] = b;
			arr[a + 1][b] = 1;
		}
	}
	if (b != 0) {
		if (arr[a][b - 1] == 0) {
			stack[top++] = a;
			stack[top++] = b - 1;
			arr[a][b - 1] = 1;
		}
	}
	if (b != w - 1) {
		if (arr[a][b + 1] == 0) {
			stack[top++] = a;
			stack[top++] = b + 1;
			arr[a][b + 1] = 1;
		}
	}
}