#include<iostream>
#include<string>
#include<map>
#include<iomanip>
#include<cstdio>
using namespace std;

int main(){
    int c, n;
    map<string, int> data;
    string name;
    cin >> c;
    cin.ignore();
    cin.ignore();
    while(c--){
        n = 0;
        data.clear();
        while(getline(cin, name) && !name.empty()){
            data[name]++;
            n++;
        }
        for(map<string, int>::iterator it = data.begin(); it != data.end(); it++){
            cout << it->first << ' ' << fixed << setprecision(4) << (double)(it->second * 100.0 / n) << endl; 
        }
        if(c){
            cout << endl;
        }
    }
    return 0;
}