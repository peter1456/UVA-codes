#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char s[10010], buffer[10010], vert[10010];
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

int isSquare(){
    int k = strlen(buffer), i, j;
    if (k == 1)
        return 1;
    if ((int)sqrt(k) * (int)sqrt(k) != k)
        return 0;
    if (!isPalindrome())
        return 0;
    strcpy(vert, buffer);
    for (i = 0; i < (int)sqrt(k); i++){
        for (j = 0; j < (int)sqrt(k); j++){
            *(buffer + (int)sqrt(k) * i + j) = *(vert + (int)sqrt(k) * j + i);
        }
    }
    if (isPalindrome())
        return (int)sqrt(k);
    return 0;
}

void process(char* input){
    memset(buffer, 0, sizeof(buffer));
    memset(vert, 0, sizeof(vert));
    int i, j;
    for (i = j = 0; i < strlen(input); i++){
        if (isalpha(input[i])){
            buffer[j++] = tolower(input[i]);
        }
    }
}

int main(){
    int T, i, tmp;
    char str[10010];
    scanf("%d", &T);
    getchar();
    for (i = 1; i <= T; i++){
        fgets(str, 10005, stdin);
        process(str);
        printf("Case #%d:\n", i);
        if (tmp = isSquare()){
            printf("%d\n", tmp);
        } else {
            printf("No magic :(\n");
        }
    }
    return 0;
}