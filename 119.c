#include<stdio.h>
#include<string.h>

typedef struct p {
    char name[15];
    int gain;
} gift;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    gift arr[10];
    char find[15];
    int N, i, j, k;
    int amount;
    scanf("%d", &N);
    memset(arr, 0, sizeof(arr));
        for (i = 0; i < N; i++){
            scanf("%s", arr[i].name);
        }
        for (i = 0; i < N; i++){
            scanf("%s", find);
            for (j = 0; strcmp(find, arr[j].name); j++){
                ;
            }
            scanf("%d %d", &amount, &k);
            if (k){
                amount /= k;
                arr[j].gain -= amount * k;
            }
            while (k--){
                scanf("%s", find);
                for (j = 0; strcmp(find, arr[j].name); j++){
                    ;
                }
                arr[j].gain += amount;
            }
        }
        for (i = 0; i < N; i++){
            printf("%s %d\n", arr[i].name, arr[i].gain);
        }
    while (scanf("%d", &N) != EOF){
        putchar('\n');
        memset(arr, 0, sizeof(arr));
        for (i = 0; i < N; i++){
            scanf("%s", arr[i].name);
        }
        for (i = 0; i < N; i++){
            scanf("%s", find);
            for (j = 0; strcmp(find, arr[j].name); j++){
                ;
            }
            scanf("%d %d", &amount, &k);
            if (k){
                amount /= k;
                arr[j].gain -= amount * k;
            }
            while (k--){
                scanf("%s", find);
                for (j = 0; strcmp(find, arr[j].name); j++){
                    ;
                }
                arr[j].gain += amount;
            }
        }
        for (i = 0; i < N; i++){
            printf("%s %d\n", arr[i].name, arr[i].gain);
        }
    }
    return 0;
}