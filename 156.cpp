#include<string>
#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

typedef struct word {
    int place;
    string str;
} w;

bool cmpstr(w a, w b){
    return lexicographical_compare(a.str.begin(), a.str.end(), b.str.begin(), b.str.end());
}

bool cmpout(string a, string b){
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

int main(){
    string ori[1000], tmp, out[1000];
    w pro[1000], buf;
    int i = 0, finddup = 1, k = 0;
    while (cin >> tmp, tmp.compare("#")) {
        ori[i].assign(tmp);
        pro[i].str.assign(tmp);
        for (string::iterator it = pro[i].str.begin(); it != pro[i].str.end(); it++){
            *it = tolower(*it);
        }
        sort(pro[i].str.begin(), pro[i].str.end());
        pro[i].place = i;
        i++;
    }
    sort(pro, pro + i, cmpstr); 
    for (int j = 0; j < i; j++){
        if (!j){
            buf.str.assign(pro[j].str);
            buf.place = pro[j].place;
        } else {
            if (buf.str.compare(pro[j].str)){
                if (finddup) {
                    out[k].assign(ori[buf.place]);
                    k++;
                } else {
                    finddup = 1;
                }
                buf.str.assign(pro[j].str);
                buf.place = pro[j].place;
            } else {
                finddup = 0;
            }
        }
    }
    if (finddup){
        out[k++].assign(ori[buf.place]);
    }
    sort(out, out + k, cmpout);
    for (int i = 0; i < k; i++){
        cout << out[i] << '\n';
    }
    return 0;   
}