#include<stdio.h>
#include<memory.h>

int main(){
    int i, N, prev, tmp, flag[3010], sum;
    while(scanf("%d", &N) != EOF){
        if (N == 1){
            scanf("%d", &tmp);
            printf("Jolly\n");
        } else {
            memset(flag, 0, sizeof(flag));
            scanf("%d", &prev);
            for (i = 1; i < N; i++){
                scanf("%d", &tmp);
                if (tmp > prev){
                    flag[tmp - prev] = 1;
                } else {
                    flag[prev - tmp] = 1;
                }
                prev = tmp;
            }
            for (sum = 0, i = 1; i < N; i++){
                sum += flag[i];
            }
            printf("%s\n", sum == N - 1 ? "Jolly" : "Not jolly");
        }
    }
    return 0;
}