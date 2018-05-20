#include<stdio.h>

int main(){
    int k, n, m, x, y;
    scanf("%d", &k);
    while (k){
        scanf("%d %d", &n, &m);
    while (k--){
        scanf("%d %d", &x, &y);
        if (x > n){
            if (y > m){
                printf("NE\n");
            } else if (y < m){
                printf("SE\n");
            } else {
                printf("divisa\n");
            }
        } else if (x < n){
            if (y > m){
                printf("NO\n");
            } else if (y < m){
                printf("SO\n");
            } else {
                printf("divisa\n");
            }
        } else {
            printf("divisa\n");
        }
    }
        scanf("%d", &k);
    }
    return 0;
}