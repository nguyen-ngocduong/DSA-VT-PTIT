#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        int cnt = 0;
        while(cnt < n){
            string tmp = q.front();
            q.pop();
            q.push(tmp + "0");
            q.push(tmp + "1");
            cout << tmp << " ";
            cnt++;
        }
        cout << endl;
    }
    return 0;
}