#define DEBUG
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 130

static char stack[SIZE];
static int topelement;

void pop () {
	stack[topelement--] = 0;
}

void push (char input) {
	stack[++topelement] = input;
} 

bool isEmpty () {
	return topelement == -1;
}

char Top (){
	return stack[topelement];
}

void Reset (){
	memset(stack,0,sizeof(stack));
	topelement = -1;
}

int isCorrect (){
	char buffer;
	#ifdef DEBUG
	printf("%d\n",topelement);
	#endif
	while ((buffer = getchar()) != '\n'){
		#ifdef DEBUG
		printf("loop entered\n");
		#endif
		if (buffer == '[' || buffer == '('){
			push(buffer);
			#ifdef DEBUG 
			printf("pushed\n");
			#endif 
		} else {
			if (isEmpty()){
				return 2;
			} else if ((buffer == ']' && Top() == '[' ) || (buffer == ')' && Top() == '(')){
				pop();
				#ifdef DEBUG
				printf("popped\n");
				#endif
			} else {
				return 2;
			}
		}
	}
	if (isEmpty()){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	#ifdef UDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int cases, i;
	char buffer;
	cases = 0;
	scanf("%d", &cases);
	topelement = -1;
	getchar();
	for (i = 0; i < cases; i++){
		#ifdef DEBUG
		printf("%d\n",i);
		#endif
		if (isCorrect() == 1){
			printf("Yes\n");
		} else {
			printf("No\n");
			if (isCorrect() == 2){
				while (getchar() != '\n'){
					;
				}
			}
		}
		Reset(); 
	}
	return 0;
}

