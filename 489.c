#include<stdio.h>
#include<string.h>

int main(){
    int word[26], toggle[26], count, i, sum, togglesum, attempt;
    char buffer[500];
    while(scanf("%d", &count), count != -1){
        attempt = togglesum = sum = 0;
        memset(word, 0, sizeof(word));
        memset(toggle, 0, sizeof(toggle));
        memset(buffer, 0, sizeof(buffer));
        scanf("%s", buffer);
        for (i = 0; i < strlen(buffer); i++){
            word[buffer[i] - 'a'] = 1;
        }
        for (i = 0; i < 26; i++){
            sum += word[i];
        }
        scanf("%s", buffer);

        for (i = 0; i < strlen(buffer) && !(togglesum == sum) && !(attempt == 7); i++){
            if (word[buffer[i] - 'a']){
                if (!toggle[buffer[i] - 'a']){
                    toggle[buffer[i] - 'a'] = 1;
                    togglesum++;
                }
            } else {
                attempt++;
            }
        }
        printf("Round %d\n", count);
        if (attempt == 7){
            printf("You lose.\n");
        } else if (togglesum == sum){
            printf("You win.\n");
        } else {
            printf("You chickened out.\n");
        }
    }    
    return 0;
}