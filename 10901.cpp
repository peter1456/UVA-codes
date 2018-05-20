#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> ii;

int main(){
    int c, n, t, m, c_time, tmp_time, place, count, i, print[10005], empty;
    char dir[8];
    vector<queue <ii> > bank;
    scanf("%d", &c);
    empty = 0;
    while(c--){
        memset(print, 0, sizeof(print));
        bank.clear();
        bank.push_back(queue<ii>());
        bank.push_back(queue<ii>());
        scanf("%d %d %d", &n, &t, &m);
        for(i = 0; i < m; i++){
            scanf("%d %s", &tmp_time, dir);
            bank[strcmp("left", dir) ? 1 : 0].push(make_pair(tmp_time, i));
        }
        place = c_time = 0;
        while(!bank[0].empty() || !bank[1].empty()){
            count = 0;
            // If there is car in the ferry
            while(!bank[place].empty() && bank[place].front().first <= c_time && count < n){
                print[bank[place].front().second] = c_time + t;
                bank[place].pop();
                count++;
            }
            if(count){
                c_time += t;
                place ^= 1;
            // Logic: Check needs to change the place or not
            } else {
                if (bank[place].empty() || (!bank[place ^ 1].empty() && bank[place].front().first >= bank[place ^ 1].front().first)){
                    place ^= 1;
                    c_time = (bank[place].front().first <= c_time) ? c_time + t : bank[place].front().first + t;
                } else {
                    c_time = bank[place].front().first;
                }
            }
        }
        if (empty){
            putchar('\n');
        } else {
            empty = 1;
        }
        // print all the things
        for(i = 0; i < m; i++){
            printf("%d\n", print[i]);
        }
    }
    return 0;
}