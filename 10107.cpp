#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int arr[10001], i, tmp;
    i = 1;
    while(scanf("%d", &arr[i - 1]) != EOF){
        if(i % 2){
            nth_element(arr, arr + i / 2, arr + i);
            printf("%d\n", arr[i / 2]);
        } else {
            nth_element(arr, arr + i / 2, arr + i);
            tmp = *(arr + i / 2);
            nth_element(arr, arr + i / 2 - 1, arr + i);
            printf("%d\n", (tmp + arr[i / 2 - 1]) / 2);
        }
        i++;
    }
    return 0;
}