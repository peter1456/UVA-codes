#include<bitset>
#include<cstdio>
using namespace std;

int main(){
    bitset<1000001> bset;
    int n, m, i, b, e, conflict, j, r;
    while(scanf("%d %d", &n, &m), n || m){
        conflict = 0;
        bset.reset();
        while(n--){
            scanf("%d %d", &b, &e);
            for(i = b + 1; !conflict && i <= e; i++){
                if(bset.test(i)){
                    conflict = 1;
                } else {
                    bset.set(i);
                }
            }
        }
        while(m--){
            scanf("%d %d %d", &b, &e, &r);
            for(i = 0; !conflict && i < 1000000 / r; i++){
                for(j = b + 1; !conflict && j <= e && i * r + j <= 1000000; j++){
                    if(bset.test(i * r + j)){
                        conflict = 1;
                    } else {
                        bset.set(i * r + j);
                    }
                }
            }
        }
        printf("%s\n", conflict ? "CONFLICT" : "NO CONFLICT");
    }
    return 0;
}