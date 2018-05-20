#include<stdio.h>

int main (){
    char buffer[100];
    while (fgets(buffer, 99, stdin) != NULL){
        printf("%s", buffer);
    }
    return 0;
}