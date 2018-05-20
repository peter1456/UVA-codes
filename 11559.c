#include<stdio.h>

int main(){
    int N, B, H, W, min, i, j, p, a;
    while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        min = 10001;
        for (i = 0; i < H; i++){
            scanf("%d", &p);
            for (j = 0; j < W; j++){
                scanf("%d", &a);
                if (a >= N && p < min){
                    min = p;
                }
            }
        }
        if ((min = min * N) > B){
            printf("stay home\n");
        } else {
            printf("%d\n", min);
        }
    }
    return 0;
}