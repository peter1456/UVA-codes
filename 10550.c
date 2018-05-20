#include<stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while (a + b + c + d){
        printf("%d\n", 720 + ((a - b + 40) % 40) * 9 + 360 + ((c - b + 40) % 40) * 9 + ((c - d + 40) % 40) * 9);
        scanf("%d %d %d %d", &a, &b, &c, &d);
    }
    return 0;
}