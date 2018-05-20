#include <stdio.h>
#include <memory.h>

int main(){
    int n, i, j, tmp, bingo, sum, bingoat;
    scanf("%d", &n);
    int BINGO[76][2], board[6][6];
    while (n--){
        bingo = 0;
        memset (BINGO, 0, sizeof(BINGO));
        memset (board, 0, sizeof(board));
        board[3][3] = 1;
        for (i = 1; i <= 5; i++){
            for (j = 1; j <= 5; j++){
                scanf("%d", &tmp);
                BINGO[tmp][0] = i;
                j = (j == 3 && i == 3) ? 4 : j;
                BINGO[tmp][1] = j;
            }
        }
        for (i = 1; i <= 75; i++){
            scanf("%d", &tmp);
            if (!bingo && BINGO[tmp][0]){
                board[BINGO[tmp][0]][BINGO[tmp][1]] = 1;
                for (sum = 0, j = 1; j <= 5; j++){
                   sum += board[BINGO[tmp][0]][j];
                }
                if (sum == 5){
                    bingo = 1;
                    bingoat = i;
                }
                for (sum = 0, j = 1; j <= 5; j++){
                    sum += board[j][BINGO[tmp][1]];
                }
                if (sum == 5){
                    bingo = 1;
                    bingoat = i;
                }
                if (BINGO[tmp][0] == BINGO[tmp][1]){
                    for (sum = 0, j = 1; j <= 5; j++){
                        sum += board[j][j];
                    }
                    if (sum == 5){
                        bingo = 1;
                        bingoat = i;
                    }
                }
                if (BINGO[tmp][0] == 6 - BINGO[tmp][1]){
                    for (sum = 0, j = 1; j <= 5; j++){
                        sum += board[j][6 - j];
                    }
                    if (sum == 5){
                        bingo = 1;
                        bingoat = i;
                    }
                }
            }
        }
        printf("BINGO after %d numbers announced\n", bingoat);
    } 
    return 0;
}