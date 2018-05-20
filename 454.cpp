#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char s[100][200], p[100][200];
    int i, j, k, N;
    scanf("%d\n", &N);
    while(N--){
        i = j = k = 0;
        memset(s, 0, sizeof(s));
        memset(p, 0, sizeof(p));
        while (fgets(s[i], 200, stdin) != NULL && s[i][0] != '\n' ){
            for (k = j = 0; s[i][j] != '\n'; j++){
                if(s[i][j] != ' '){
                    p[i][k++] = s[i][j];
                }
            }
            s[i][j] = p[i][k] = '\0';
            sort(p[i], p[i] + strlen(p[i]));
            i++;
        }
        for (j = 0; j < i - 1; j++){
            for (k = j + 1; k < i; k++){
                if (!strcmp(p[j], p[k])){
                    printf("%s = %s\n", s[j], s[k]);
                }
            } 
        }
        putchar('\n');
    }
    return 0;
}