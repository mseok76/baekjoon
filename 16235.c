//unsol
//Time out, linked list가 아닌 array를 이용해야할듯
//충분히 큰 크기의 array에 나무 추가하고 나무 개수 arr 따로 만들어서 아래와 같은 방식으로 진행. 해결가능할듯 -> 이게 더 쉬움


#include <stdio.h>
#include <stdlib.h>

typedef struct tree_
{
    int age;
    struct tree_* next;
}tree;

tree* map[10][10];

void add_tree(int y,int x, int age){
    tree* temp = (tree*)malloc(sizeof(tree));
    temp->age = age;
    temp->next = map[y][x];
    map[y][x] = temp;
}

int dead_tree(tree* pre_tree){
    int ingre=0;
    tree* temp;
    temp = pre_tree->next;
    pre_tree -> next = NULL;
    while(temp != NULL){
        pre_tree = temp->next;
        ingre += temp->age/2;
        free(temp);
        temp = pre_tree;
    }
    return ingre;
}

int main(){
    int dirx[8] = {1,1,0,-1,-1,-1,0,1};
    int diry[8] = {0,-1,-1,-1,0,1,1,1};
    int ingre[10][10];
    int add[10][10];
    int n,m,k,i,j,h, cnt = 0;
    scanf("%d %d %d",&n,&m,&k);
    for(i =0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&add[i][j]);
            ingre[i][j] = 5;
            map[i][j] = NULL;
        }
    }
    int x,y,z;
    for(i =0;i<m;i++){
        scanf("%d %d %d",&y,&x,&z);   //input으로 들어오는 좌표는 1부터 시작함.
        add_tree(y-1,x-1,z);
    }
    tree* pre_temp;
    tree* temp;
    while(k--){
        //spring, consume ingre
        // printf("spring\n");
        for(i =0;i<n;i++){
            for(j=0;j<n;j++){
                // printf("%d %d\n",i,j);
                int dead_ingre =0;
                temp = map[i][j];
                if(temp == NULL)continue;
                // 첫 원소가 죽을 경우; 
                if(temp->age > ingre[i][j]){
                    dead_ingre = dead_tree(temp);
                    dead_ingre += temp->age/2;
                    map[i][j] = NULL;
                    ingre[i][j] += dead_ingre;
                    continue;
                }

                //첫 원소까지 ok인 경우
                while(temp != NULL){

                    if(ingre[i][j] < temp->age){
                        dead_ingre = dead_tree(pre_temp);
                        break;
                    }
                    ingre[i][j] -= temp->age;
                    temp->age++;
                    pre_temp = temp;
                    temp = temp->next;
                }
                ingre[i][j] += dead_ingre;
            }
        }
        //summer, dead tree became ingre
        // printf("summer\n");
        // int del;
        // tree* temp2;
        // tree* pre_temp;
        // for(i =0;i<n;i++){
        //     for(j=0;j<n;j++){
        //         // printf("%d %d\n",i,j);
        //         del =0;
        //         temp = map[i][j];
        //         if(temp == NULL){
        //             continue;
        //         }
        //         // printf("flag\n");
        //         if(temp->dead == 1){    // 첫 linked list 확인
        //             map[i][j] = NULL;
        //             while(temp != NULL){
        //                     ingre[i][j] += (temp->age)/2;
        //                     pre_temp = temp;
        //                     temp = temp->next;
        //                     free(pre_temp);
        //             }
        //             continue;
        //         }
        //         // printf("flag2\n");
        //         while(temp != NULL){
        //             if(temp -> dead == 1){
        //                 pre_temp ->next = NULL;
        //                 while(temp != NULL){
        //                     ingre[i][j] += (temp->age)/2;
        //                     pre_temp = temp;
        //                     temp = temp->next;
        //                     free(pre_temp);
        //                 }
        //             }else{
        //                 pre_temp = temp;
        //                 temp = temp->next;
        //             }
        //         }
        //     }
        // }
        //autumn, breeding tree
        // printf("autumn\n");
        int dir;
        for(i =0;i<n;i++){
            for(j=0;j<n;j++){
                temp = map[i][j];
                while(temp != NULL){
                    if(temp->age % 5 == 0){
                        for(dir =0;dir<8;dir++){
                            if(i+diry[dir] < 0 || i+diry[dir] >= n || j+dirx[dir] < 0 || j+dirx[dir] >= n ){
                                continue;
                            }
                            add_tree(i+diry[dir], j+dirx[dir], 1);
                        }
                    }
                    temp = temp->next;
                }
            }
        }
        //winter, add ingre 
        // printf("winter\n");
        for(i =0;i<n;i++){
            for(j=0;j<n;j++){
                ingre[i][j] += add[i][j];
            }
        }
    }
    
    for(i =0;i<n;i++){
            for(j=0;j<n;j++){
                temp = map[i][j];
                while(temp != NULL){
                    cnt++;
                    temp = temp->next;
            }
        }
    }
    printf("%d",cnt);


}

