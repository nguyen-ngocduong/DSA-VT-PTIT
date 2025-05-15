#include<bits/stdc++.h>
using namespace std;
int main (){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<int> q;
        q.push(1);
        int cnt = 0;
        while(q.front() <= n){
            int tmp = q.front();
            q.pop();
            q.push(tmp*10);
            q.push(tmp*10+1);
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}