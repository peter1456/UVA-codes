#include<stdio.h>
#include<memory.h>

typedef struct s {
    int count;
    int hasKing;
    int hasQueen;
    int hasJack;
    int stopped;
} suit;

int main(){
    suit Suit[4];
    int i, color, point, j, stopcount, maxcount, maxsuit;
    char cards[50];
    while(fgets(cards, 50, stdin)){
        memset(Suit, 0, sizeof(Suit));
        maxsuit = maxcount = stopcount = point = 0;
        for (i = 0; i < 39; i += 3){
            switch(cards[i+1]){
                case 'S':
                    color = 0;
                    break;
                case 'H':
                    color = 1;
                    break;
                case 'D':
                    color = 2;
                    break;
                default:
                    color = 3;
            }
            switch(cards[i]){
                case 'A':
                    Suit[color].stopped = 1;
                    point += 4;
                    break;
                case 'J':
                    Suit[color].hasJack = 1;
                    point += 1;
                    break;
                case 'Q':
                    Suit[color].hasQueen = 1;
                    point += 2;
                    break;
                case 'K':
                    Suit[color].hasKing = 1;
                    point += 3;
                    break;
            }
            Suit[color].count++;
        }
        for (j = 0; j < 4; j++){
            if (Suit[j].hasKing){
                if (Suit[j].count == 1)
                    point--;
                else 
                    Suit[j].stopped = 1;
            }
            if (Suit[j].hasQueen){
                if (Suit[j].count < 3)
                    point--;
                else 
                    Suit[j].stopped = 1;
            }
            if (Suit[j].hasJack && Suit[j].count < 4)
                point--;
            stopcount += Suit[j].stopped;
            if (Suit[j].count > maxcount){
                maxcount = Suit[j].count;
                maxsuit = j;
            }
        }
        if (point >= 16 && (stopcount == 4)){
            printf("BID NO-TRUMP\n");
        } else {
            for (i = 0; i < 4; i++){
                if (Suit[i].count < 2){
                    point += 2;
                } else if (Suit[i].count == 2){
                    point++;
                }
            }
            if (point < 14)
                printf("PASS\n");
            else {
                printf("BID ");
                switch(maxsuit){
                    case 0:
                        printf("S\n");
                        break;
                    case 1:
                        printf("H\n");
                        break;
                    case 2:
                        printf("D\n");
                        break;
                    default:
                        printf("C\n");
                        break;
                }
            }
        }
    }
    return 0;
}