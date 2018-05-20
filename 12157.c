#include<stdio.h>
#include<math.h>

int main(){
    int T, i, N, j, jsum, msum;
    double d;
    scanf("%d", &T);
    for (i = 1; i <= T; i++){
        jsum = msum = 0;
        scanf("%d", &N);
        for (j = 0; j < N; j++){
            scanf("%lf", &d);
            msum += (int)ceil((d + 1) / 30) * 10;
            jsum += (int)ceil((d + 1) / 60) * 15;
        }
        if (jsum < msum){
            printf("Case %d: Juice %d\n", i, jsum);
        } else if (msum < jsum){
            printf("Case %d: Mile %d\n", i, msum);
        } else {
            printf("Case %d: Mile Juice %d\n", i, jsum);
        }
    }
    return 0;
}