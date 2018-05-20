#include<stdio.h>
#include<string.h>

int main(){
    int stack[26], count, s_count, i, j;
    char input[1002];
    scanf("%s", input);
    count = 0;
    while(s_count = 0, strcmp(input, "end")){
        for (i = 0; i < 26; i++){
            stack[i] = 999;
        }
        stack[s_count++] = input[0]; 
        for(i = 1; i < strlen(input); i++){
            for(j = 0; input[i] > stack[j]; j++){
                ;
            }
            stack[j] = input[i];
            s_count = (s_count > j + 1 ? s_count : j + 1);
        }
        printf("Case %d: %d\n", ++count, s_count);
        scanf("%s", input);
    }
    return 0;
}