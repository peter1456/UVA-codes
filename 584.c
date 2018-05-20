#include<stdio.h>
#include<stdlib.h>

int main(){
    int score, roll, frame, multiplier[25], i, buf, max, init;
    char buffer[6];
    while (scanf("%s", buffer), buffer[0] != 'G'){
        roll = score = 0;
        init = frame = 1;
        for (i = 0; i < 25; i++){
            multiplier[i] = 1;
        }
        while (frame < 10){
            for(i = 0; i < 2; roll++, i++){
                if (init){
                    init = 0;
                } else {
                    scanf("%s", buffer);
                }
                switch(buffer[0]){
                    case 'X':
                        score += 10 * multiplier[roll];
                        multiplier[roll + 1]++;
                        multiplier[roll + 2]++;
                        i++;
                        break;
                    case '/':
                        score += (10 - buf) * multiplier[roll];
                        multiplier[roll + 1]++;
                        break;
                    default:
                        score += (buf = atoi(buffer)) * multiplier[roll];
                }
            }
            frame++;
            buf = 0;
        }
        max = 2;
        for (i = 0; i < max; roll++, i++){
            scanf("%s", buffer);
            switch(buffer[0]){
                case 'X':
                    score += 10 * multiplier[roll];
                    max = 3;
                    break;
                case '/':
                    score += (10 - buf) * multiplier[roll];
                    max = 3;
                    break;
                default:
                    score += (buf = atoi(buffer)) * multiplier[roll];
            }
        }
        printf("%d\n", score);
    }
    return 0;
}