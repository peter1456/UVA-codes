#include<stdio.h>
#include<string.h>

char s[100], t[100], st[100], ans[200];

typedef struct st {
    char s[100];
} Stack;

void dfs (int idx, int st_top, int sidx, int aidx, Stack stk){
    int i;
    if (sidx < strlen(s)){
        stk.s[st_top + 1] = s[sidx];
        ans[idx] = 'i';
        dfs(idx + 1, st_top + 1, sidx + 1, aidx + 1, stk);
    }
    if (st_top != -1){
        if(stk.s[st_top] == t[idx - sidx]){
            ans[idx] = 'o';
            if(idx == 2 * strlen(s) - 1){
                printf("%c", ans[0]);
                for(i = 1; i < 2 * strlen(s); i++){
                    printf(" %c", ans[i]);
                }
                putchar('\n');
            } else {
                dfs(idx + 1, st_top - 1, sidx, aidx + 1, stk);
            }
        }
    }
}

int main(){
    Stack stk;
    memset(&stk, 0, sizeof(stk));
    while(scanf("%s", s) != EOF){
        scanf("%s", t);
        printf("[\n");
        if(strlen(s) == strlen(t)){
            dfs(0, -1, 0, 0, stk);
        }
        printf("]\n");
    }
    return 0;
}