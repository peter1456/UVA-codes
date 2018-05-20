#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct ctant {
    int qsolved;
    int ptime;
    int time[10], solved[10];
    int count;
    int teamno;
} P;

bool cmp_ptime(P a, P b){
    return a.ptime < b.ptime;
}

bool cmp_qsolved(P a, P b){
    return a.qsolved > b.qsolved;
}

int main(){
    P arr[101];
    int T, c, p, t, i, j;
    char line[100], L;
    scanf("%d", &T);
    getchar();
    getchar();
    j = 0;
    while(T--){
        memset (arr, 0, sizeof(arr));
        while(fgets(line, 99, stdin) != NULL && strcmp(line, "\n")){
            sscanf(line, "%d %d %d %c", &c, &p, &t, &L);
            arr[c].teamno = c;
            arr[c].count++;
            switch (L){
                case 'C':
                    if (!arr[c].solved[p]){
                        arr[c].ptime += t + arr[c].time[p];
                        arr[c].qsolved++;
                        arr[c].solved[p] = 1;
                    }
                    break;
                case 'I':
                    arr[c].time[p] += 20;
                    break; 
            }
        }
        stable_sort(arr, arr + 101, cmp_ptime);
        stable_sort(arr, arr + 101, cmp_qsolved);
        if(j) putchar('\n');
        for(i = 0; i < 101; i++){
            if(arr[i].count){
                printf("%d %d %d\n", arr[i].teamno, arr[i].qsolved, arr[i].ptime);
            }
        }
        j = 1;
    }
    return 0;
}