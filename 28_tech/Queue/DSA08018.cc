#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        deque<string> res;
        q.push("6");
        q.push("8");
        while(q.front().size() <= n){
            string tmp = q.front();
            res.push_back(tmp);
            q.pop();
            q.push(tmp + "6");
            q.push(tmp + "8");
        }
        cout << res.size() << endl;
        while(!res.empty()){
            cout << res.front() << " ";
            res.pop_front();
        }
        cout << endl;
    }
    return 0;
}