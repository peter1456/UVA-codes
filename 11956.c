#include<stdio.h>
#include<string.h>

int main(){
    int T, i, memory[100], at, j;
    char s[100010];
    scanf("%d", &T);
    for (i = 1; i <= T; i++){
        memset(memory, 0, sizeof(memory));
        at = 0;
        scanf("%s", s);
        for (j = 0; j < strlen(s); j++){
            switch (s[j]){
                case '>':
                    at = (at + 1) % 100;
                    break;
                case '<':
                    at = (at + 99) % 100;
                    break;
                case '+':
                    memory[at] = (memory[at] + 1) % 255;
                    break;
                case '-':
                    memory[at] = (memory[at] + 254) % 255;
                    break;
            }
        }
        printf("Case %d: ", i);
        for (j = 0; j < 99; j++){
            printf("%02X ", memory[j]);
        }
        printf("%02X\n", memory[j]);
    }
    return 0;
}