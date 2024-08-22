#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
char name[100000][101];
int age[100000];
int indexing[100000];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %s",&age[i], name[i]);
        indexing[i] = i;
    }
    qsort(indexing,n,sizeof(int),compare);

    for(int i =0;i<n;i++){
        printf("%d %s\n",age[indexing[i]], name[indexing[i]]);
    }
}

int compare(const void* a, const void* b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(age[A]>age[B]) return 1;
    else return -1;
}