#include<stdio.h>

int main(){
    int n, a, b, i;
    while(scanf("%d", &n), n){
        i = 1;
        a = b = 0;
        while(n){
            if(i){
                a += n & (-n);
                i = 0;
            } else {
                b += n & (-n);
                i = 1;
            }
            n -= n & (-n);
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}