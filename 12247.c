#include<stdio.h>

int main(){
    int A, B, C, X, Y, i, tmp, K;
    while(scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y), A + B + C + X + Y){
        for (i = 0; i < 2; i++){
            if (A > B){
                tmp = A;
                A = B;
                B = tmp;
            }
            if (B > C){
                tmp = B;
                B = C;
                C = tmp;
            }
        }
        if (X > Y){
            tmp = X;
            X = Y;
            Y = tmp;
        }
        if (Y < B){
            printf("-1\n");
        } else if (X > C) {
            K = 1;
            while ((K == A) || (K == B) || (K == C) || (K == X) || (K == Y)){
                K++;
            }
            printf("%d\n", K);
        } else if (X > B){
            K = B + 1;
            while ((K == A) || (K == B) || (K == C) || (K == X) || (K == Y)){
                K++;
            } 
            printf("%d\n", K <= 52 ? K : -1);
        } else if (Y < C){
            printf("-1\n");
        } else {
            K = C + 1;
            while ((K == A) || (K == B) || (K == C) || (K == X) || (K == Y)){
                K++;
            } 
            printf("%d\n", K <= 52 ? K : -1);
        }
    }
    return 0;
}