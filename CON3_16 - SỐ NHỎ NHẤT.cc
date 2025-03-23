#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
        int s,d;
        cin >> s >>d;
        vector<int> v(d);
        if(s > d*9) cout << -1 << endl;
        else if (s == 0) {
            if (d == 0){
                cout << 0 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            s--;
            for(int i = v.size() - 1; i>0; i--) {
                if(s > 9){
                    v[i] = 9;
                    s -= 9;
                }
                else { 
                    v[i] = s;
                    s = 0;
                }
            }
            v[0] = s + 1;
            for(int i = 0; i<v.size(); i++) {
                cout << v[i];
            }
            cout << endl;
        }
    }
    return 0;
}