#include <stdio.h>

int main(){
    char pile[25][3], deck[27][3];
    int count, at, Y, i, N, X;
    scanf("%d", &N);
    for (count = 1; count <= N; count++){
        at = Y = 0;
        for (i = 26; i >= 0; i--){
            scanf("%s", deck[i]);
        }
        for (i = 24; i >= 0; i--){
            scanf("%s", pile[i]);
        }
        for (i = 0; i < 3; i++){
            X = ((deck[at][0] - '2' >= 0) && (deck[at][0] - '2' <= 7)) ? deck[at][0] - '0' : 10;
            Y += X ;
            at = at + 11 - X;
        }
        if (Y > 27 - at){
            printf("Case %d: %s\n", count, pile[25-(Y-27+at)]);
        } else {
            printf("Case %d: %s\n", count, deck[27-Y]);
        }
    }
    return 0;
}