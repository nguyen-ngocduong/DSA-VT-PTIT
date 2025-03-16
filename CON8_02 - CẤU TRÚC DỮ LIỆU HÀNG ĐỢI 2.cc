#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    queue<int> q;
    while(t--){
        string s; cin >> s;
        int x;
        if(s == "PUSH"){
            cin >> x;
            q.push(x);
        }
        if(s == "PRINTFRONT"){
            if(q.empty()) cout << "NONE" << endl;
            else cout << q.front() << endl;
        }
        if(s == "POP" && !q.empty()) q.pop();
    }
    return 0;
}