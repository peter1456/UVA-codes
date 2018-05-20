#include<stdio.h>

int main(){
    int a, b, n;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        if (a < 0 || b < 0 || b > a || (b - a) % 2){
            printf("impossible\n");
        } else {
            printf("%d %d\n", b + (a - b) / 2, (a - b) / 2);
        }
    }
    return 0;
}