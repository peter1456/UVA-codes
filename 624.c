#include<stdio.h>

int max, configuration, duration[20], N, M;

void backtrack(int config, int sum, int n){
    int i;
    if (sum > max){
        max = sum;
        configuration = config;
    }
    for(i = n; i < M; i++){
        if(sum + duration[i] <= N){
            backtrack(config + (1 << i), sum + duration[i], i + 1);
        }
    }
}

int main(){
    int i;
    while(scanf("%d %d", &N, &M) == 2){
        for(i = 0; i < M; i++){
            scanf("%d", &duration[i]);
        }
        max = 0;
        backtrack(0,0,0);
        for(i = 0; i < M; i++){
            if(configuration & (1 << i)){
                printf("%d ", duration[i]);
            }
        }
        printf("sum:%d\n", max);
    }
    return 0;
}