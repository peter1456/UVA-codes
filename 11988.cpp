#include<list>
#include<cstdio>
using namespace std;

int main(){
    list<char> s;
    char c;
    list<char>::iterator it = ++s.begin();
    while((c = getchar()) != EOF){
        switch(c){
            case '[':
                it = s.begin();
                break;
            case ']':
                it = s.end();
                break;
            case '\n':
                for(it = s.begin(); it != s.end(); ++it){
                    putchar(*it);
                }
                putchar('\n');
                s.clear();
                it = s.begin();
                break;
            default:
                s.insert(it, c);
        }
    }
    if(!s.empty()){
         for(it = s.begin(); it != s.end(); ++it){
                putchar(*it);
            }
            putchar('\n');
    }
    return 0;
}