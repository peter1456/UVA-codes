#include<stack>
#include<cstdio>
using namespace std;

int main(){
    stack<int> s;
    int N, perm[1000], pos, i, j;
    while(scanf("%d", &N), N){
         while(scanf("%d", &perm[0]), perm[0]){
             for(i = 1; i < N; i++){
                 scanf("%d", &perm[i]);
             }
             for(i = 0, j = 1, pos = 1; i < N && pos; i++){
                while(j <= perm[i]){
                    s.push(j);
                    j++;
                }
                if(s.top() != perm[i]){
                    pos = 0;
                } else {
                    s.pop();
                }
             }
             printf("%s\n", pos ? "Yes" : "No");
             while(!s.empty()){
                 s.pop();
             }
         }
         putchar('\n');
    }
    return 0;
}