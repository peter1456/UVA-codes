#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int main(){
    stack<int> carrier;
    vector< queue<int> > stations;
    int set, N, S, Q, i, Qi, lcount, tmp, t, pos;
    scanf("%d", &set);
    while(set--){
        lcount = 0;
        scanf("%d %d %d", &N, &S, &Q);
        for (i = 0; i < N; i++){
            scanf("%d", &Qi);
            lcount += Qi;
            stations.push_back(queue<int>());
            while(Qi--){
                scanf("%d", &tmp); 
                stations[i].push(tmp);
            }
        }
        for (pos = t = 0; lcount; pos = (pos + 1) % N){
            while(carrier.size() && (stations[pos].size() < Q || carrier.top() == pos + 1)){
                if (carrier.top() == pos + 1){
                    carrier.pop();
                    lcount--;
                } else {
                    stations[pos].push(carrier.top());
                    carrier.pop();
                }
                t++;
            }
            while(carrier.size() < S && stations[pos].size()){
                carrier.push(stations[pos].front());
                stations[pos].pop();
                t++;
            }
            t += lcount ? 2 : 0;
        }
        printf("%d\n", t);
    }
    return 0;
}