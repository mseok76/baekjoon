//[PCCP 기출문제] 3번 / 충돌위험 찾기

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct car_{
    int cnt_route;
    int x;
    int y;
}car;

// points_rows는 2차원 배열 points의 행 길이, points_cols는 2차원 배열 points의 열 길이입니다.
// routes_rows는 2차원 배열 routes의 행 길이, routes_cols는 2차원 배열 routes의 열 길이입니다.
int solution(int** points, size_t points_rows, size_t points_cols, int** routes, size_t routes_rows, size_t routes_cols) {
    //points_cols 가 point 개수
    //routes_cols 가 경로 개수
    //routes_rows가 차 개수
    int i,j,x,y,ans=0, end_car = 0;
    int map[100][100] = {0};
    //차 위치 초기화
    car cars[100];
    for(i=0;i<routes_rows;i++){
        cars[i].cnt_route = 0;
        x = points[routes[i][0]][1] -1;
        y = points[routes[i][0]][0] -1;
        cars[i].y = points[routes[i][0]][0] -1; //r,c는 1부터 시작이기 때문에 -1
        cars[i].x = points[routes[i][0]][1] -1;
        // map[y][x]++;
    }
    for(i =0;i<100;i++){
            for(j=0;j<100;j++){
                if(map[i][j] > 1)ans++;
                map[i][j]=0;
            }
        }
    //이동 및 충돌확인
    while(end_car == routes_rows){  //모든 차 이동 종료시 끝
        for(int i=0;i<routes_rows;i++){ //모든 차 반복
            if(cars[i].cnt_route == routes_cols)continue;
            //차 이동 y먼저
            y = points[routes[i][cars[i].cnt_route]][0] - 1;
            x = points[routes[i][cars[i].cnt_route]][1] - 1;
            if(y > cars[i].y){
                cars[i].y++;
            }else if(y < cars[i].y){
                cars[i].y--;
            }else{
                if(x > cars[i].x){
                    cars[i].x++;
                }else if(x < cars[i].x){
                    cars[i].x--;
                }else{
                    //ERR
                    printf("ERR\n");
                }
            }
            //위치에 점수 추가 
            map[cars[i].y][cars[i].x]++;
            //route 도착한 경우 cnt++
            if(x == cars[i].x && y == cars[i].y){
                cars[i].cnt_route++;
                if(cars[i].cnt_route == routes_cols){
                    end_car++;
                }
            }
        }
        //맵에 확인 및 초기화
        for(i =0;i<100;i++){
            for(j=0;j<100;j++){
                if(map[i][j] > 1)ans++;
                map[i][j]=0;
            }
        }
    }
    return ans;
}