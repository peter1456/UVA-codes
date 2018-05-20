#include<stdio.h>
#include<string.h>
#include<float.h>

int main(){
    int n, p, r, i, ccount = 0;
    char tmp[90], name[90];
    double low = DBL_MAX, d, hcomp = 0, tcomp;
    scanf("%d %d", &n, &p);
    if (n+p){
        for (i = 0; i < n; i++){
            fgets(tmp, 90, stdin);
        }
        while (p--){
            scanf("%s", tmp);
            scanf("%lf %d", &d, &r);
            tcomp = (double) r / (double) n;
            if (tcomp > hcomp){
                low = d;
                hcomp = tcomp;
                strcpy(name, tmp);
            } else if (tcomp == hcomp){
                if (d < low){
                    strcpy(name, tmp);
                }
            }
            while (r--){
                fgets(tmp, 90, stdin);
            }
        }
        printf("RFP #%d\n%s\n", ++ccount, name);
    while(scanf("%d %d", &n, &p), n+p){
        putchar('\n');
        for (i = 0; i < n; i++){
            fgets(tmp, 90, stdin);
        }
        while (p--){
            scanf("%s", tmp);
            scanf("%lf %d", &d, &r);
            tcomp = (double) r / (double) n;
            if (tcomp > hcomp){
                low = d;
                hcomp = tcomp;
                strcpy(name, tmp);
            } else if (tcomp == hcomp){
                if (d < low){
                    strcpy(name, tmp);
                }
            }
            while (r--){
                fgets(tmp, 90, stdin);
            }
        }
        printf("RFP #%d\n%s\n", ++ccount, name);
    }
    }
}