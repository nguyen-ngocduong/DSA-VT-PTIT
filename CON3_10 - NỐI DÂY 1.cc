#include<bits/stdc++.h>
using namespace std;
int main (){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(int i = 0; i< n; i++) {
            int x; cin >> x;
            q.push(x);
        }
        long long ans = 0;
        while(q.size() > 1){
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            ans += x + y;
            q.push(x + y);
        }
        cout << ans << endl;
    }
    return 0;
}