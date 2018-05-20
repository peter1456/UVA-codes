#include<stdio.h>

int board[9][9];

int isLegal(int c, int a, int b){
    int i, j, end, bmask = 0, count;
    if (board[a][b]){
        return 0;
    }
    for (end = count = 0, i = a - 1, j = b; i >= 1 && !end; i--, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 0;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    for (end = count = 0, i = a + 1, j = b; i <= 8 && !end; i++, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 1;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    for (end = count = 0, i = a , j = b + 1; j <= 8 && !end; j++, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 2;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    for (end = count = 0, i = a , j = b - 1; j >= 1 && !end; j--, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 3;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    for (end = count = 0, i = a + 1, j = b + 1; !end && i <= 8 && j <= 8 ; i++, j++, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 4;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    for (end = count = 0, i = a + 1, j = b - 1; !end && i <= 8 && j >= 1 ; i++, j--, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 5;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    for (end = count = 0, i = a - 1, j = b - 1; !end && i >= 1 && j >= 1 ; i--, j--, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 6;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    for (end = count = 0, i = a - 1, j = b + 1; !end && i >= 1 && j <= 8 ; i--, j++, count++){
        if (!board[i][j]){
            end = 1;
        } else if (board[i][j] == c){
            if (count) {
                bmask += 1 << 7;
                end = 1;
            } else {
                end = 1;
            }
        }
    }
    return bmask;
}

int main(){
    int N, i, j, current, count, move, a, b, bcount, wcount, k;
    char c;
    scanf("%d", &N);
    getchar();
    for (k = 0; k < N; k++){
        if (k)
            putchar('\n');
        for (i = 1; i <= 8; i++){
            for (j = 1; j <= 8; j++){
                board[i][j] = (c = getchar()) == '-' ? 0 : (c == 'B' ? 1 : 2);
            }
            getchar();
        }
        current = getchar() == 'B' ? 1 : 2;
        getchar();
        while((c = getchar()) != 'Q'){
            if (c == 'L'){
                for (count = 0, i = 1; i <= 8; i++){
                    for (j = 1; j <= 8; j++){
                        if (isLegal(current, i, j)){
                            if (!count)
                                printf("(%d,%d)", i, j);
                            else 
                                printf(" (%d,%d)", i, j);
                            count++;
                        }
                    }
                }
                if (!count)
                    printf("No legal move.\n");
                else 
                    putchar('\n');
                getchar();
            } else {
                bcount = wcount = 0;
                i = getchar() - '0';
                j = getchar() - '0';
                if (!(move = isLegal(current, i, j))){
                    current = (current == 1) ? 2 : 1;
                    move = isLegal(current, i, j);
                }
                board[i][j] = current;
                if (move & 1 << 0){
                    for (a = i - 1, b = j; board[a][b] != current; a--){
                        board[a][b] = current;
                    }
                }
                if (move & 1 << 1){
                    for (a = i + 1, b = j; board[a][b] != current; a++){
                        board[a][b] = current;
                    }
                }
                if (move & 1 << 2){
                    for (a = i, b = j + 1; board[a][b] != current; b++){
                        board[a][b] = current;
                    }
                }
                if (move & 1 << 3){
                    for (a = i, b = j - 1; board[a][b] != current; b--){
                        board[a][b] = current;
                    }
                }
                if (move & 1 << 4){
                    for (a = i + 1, b = j + 1; board[a][b] != current; a++, b++){
                        board[a][b] = current;
                    }
                }
                if (move & 1 << 5){
                    for (a = i + 1, b = j - 1; board[a][b] != current; a++, b--){
                        board[a][b] = current;
                    }
                }
                if (move & 1 << 6){
                    for (a = i - 1, b = j - 1; board[a][b] != current; a--, b--){
                        board[a][b] = current;
                    }
                }
                if (move & 1 << 7){
                    for (a = i - 1, b = j + 1; board[a][b] != current; a--, b++){
                        board[a][b] = current;
                    }
                }
                for (i = 1; i <= 8; i++){
                    for (j = 1; j <= 8; j++){
                        switch(board[i][j]){
                            case 1:
                                bcount++;
                                break;
                            case 2:
                                wcount++;
                                break;
                        }
                    }
                }
                printf("Black - %2d White - %2d\n", bcount, wcount);
                current = (current == 1) ? 2 : 1;
                getchar();
            }
        }
        for (i = 1; i <= 8; i++){
            for (j = 1; j <= 8; j++){
                putchar(!board[i][j] ? '-' : (board[i][j] == 1 ? 'B' : 'W'));
            }
            putchar('\n');
        }
        getchar();
    }
    return 0;
}