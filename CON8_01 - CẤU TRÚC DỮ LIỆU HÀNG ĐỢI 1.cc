#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue<int> q;
        int k;
        while(n--){
            cin >> k;
            if(k == 1) cout << q.size() << endl;
            else if(k == 2){
                if(q.size()) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
            else if(k == 3){
                int x; cin >> x;
                q.push(x);
            }
            else if(k == 4){
                if(q.size()) q.pop();
            }
            else if(k == 5){
                if(q.size()) cout << q.front() << endl;
                else cout << -1 << endl;
            }
            else if(k == 6){
                if(q.size()) cout << q.back() << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}