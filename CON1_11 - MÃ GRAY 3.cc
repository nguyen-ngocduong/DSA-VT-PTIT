#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << s[0];
        for(int i = 1; i<s.size(); i++){
            if(s[i] == s[i-1]) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }
    return 0;
}