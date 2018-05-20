#include<stdio.h>
#include<memory.h>

int main(){
    int n, i, j, pagec, count;
    int page[25][2][2];
    while(scanf("%d", &n), n){
        memset(page, 0, sizeof(page));
        pagec = n / 4 + 1;
        for (i = 0, count = 1; i < pagec || count <= n; i++){
            for (j = 0; j < 2; j++){
                page[i][j][1] = count++;
            }
        }
        for (i = pagec - 1; pagec >= 0 || count <= n; i--){
            for (j = 0; j < 2; j++){
                page[i][j][0] = count++;
            }
        }
        printf("Printing order for %d pages\n", pagec);
        for (i = 0; i < pagec; i++){
            if(page[i][0][1] || page[i][0][0]){
                printf("Sheet %d, front:", i + 1);
                if(page[i][0][0]){
                    printf(" %d, ", page[i][0][0]);
                } else {
                    printf(" Blank, ");
                }
                if(page[i][0][1]){
                    printf("%d\n", )
                }
            }
        }
    }
    return 0;
}