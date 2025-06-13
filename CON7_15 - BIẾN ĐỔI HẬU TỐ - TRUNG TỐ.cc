#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<string> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                string tmp1 = st.top();
                st.pop();
                string tmp2 = st.top();
                st.pop();
                string res = "(" + tmp2 + s[i] + tmp1 + ")";
                st.push(res);
            }
            else st.push(string(1,s[i]));
        }
        cout << st.top() << endl;
    }
    return 0;
}