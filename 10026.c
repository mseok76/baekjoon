#include <stdio.h>
#include <stdlib.h>

void sector2(int x,int y,char color);
void sector(int x,int y, char color);

char** canvas;
char** canvas2;
int BLK;


int main(){
    int cnt=0,cnt1=0;
    scanf("%d",&BLK);
    canvas = (char**)malloc(BLK*sizeof(char *));
    for(int i=0;i<BLK;i++){
        canvas[i] = (char*)malloc(BLK*sizeof(char));
    }

    canvas2 = (char**)malloc(BLK*sizeof(char*));
    for(int i=0;i<BLK;i++){
        canvas2[i] = (char*)malloc(BLK*sizeof(char));
    }

    //scan
    getchar();
    for(int i=0;i<BLK;i++){
        for(int j=0;j<BLK;j++){
            canvas[i][j] = getchar();
            if(canvas[i][j] == 'G'){
                canvas2[i][j] = 'R';
            }else{
                canvas2[i][j] = canvas[i][j];
            }
        }
        getchar();
    }

    // for(int i=0;i<BLK;i++){
    //     for(int j=0;j<BLK;j++){
    //         printf("%c",canvas[i][j]);
    //     }
    //     printf("\n");
    // }

    //모든 canvas 탐색하며 모든 sector 구분
    for(int i=0;i<BLK;i++){
        for(int j=0;j<BLK;j++){
            if(canvas[i][j] != 'a'){
                sector(j,i,canvas[i][j]);    //재귀 진입
                cnt++;
            }
            if(canvas2[i][j] != 'a'){
                sector2(j,i,canvas2[i][j]);
                cnt1++;
            }
        }
    }

    printf("%d %d\n",cnt,cnt1);
    
    for(int i=0;i<BLK;i++){
        free(canvas[i]);
        free(canvas2[i]);
    }
    free(canvas);
    free(canvas2);

}

void sector(int x,int y,char color){
    if( x<0 || x==BLK || y<0 || y ==BLK ) return;
    if(canvas[y][x] != color) return;
    canvas[y][x] = 'a';
    sector(x-1,y,color);
    sector(x+1,y,color);
    sector(x,y-1,color);
    sector(x,y+1,color);
}

void sector2(int x,int y,char color){
    if( x<0 || x==BLK || y<0 || y ==BLK ) return;
    if(canvas2[y][x] != color) return;
    canvas2[y][x] = 'a';
    sector2(x-1,y,color);
    sector2(x+1,y,color);
    sector2(x,y-1,color);
    sector2(x,y+1,color);
}