#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _axis {
	int x;
	int y;
}axis;

int min,c_cnt,h_cnt;
int map[50][50];
axis chicken[13];
axis home[100];
int* choosen;

int distance(int m) {
	//map & choosen
	int max, temp, sum = 0;
	for (int i = 0; i < h_cnt; i++) {	//home
		max = 100;
		for (int j = 0; j < m; j++) {	//chicken shop
			temp = abs(home[i].x - chicken[choosen[j]].x);
			temp += abs(home[i].y - chicken[choosen[j]].y);
			if (max > temp) {
				max = temp;
			}
		}
		//printf("sum: %d\n", max);
		sum += max;
	}
	return sum;
}

void choose(int prev, int m, int depth) {
	int length;
	//printf("depth %d\n", depth);
	if (depth == m) {
		length = distance(m);
		if (length < min) min = length;
		//printf("lenght calucute %d\n",length);
		return;
	}
	if ((c_cnt - prev) < (m - depth)){		//남은 치킨집 수 < 고를 치킨집 수
		return;
	}
	for (int i = prev; i < c_cnt;i++) {
		choosen[depth] = i;
		choose(i + 1, m, depth + 1);
	}
}

int main() {
	int n, m;
	c_cnt = 0, h_cnt = 0, min = 10000;
	scanf("%d %d", &n, &m);
	choosen = (int*)malloc(m*sizeof(int));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chicken[c_cnt].x = j;
				chicken[c_cnt].y = i;
				c_cnt++;
			}
			else if (map[i][j] == 1) {
				home[h_cnt].x = j;
				home[h_cnt].y = i;
				h_cnt++;
			}
		}
	}
	//printf("chicken, home :%d %d\n", c_cnt, h_cnt);
	choose(0, m, 0);
	printf("%d", min);
	free(choosen);
}