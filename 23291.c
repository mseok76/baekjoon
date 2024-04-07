#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int* map;

void flip(){
    int first_floor, second_floor, height;
    while(1){
        for(int i =0;i<n;i++){
            if(map[i]!= 0){
                first_floor = i;
                break;
            }
        }
        if(first_floor == 0){
            // printf("first\n");
            map[n+1] = map[0];
            map[0] = 0;
            continue;
        }

        for(int i = first_floor;i<n;i++){
            if (map[n+i]==0 ){
                second_floor = i;
                break;
            }
            else if(i == n-1){
                second_floor = n;
                break;
            }
        }
        for(int i =0;i<n/2;i++){
            if (map[i*n+first_floor] == 0){
                height = i;
                break;
            }else if(i == n/2-1){
                height = n/2;
            }
            
        }
        if(n-second_floor < height){
            break;
        }
    
        //or start flip
        for(int i =0;i<height;i++){
            for(int j = 0;j<second_floor-first_floor;j++){
                map[n*(second_floor-first_floor - j)+second_floor+i] = map[i*n+first_floor+j];
                map[i*n+first_floor+j] = 0;
            }
        }
    }   
}

void diff(){
    int* plus = (int*)calloc(n*n/2,sizeof(int));
    int temp;
    for(int i = 0;i<n/2+1;i++){
        for(int j =0;j<n;j++){
            if(map[i*n+j] == 0){
                continue;
            }
            if(map[(i+1)*n+j] != 0){
                temp = map[i*n+j]-map[(i+1)*n+j];
                temp = temp/5;
                if(temp != 0){
                    plus[i*n+j] -= temp;
                    plus[(i+1)*n+j] += temp;
                }
            }
            if(j == n-1) continue; //boundary
            if(map[i*n+j+1] != 0){
                temp = map[i*n+j] - map[i*n+j+1];
                temp = temp/5;
                if(temp != 0){
                    plus[i*n+j] -= temp;
                    plus[i*n+j+1] += temp;
                }
            }
        }
    }
    for(int i =0;i<n*n/2;i++){
        map[i] += plus[i];
    }
    free(plus);
}

void flat(){
    int* new_map = (int*)calloc(n*n/2,sizeof(int));
    int* temp;
    int count=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n/2;j++){
            if(map[i+j*n] == 0){
                i++;
                j = 0;
            }
            new_map[count++] = map[i+j*n];
            if(count == n-1) break;
        }
    }
    temp = map;
    map = new_map;
    free(temp);

}

void half(){
    int layer = n/4;
    for(int i =0;i<n/4;i++){
        map[n*2-1-i] = map[i];
        map[n*2+i] = map[i+n/4];
        map[n*4-1-i] = map[i+n/2]; 
    }
}

void printing(){
    for(int i =0;i<n/2;i++){
        for(int j =0;j<n;j++){
            printf("%4d",map[n*(n/2-1-i)+j]);
        }
        printf("\n");
    }
}


int main(){
    int k,max,min,depth =0;
    scanf("%d %d",&n, &k);
    map = (int*)calloc(n*n/2,sizeof(int));
    for(int i =0;i<n;i++){
        scanf("%d",&map[i]);
    }
    while(1){
        min = map[0];
        max = map[0];
        for(int i=1;i<n;i++){   //find min max
             if(map[i] != 0){
                if(max < map[i]){
                    max = map[i];
                }
                else if(min > map[i]){
                    min = map[i];
                }
            }
        }

        if((max - min) <= k ){
            break;
        }
        depth++;
        printf("start\n");
        printing();
        flip();
        printf("af flip\n");
        printing();
        diff();
        printf("af diff\n");
        printing();
        flat();
        printf("af flat\n");
        printing();
        half();
        printf("af half\n");
        printing();
        flat();
        printf("af flat\n");
        printing();
    }
    free(map);
    printf("%d",depth);
}