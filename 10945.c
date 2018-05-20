#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[1010], buffer[1010];
int s_top;

int isPalindrome(){
    int i;
    s_top = -1;
    if (strlen(buffer) == 1)
        return 1;
    for (i = 0; i < strlen(buffer) / 2; i++){
		s[++s_top] = buffer[i];
	}
    if (strlen(buffer) % 2){
		for (i = strlen(buffer) / 2 + 1; i < strlen(buffer); i++){
			if (s[s_top--] != buffer[i]){
				return 0;
			}
		}
	} else {
		for (i = strlen(buffer) / 2; i < strlen(buffer); i++){
			if (s[s_top--] != buffer[i]){
				return 0;
			}
		}
	}
	return 1;
}

void process(char* input){
    memset(buffer, 0, sizeof(buffer));
    int i, j;
    for (i = j = 0; i < strlen(input); i++){
        if (isalpha(input[i])){
            buffer[j++] = toupper(input[i]);
        }
    }
}

int main(){
    char str[1010];
    fgets(str, 1000, stdin);
    process(str);
    while (strcmp(buffer,"DONE")){
        printf("%s\n", isPalindrome() ? "You won't be eaten!" : "Uh oh..");
        fgets(str, 1000, stdin);
        process(str);
    }
    return 0;
}