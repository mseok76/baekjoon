#include <stdio.h>
#include <stdlib.h>

typedef struct tree_
{
    int age;
    int dead;
    struct tree_* next;
}tree;

tree* map[10][10];

void add_tree(int y,int x, int age){
    tree temp;
    temp.age = age;
    temp.dead = 0;
    temp.next = map[y][x];
    map[y][x] = &temp;
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
    tree* temp;
    int dead_tree;
    while(k--){
        //spring, consume ingre
        for(i =0;i<n;i++){
            for(j=0;j<n;j++){
                dead_tree = 0;
                temp = map[i][j];
                while(temp != NULL){
                    if(dead_tree){
                        temp -> dead = 1;
                        temp = temp->next;
                        continue;
                    }
                    if(ingre[i][j] < temp->age){
                        temp -> dead = 1;
                        dead_tree = 1;
                        temp = temp->next;
                        continue;
                    }
                    ingre[i][j] -= temp->age;
                    temp = temp->next;
                }

            }
        }
        //summer, dead tree became ingre
        int dead_ingre, del;
        tree* temp2;
        for(i =0;i<n;i++){
            for(j=0;j<n;j++){
                del = 0;
                temp = map[i][j];
                while(temp != NULL){
                    if(del){
                        ingre[i][j] += (temp->age)/2;
                    }else if(temp -> next == NULL){
                        break;
                    }else if(temp->next->dead){
                        temp2 = temp;
                        del = 1;
                    }
                    temp = temp->next;
                }
                temp2->next = NULL;
            }
        }
        //autumn, breeding tree
        int dir;
        for(i =0;i<n;i++){
            for(j=0;j<n;j++){
                temp = map[i][j];
                while(temp != NULL){
                    if(temp->age % 5 == 0){
                        for(dir =0;dir<8;dir++){
                            if(i+diry[dir] < 0 || i+diry[dir] >= n || j+dirx[dir] < 0 || j+diry[dir] >= n ){
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

