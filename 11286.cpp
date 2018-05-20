#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, max, tmp, count;
    vector<int> tmpvec;
    map<vector<int>, int> mp;
    while(scanf("%d", &n), n){
        mp.clear();
        while(n--){
            tmpvec.clear();
            for(int i = 0; i < 5; i++){
                scanf("%d", &tmp);
                tmpvec.push_back(tmp);
            }
            sort(tmpvec.begin(), tmpvec.end());
            mp[tmpvec]++;
        }
        max = count = 0;
        for (map<vector<int>, int>::iterator it = mp.begin(); it != mp.end(); it++){
            if(it->second > max){
                max = it->second;
                count = 1;
            } else if (it->second == max) {
                count++;
            }
        }
        printf("%d\n", count * max);
    }
    return 0;
}