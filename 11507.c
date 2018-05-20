#include <stdio.h>

/*
0 -> +x
1 -> +y
2 -> -x
3 -> -y
*/

int main(){
    int L, xy, z;
    char d[3];
    while(scanf("%d", &L), L > 0){
        xy = 0;
        z = 0;
        while (--L){
            scanf("%s", d);
            switch (d[1]){
                case 'y':
                    if (!z){
                        if (d[0] == '+'){
                            xy = (xy + 1) % 4;
                        } else {
                            xy = (xy + 3) % 4;
                        }
                    }
                    break;
                case 'z':
                    if (!(xy % 2)){
                        if (d[0] == '+'){
                            if (z){
                                xy = z > 0 ? 2 : 0;
                                z = 0; 
                            } else {
                                z = xy ? -1 : 1;
                            }
                        } else {
                            if (z){
                                xy = z > 0 ? 0 : 2;
                                z = 0; 
                            } else {
                                z = xy ? 1 : -1;
                            }
                        }
                    }
                    break;
            }
        }
        if (z){
            if (z > 0){
                printf("+z\n");
            } else {
                printf("-z\n");
            }
        } else {
            switch(xy){
                case 0:
                    printf("+x\n");
                    break;
                case 1:
                    printf("+y\n");
                    break;
                case 2:
                    printf("-x\n");
                    break;
                case 3:
                    printf("-y\n");
                    break;
            }
        }
    }
    return 0;
}