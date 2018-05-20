#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;

bool cmp(char a, char b){
    if (tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}

int main(){
    int N;
    char tmp[1000];
    scanf("%d", &N);
    while(N--){
        scanf("%s", tmp);
        sort(tmp, tmp + strlen(tmp), cmp);
        printf("%s\n", tmp);
        while(next_permutation(tmp, tmp + strlen(tmp), cmp)){
            printf("%s\n", tmp);
        }
    }
    return 0;
}