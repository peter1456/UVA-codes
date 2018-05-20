#include<stdio.h>
#include<string.h>

int isGreen(int now, int cycle){
    int k = (now - (cycle - 5)) % (2 * cycle);
    return k >= 5 + cycle;
}

int main(){
    int cycle[100], count, i = 0, tmp, sum, allGreen, j, k;
    char line[110], *p;
    p = line;
    while(fgets(line, 102, stdin), strcmp(line, "0 0 0")){
        while(sscanf(p, "%d%n", &tmp, &count)){
            if (!tmp){
                for (j = 2 * cycle[0]; j <= 5 * 60 * 60 || !allGreen; i++){
                    for (sum = k = 0; k < i; k++){
                        sum += isGreen(j, cycle[k]);
                    }
                    allGreen = (sum == i);
                }
                if(allGreen){
                    printf("%d:%d:%d\n", j / 3600, (j / 60) % 60, j % 60);
                } else {
                    printf("Signals fail to synchronise in 5 hours\n");
                }
                i = 0;
            } else {
                p += count;
                cycle[i++] = tmp;
            }
        }
    }
    return 0;
}