#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    char s[70];
    while(scanf("%s", s), strcmp(s, "#")){
        if(next_permutation(s, s + strlen(s))){
            printf("%s\n", s);
        } else {
            printf("No Successor\n");
        }
    }
    return 0;
}