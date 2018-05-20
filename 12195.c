#include<stdio.h>
#include<string.h>

int main(){
    char s[210];
    int count, measure, i;
    while(fgets(s, 205, stdin), strcmp(s, "*\n")){
        count = measure = 0;
        for (i = 1; i < strlen(s) - 1; i++){
            switch(s[i]){
                case 'W':
                    measure += 64;
                    break;
                case 'H':
                    measure += 32;
                    break;
                case 'Q':
                    measure += 16;
                    break;
                case 'E':
                    measure += 8;
                    break;
                case 'S':
                    measure += 4;
                    break;
                case 'T':
                    measure += 2;
                    break;
                case 'X':
                    measure += 1;
                    break;
                case '/':
                    if (measure == 64)
                        count++;
                    measure = 0;
                break;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}