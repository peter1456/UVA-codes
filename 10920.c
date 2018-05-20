#include<stdio.h>
#include<inttypes.h>

int main(){
    long SZ, xcoor, ycoor, t, dir, j;
    long long P, i;
    int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
    while(scanf("%li %lli", &SZ, &P), SZ || P){
        xcoor = ycoor = SZ / 2 + 1;
        dir = 0;
        for(i = t = 1; i < P; t++){
            for(j = 0; j < 2 && i < P; j++){
                xcoor += t * dx[dir];
                ycoor += t * dy[dir];
                i += t;
                dir = (dir + 1) % 4;
            }
        }
        xcoor -= (i - P) * dx[(dir + 3) % 4];
        ycoor -= (i - P) * dy[(dir + 3) % 4];
        printf("Line = %li, column = %li.\n", ycoor, xcoor);
    }
    return 0;
}