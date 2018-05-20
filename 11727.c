#include<stdio.h>

void swap (int* a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int t, arr[3], i, j;
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d %d %d", arr, arr+1, arr+2);
        for (j = 0; j < 2; j++){
            if (arr[0] > arr[1]){
                swap(arr, arr+1);
            }
            if (arr[1] > arr[2]){
                swap(arr+1, arr+2);
            }
        }
        printf("Case %d: %d\n", i, arr[1]);
    }
    return 0;
}