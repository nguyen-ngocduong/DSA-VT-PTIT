#include<bits/stdc++.h>
#define MODE 1000000007
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(int i = 0; i< n; i++) {
            int x; cin >> x;
            q.push(x);
        }
        long long res = 0;
        while(q.size() > 1){
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            res = (res + x + y) % MODE;
            q.push(x+y);
        }
        cout << res << endl;
    }
    return 0;
}