#include<stdio.h>
#include<memory.h>

int main(){
    int n, m, c, dev[21], toggle[21], count, ccount = 0, i, max;
    while (scanf("%d %d %d", &n, &m, &c), n+m+c){
        memset(toggle, 0, sizeof(toggle));
        max = count = 0;
        for (i = 1; i <= n; i++){
            scanf("%d", dev+i);
        }
        while (m--){
            scanf("%d", &n);
            count += dev[n] * ((toggle[n] = !toggle[n]) ? 1 : -1);
            max = count > max ? count : max;
        }
        printf("Sequence %d\n", ++ccount);
        if (max > c){
            printf("Fuse was blown.\n");
        } else {
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", max);
        }
        putchar('\n');
    }
    return 0;
}