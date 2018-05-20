#include <stdio.h>
#include <string.h>

char s[25], mir[91];
int s_top;

int isMirPalindrome (char* input){	
	int mirror, palindrome, i;
	char tmp;
	mirror = palindrome = 1;
	if (strlen(input) == 1){
		if (mir[input[0]] == input[0]){
			return 3;
		} else {
			return 2;
		}
	}
	for (i = 0; i < strlen(input) / 2; i++){
		s[++s_top] = input[i] == '0' ? 'O' : input[i];
		if (!mir[s[s_top]]){
			mirror = 0;
		}
	}
	if (strlen(input) % 2){
		if (input[strlen(input) / 2] != '0'){
			if (mir[input[strlen(input) / 2]] != input[strlen(input) / 2]){
				mirror = 0;
			}
		}
		for (i = strlen(input) / 2 + 1; i < strlen(input); i++){
			tmp = input[i] == '0' ? 'O' : input[i];
			if (s[s_top] != tmp){
				palindrome = 0;
			}
			if (mir[tmp] != s[s_top--]){
				mirror = 0;
			}
			if (!palindrome && !mirror){
				return 0;
			}
		}
	} else {
		for (i = strlen(input) / 2; i < strlen(input); i++){
			tmp = input[i] == '0' ? 'O' : input[i];
			if (s[s_top] != tmp){
				palindrome = 0;
			}
			if (mir[tmp] != s[s_top--]){
				mirror = 0;
			}
			if (!palindrome && !mirror){
				return 0;
			}
		}
	}
	return palindrome * 2 + mirror;
}

void initialize(){
	memset(mir, 0, sizeof(mir));
	mir['A'] = 'A';
	mir['E'] = '3';
	mir['H'] = 'H';
	mir['I'] = 'I';
	mir['L'] = 'J';
	mir['J'] = 'L';
	mir['M'] = 'M';
	mir['O'] = 'O';
	mir['S'] = '2';
	mir['T'] = 'T';
	mir['U'] = 'U';
	mir['V'] = 'V';
	mir['W'] = 'W';
	mir['X'] = 'X';
	mir['Y'] = 'Y';
	mir['Z'] = '5';
	mir['1'] = '1';
	mir['2'] = 'S';
	mir['3'] = 'E';
	mir['5'] = 'Z';
	mir['8'] = '8';
}

int main (){
	int count = 0;
	char buffer[25];
	initialize();
	while (scanf("%s",buffer) != EOF){
		s_top = -1;
		if(count){
			putchar('\n');
		}
		switch (isMirPalindrome(buffer)){
			case 0:
				printf("%s -- is not a palindrome.\n", buffer);
				break;
			case 1:
				printf("%s -- is a mirrored string.\n", buffer);
				break;
			case 2:
				printf("%s -- is a regular palindrome.\n", buffer);
				break;
			case 3:
				printf("%s -- is a mirrored palindrome.\n", buffer);
				break;
		}
		count++;
	}
	putchar('\n');
	return 0;
}
