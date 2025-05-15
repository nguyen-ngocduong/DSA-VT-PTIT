#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        deque<string> res;
        q.push("6");
        q.push("8");
        while(q.front().size() <= n){
            string tmp = q.front();
            q.pop();
            res.push_back(tmp);
            q.push(tmp + "6");
            q.push(tmp + "8");
        }
        cout << res.size() << endl;
        while(res.size()){
            cout << res.back() << " ";
            res.pop_back();
        }
        cout << endl;
    }
    return 0;
}