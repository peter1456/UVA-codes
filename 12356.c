#include<stdio.h>
#include<memory.h>

int main(){
    int S, B, left[100001], right[100001], i, L, R;
    while(scanf("%d %d", &S, &B), S || B){
        for (i = 1; i <= S; i++){
            left[i] = i - 1;
            right[i] = i + 1; 
        }
        right[S] = 0;
        while(B--){
            scanf("%d %d", &L, &R);
            if(left[L]){
                printf("%d ", left[L]);
            } else {
                printf("* ");
            }
            if(right[R]){
                printf("%d\n", right[R]);
            } else {
                printf("*\n");
            }
            left[right[R]] = left[L];
            right[left[L]] = right[R];
        }
        printf("-\n");
    }
    return 0;
}