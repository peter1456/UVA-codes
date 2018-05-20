#include<stdio.h>
#include<memory.h>

int main(){
    int corner[17000], power[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768}, N, i, max, j, potent[17000];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < power[N]; i++){
            scanf("%d", &corner[i]);
        }
        memset(potent, 0, sizeof(potent));
        for(i = 0; i < power[N]; i++){
            for(j = 0; j < N; j++){
                potent[i] += corner[i ^ (1 << j)];
            }
        }
        for(max = 0, i = 0; i < power[N] - 1; i++){
            for(j = 0; j < N; j++){
                max = potent[i] + potent[i ^ (1 << j)] > max ? potent[i] + potent[i ^ (1 << j)] : max;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}