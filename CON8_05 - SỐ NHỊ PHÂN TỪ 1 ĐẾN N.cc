#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        int cnt = 0;
        while(1){
            string x = q.front();
            q.pop();
            q.push(x+"0");
            q.push(x+"1");
            cout << x << " ";
            cnt++;

            if(cnt == n) break;
        }
        cout << endl;
    }
    return 0;
}