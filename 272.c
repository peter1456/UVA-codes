#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char buffer[1000], output[1000];
	int open = 1;
	int i, j = 0;
	while(fgets(buffer,1000,stdin)){
		j = 0;
		for (i = 0;i<=strlen(buffer);i++){
			if (buffer[i]=='"'){
				if (open){
					output[j++] = '`';
					output[j++] = '`';
					open = 0;
				} else {
					output[j++] = '\'';
					output[j++] = '\'';
					open = 1;
				}
			} else {
				output[j++] = buffer[i];
			}
		}
		printf("%s",output);
	}
		return 0;
}
