#include<stdio.h>
#include<string.h>

int main(){
    int t;
    char s[200];
    scanf("%d", &t);
    while (t--){
        scanf("%s", s);
        if ( ! strcmp(s, "1") || ! strcmp(s, "4") || ! strcmp(s, "78")){
            printf("+\n");
        } else {
            switch(s[strlen(s) - 1]){
                case '5':
                    if (s[strlen(s) - 2] == '3'){
                        printf("-\n");
                    } else {
                        printf("?\n");
                    }
                    break;
                case '4':
                    if (s[0] == '9'){
                        printf("*\n");
                    } else {
                        printf("?\n");
                    }
                    break;
                default:
                    printf("?\n");
            }
        }
    }
    return 0;
}