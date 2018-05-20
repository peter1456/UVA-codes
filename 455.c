#include <stdio.h>
#include <string.h>

// Problem: Handling margin cases and outputs

int isPeriod (int period, char* string){
	int i, j;
	if ((strlen(string) - 1) % period != 0){
		return 0;
	}
	for (i = 1;i < (strlen(string) - 1) / period; i++){
		if (strncmp(string,string+i*period,period)){
			return 0;
		}
	}
	return 1;
}

int main (){
	int cases, i, j;
	char buffer[80];
	scanf("%d\n",&cases);
	for (i=0;i<cases;i++){
		fgets(buffer,80,stdin);
		getchar();
		if (strlen(buffer) != 1){
			for (j = 1; !isPeriod(j,buffer); j++){
				;
			}
		} else {
			j = 0;
		}
		printf("%d\n\n",j);
	}
	return 0;
}
