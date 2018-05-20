#include<stdio.h>

int main(){
    int H, U, D, F, day, reached;
    double decre, dist, up;
    scanf("%d %d %d %d", &H, &U, &D, &F);
    while(H != 0){
        reached = day = dist = 0;
        decre = (double)U * (double)F / 100;
        up = U;
        while (!reached && dist >= 0){
            day++;
            dist += up;
            up -= decre;
            if (up < 0){
                up = 0;
            }
            if (dist > H){
                reached = 1;
            } else {
                dist -= D;
            }
        }
        printf("%s on day %d\n", reached ? "success" : "failure", day);
        scanf("%d %d %d %d", &H, &U, &D, &F);
    }
    return 0;
}