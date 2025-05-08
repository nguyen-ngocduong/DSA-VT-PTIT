#include<bits/stdc++.h>
using namespace std;
void solve(string s){
    stack<int> st;
    int num = 1;
    for(int i = 0; i<=s.size(); i++){
        st.push(num);
        if (i == s.size() || s[i] == 'I') {
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
        }
        num++;
    }
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        solve(s);
    }
    return 0;
}