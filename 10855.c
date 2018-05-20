#include<stdio.h>
#include<memory.h>

int main(){
    int N, n, i, j, count[4], k, l, same;
    char small[100][100], big[100][100];
    while(scanf("%d %d", &N, &n), N && n){
        for(i = 0; i < N; i++){
            scanf("%s", big[i]);
        }
        for(i = 0; i < n; i++){
            scanf("%s", small[i]);
        }
        memset(count, 0, sizeof(count));
        for(i = 0; i < N - n + 1; i++){
            for(j = 0; j < N - n + 1; j++){
                for (same = 1, k = 0; same && k < n; k++){
                    for (l = 0; same && l < n; l++){
                        if(big[i+k][j+l] != small[k][l])
                            same = 0;
                    }
                }
                if(same){
                    count[0]++;
                }
                for (same = 1, k = 0; same && k < n; k++){
                    for (l = 0; same && l < n; l++){
                        if(big[i+k][j+l] != small[l][n-1-k])
                            same = 0;
                    }
                }
                if(same){
                    count[1]++;
                }
                for (same = 1, k = 0; same && k < n; k++){
                    for (l = 0; same && l < n; l++){
                        if(big[i+k][j+l] != small[n-1-k][n-1-l])
                            same = 0;
                    }
                }
                if(same){
                    count[2]++;
                }
                for (same = 1, k = 0; same && k < n; k++){
                    for (l = 0; same && l < n; l++){
                        if(big[i+k][j+l] != small[n-1-k][l])
                            same = 0;
                    }
                }
                if(same){
                    count[3]++;
                }
            }
        }
        printf("%d %d %d %d\n", count[0], count[1], count[2], count[3]);
    }
}