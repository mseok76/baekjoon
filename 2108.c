#include <stdio.h>

int main(){
    int n, max, min, temp, mcnt, num, j;
    double sum;
    int arr[8001] = {0};  //-4000 ~ 4000

    j = 0;
    mcnt = 0;
    sum = 0;
    max = -4001;
    min = 4001;

    scanf("%d",&n);
    num = n/2 + 1;
    for(int i =0; i<n;i++){
        scanf("%d",&temp);
        if(temp > max) max = temp;
        if(temp < min) min = temp;
        sum += temp;
        arr[temp+4000]++;
        if(arr[temp+4000] > mcnt) mcnt = arr[temp+4000];
    }
    if(sum/n < 0 && sum/n > -1) printf("0\n");
    else printf("%.0f\n",sum/n);

    while(num > 0){
        num -= arr[j++];
    }
    printf("%d\n",j-4001);
    
    int most, flag = 0;;
    for(int i=0;(i<8001) && (flag != 2) ;i++){
        if(arr[i] == mcnt){
            most = i - 4000;
            flag++;
            }
    }
    printf("%d\n",most);
    printf("%d\n",max-min);
}