#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        for(int i = 1; i<s.size(); i++){
            s[i] = (s[i] - '0')^(s[i-1] - '0') + '0';
        }
        cout << s << endl;
    }
    return 0;
}