//So BDN 2
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<long long> q;
        q.push(1);
        while(q.front() % n != 0){
            long long tmp = q.front();
            q.pop();
            q.push(tmp * 10);
            q.push(tmp * 10 + 1);
        }
        cout << q.front() << endl;
    }
    return 0;
}