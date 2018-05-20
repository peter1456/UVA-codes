#include<stdio.h>
#include<memory.h>

int NotZero(int grid[3][3]){
    int i, j, sum;
    for(sum = 0, i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            sum += grid[i][j];
        }
    }
    return sum;
}

int main(){
    int grid[3][3], T, i, j, Index, tmp, tmpgrid[3][3];
    scanf("%d", &T);
    while(T--){
        for (i = 0; i < 3; i++){
            scanf("%d", &tmp);
            grid[i][0] = tmp / 100;
            grid[i][1] = (tmp / 10) % 10;
            grid[i][2] = tmp % 10;
        }
        Index = -1;
        while(NotZero(grid)){
            Index++;
            for (i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    tmpgrid[i][j] = ((i - 1 >= 0 ? grid[i - 1][j] : 0) + (i + 1 < 3 ? grid[i + 1][j] : 0) + (j + 1 < 3 ? grid[i][j + 1] : 0) + (j - 1 >= 0 ? grid[i][j - 1] : 0)) % 2;
                }
            }
            memcpy(grid, tmpgrid, sizeof(grid));
        }
        printf("%d\n", Index);
    }
    return 0;
}