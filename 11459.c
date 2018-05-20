#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int main(){
    int board[101], *players, cases, a, b, c, i, ended, s, e, roll, count, p;
    scanf("%d", &cases);
    players = (int *)malloc(1000010 * sizeof(int));
    while(cases--){
        memset(board, 0, sizeof(board));
        count = ended = 0;
        scanf("%d %d %d", &a, &b, &c);
        for (i = 1; i <= a; i++){
            players[i] = 1;
        }
        while(b--){
            scanf("%d %d", &s, &e);
            board[s] = e;
        }
        while(c--){
            scanf("%d", &roll);
            if (!ended){
                p = ++count % a;
                if (!p){
                    p = a;
                }
                players[p] += roll;
                if (board[players[p]]){
                    players[p] = board[players[p]];
                }
                if (players[p] >= 100){
                    ended = 1;
                    players[p] = 100;
                }
            }
        }
        for (i = 1; i <= a; i++){
            printf("Position of player %d is %d.\n", i, players[i]);
        }
    }
    return 0;
}