#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int c, l, m, count, l_count, len, place;
    vector<queue <int> > bank;
    char dir[8];
    scanf("%d", &c);
    bank.push_back(queue<int>());
    bank.push_back(queue<int>()); 
    while(c--){
        scanf("%d %d", &l, &m);
        l *= 100;
        while(m--){
            scanf("%d %s", &len, dir);
            bank[strcmp("left", dir) ? 1 : 0].push(len);
        }
        place = count = 0;
        while(!bank[0].empty() || !bank[1].empty()){
            l_count = 0;
            while(!bank[place].empty() && bank[place].front() + l_count <= l){
                l_count += bank[place].front();
                bank[place].pop();
            }
            place ^= 1;
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}