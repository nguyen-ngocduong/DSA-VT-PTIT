#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int option;
        queue<int> q;
        while(n--){
            cin >> option;
            switch (option)
            {
            case 1:
                cout << q.size() << endl;
                break;
            case 2:
                if(q.empty()) cout << "YES" << endl;
                else cout << "NO" << endl;
                break;
            case 3: {
                int x; cin >> x;
                q.push(x);
                break;
            }
            case 4:
                if(!q.empty()) q.pop();
                break;
            case 5:
                if(q.empty()) cout << -1 << endl;
                else cout << q.front() << endl;
                break;
            case 6:
            if(q.empty()) cout << -1 << endl;
            else cout << q.back() << endl;
            break;
            default:
                break;
            }
        }
    }
    return 0;
}