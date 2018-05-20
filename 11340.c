#include<stdio.h>
#include<string.h>

int main(){
    int N, K, M, table[130], fee, i;
    long sum;
    char line[10010];
    char c;
    scanf("%d", &N);
    while(N--){
        memset(table, 0, sizeof(table));
        sum = 0;
        scanf("%d", &K);
        while(K--){
            scanf(" %c %d", &c, &fee);
            table[c] = fee;
        }
        scanf("%d", &M);
        getchar();
        while(M--){
            fgets(line, 10009, stdin);
            for (i = 0; i < strlen(line); i++){
                if(line[i] > 0 && line[i] < 128)
                sum += table[line[i]];
            }
        }
        printf("%li.%02li$\n", sum / 100 ? sum / 100 : 0, sum % 100);
    }
    return 0;
}