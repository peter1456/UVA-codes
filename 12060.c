#include<stdio.h>

int main(){
    int n, sum, i, tmp, num, denom, in;
    while(scanf("%d", &n), n){
        for(sum = i = 0; i < n; i++){
            scanf("%d", &tmp);
            sum += tmp;
        }
        denom = n;
        num = sum % denom;
        in = sum / denom;
        
    }
    return 0;
}