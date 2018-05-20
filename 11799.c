#include<stdio.h>

int main(){
    int T, N, max, i, x, j;
    scanf("%d", &T);
    for (j = 1; j <= T; j++) {
        max = -1;
        scanf("%d", &N);
        for (i = 0; i < N; i++){
            scanf("%d", &x);
            max = x > max ? x : max;
        }
        printf ("Case %d: %d\n", j, max);
    }
    return 0;
}