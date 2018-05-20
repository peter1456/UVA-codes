#include <stdio.h>
#include <memory.h>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int months, m, i, no;
    double dpayment, value, owe, depre[100], decre, dep;
    scanf("%d %lf %lf %d", &months, &dpayment, &value, &no);
    while (months >= 0){
        memset(depre, 0, sizeof(depre));
        owe = value - dpayment;
        decre = owe / months;
        while(no--){
            scanf("%d", &m);
            scanf("%lf", &depre[m]);
        }
        dep = depre[0];
        value *= 1 - dep;
        for (i = 1; owe >= value; i++){
            if (depre[i]){
                dep = depre[i];
            }
            owe -= decre;
            value *= 1 - dep;
        }
        printf("%d %s\n", i > 1 ? i -1 : i, i - 1 > 1 ? "months" : "month");
        scanf("%d %lf %lf %d", &months, &dpayment, &value, &no);
    }
    return 0;
}