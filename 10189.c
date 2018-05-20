#include<stdio.h>
#include<memory.h>

int main(){
    int field[100][100], i, j, count = 0, n, m;
    char line[110];
    scanf("%d %d", &n, &m);
    if (n + m){
        memset(field, 0, sizeof(field));
        for (i = 0; i < n; i++){
            scanf("%s", line);
            for (j = 0; j < m; j++){
                if (line[j] == '*'){
                    field[i][j] = -10;
                    if (i - 1 >= 0){
                        field[i - 1][j]++;
                        if (j - 1 >= 0){
                            field[i - 1][j - 1]++;
                        }
                        if(j + 1 < m){
                            field[i - 1][j + 1]++;
                        }
                    }
                    if (j - 1 >= 0){
                        field[i][j - 1]++;
                        if (i + 1 < n){
                            field[i + 1][j - 1]++;
                        }
                    }
                    if (i + 1 < n){
                        field[i + 1][j]++;
                        if (j + 1 < m){
                            field[i + 1][j + 1]++;
                        }
                    }
                    if (j + 1 < m){
                        field[i][j + 1]++;
                    }
                }
            }
        }
        printf("Field #%d:\n", ++count);
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                putchar(field[i][j] < 0 ? '*' : field[i][j] + '0');
            }
            putchar('\n');
        }
    }
         while(scanf("%d %d", &n, &m), n + m){
        putchar('\n');
        memset(field, 0, sizeof(field));
        for (i = 0; i < n; i++){
            scanf("%s", line);
            for (j = 0; j < m; j++){
                if (line[j] == '*'){
                    field[i][j] = -10;
                    if (i - 1 >= 0){
                        field[i - 1][j]++;
                        if (j - 1 >= 0){
                            field[i - 1][j - 1]++;
                        }
                        if(j + 1 < m){
                            field[i - 1][j + 1]++;
                        }
                    }
                    if (j - 1 >= 0){
                        field[i][j - 1]++;
                        if (i + 1 < n){
                            field[i + 1][j - 1]++;
                        }
                    }
                    if (i + 1 < n){
                        field[i + 1][j]++;
                        if (j + 1 < m){
                            field[i + 1][j + 1]++;
                        }
                    }
                    if (j + 1 < m){
                        field[i][j + 1]++;
                    }
                }
            }
        }
        printf("Field #%d:\n", ++count);
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                putchar(field[i][j] < 0 ? '*' : field[i][j] + '0');
            }
            putchar('\n');
        }
    }
    return 0;
}